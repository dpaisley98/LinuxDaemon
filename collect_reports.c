#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <syslog.h>

void collect_reports(void)
{
    pid_t  pid;

    pid = fork();
    if(pid == -1) // Error check for if fork fails
    {
        syslog(LOG_ERR, "ERROR: collect_reports.c : FORK FAILED");
    } else if (pid == 0) // Code executed by child
    {
        syslog(LOG_INFO, "COLLECTING REPORTS");
        char *collect_script = "/home/fluffyhobo/systems_software/ca1/src/scripts/collect_reports.sh";
        char *args[] = {"/bin/sh", collect_script, NULL};

        execvp(args[0], args);
    } else // Parent waiting for status from child
    {
        int status;

        if(wait(&status) == -1)
        {
            syslog(LOG_ERR, "ERROR: collect_reports.c : WAIT FAILED");
        }

        if( (WIFEXITED(status)) )
        {
            if( WEXITSTATUS(status) != 0 )
            {
                syslog(LOG_ERR, "ERROR: COLLECTING REPORTS FROM UPLOAD DIRECTORY: STATUS %d", WEXITSTATUS(status));
            } else
            {
                syslog(LOG_INFO, "REPORTS COLLECTED SUCCESSFULLY, STATUS %d", WEXITSTATUS(status));
            }
        }
    }
}

