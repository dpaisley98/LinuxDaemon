
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <syslog.h>

void unlock_directories()
{
    pid_t pid;

    pid = fork();

    if(pid == -1) // Error check for if fork fails
    {
            syslog(LOG_ERR, "ERROR: lock_directories.c : FORK FAILED");
    } else if(pid == 0) // Code executed by child
    {
    char *unlock_script = "/home/fluffyhobo/systems_software/ca1/src/scripts/unlock_directories.sh";
            char *args[] = {"/bin/sh", unlock_script, NULL};
            execvp(args[0], args);
    } else // Parent waiting for status from child
    {
        int status;

        if(wait(&status) == -1)
        {
            syslog(LOG_ERR, "ERROR: unlock_directories.c : WAIT FAILED");
        }

        if( (WIFEXITED(status)) )
        {
            if( WEXITSTATUS(status) != 0 )
            {
                syslog(LOG_ERR, "ERROR: UNLOCKING DIRECTORIES, STATUS %d", WEXITSTATUS(status));
            } else
            {
                syslog(LOG_INFO, "DIRECTORIES UNLOCKED");
            }
        }
    }
}
        
