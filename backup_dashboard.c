#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void backup_dashboard(void)
{
	pid_t  pid;

	pid = fork();
    if(pid == -1) // Error check for if fork fails
    {
        syslog(LOG_ERR, "ERROR: backup_dashboard.c : FORK FAILED");
    } else if (pid == 0) // Code executed by child
	{
	    syslog(LOG_INFO, "BACKING UP DASHBOARD");
	    char *backup_script = "/home/fluffyhobo/systems_software/ca1/src/scripts/backup_reports.sh";
		char *args[] = {"/bin/sudo", backup_script, NULL};

		execvp(args[0], args);
	} else // Parent waiting for status from child
	{
		int status;
		
		if(wait(&status) == -1)
		{
			syslog(LOG_ERR, "ERROR: backup_dashboard.c : WAIT FAILED");
		}

		if( (WIFEXITED(status)) )
		{
			if( WEXITSTATUS(status) != 0 )
			{
				syslog(LOG_ERR, "ERROR: BACKING UP DASHBOARD DIRECTORY; STATUS %d", WEXITSTATUS(status));
			} else
			{
				syslog(LOG_INFO, "REPORTS BACKED UP SUCCESSFULLY, STATUS %d", WEXITSTATUS(status));
			}
		}
	}
}

