#include <unistd.h>
#include <syslog.h>
#include <sys/wait.h>
#include <sys/stat.h>

void check_file_uploads(void)
{
    char *manufacturing_report = "/home/fluffyhobo/systems_software/ca1/src/uploaded_manager_reports/manufacturing_report.xml";
    char *warehouse_report = "/home/fluffyhobo/systems_software/ca1/src/uploaded_manager_reports/warehouse_report.xml"    ;
    char *sales_report = "/home/fluffyhobo/systems_software/ca1/src/uploaded_manager_reports/sales_report.xml";
    char *distribution_report = "/home/fluffyhobo/systems_software/ca1/src/uploaded_manager_reports/distribution_report.xml";

    char *reports[] = {manufacturing_report ,  warehouse_report, sales_report, distribution_report};

    pid_t  pid;
    pid = fork();

    if(pid == -1) // Error check for if fork fails
    {
        syslog(LOG_ERR, "ERROR: check_file_uploads.c : FORK FAILED");
    } else if (pid == 0) // Code executed by child
    {
        syslog(LOG_INFO, "CHECKING FOR UPLOADED XML REPORTS");

        for(int i = 0; i < (int)(sizeof(reports) / sizeof(reports[0])); ++i) // For loop to check if all files are present
        {
                if( access(reports[i], F_OK) == -1)
                {
                        syslog(LOG_INFO,"REPORT %s NOT UPLOADED", reports[i]);
                }
        }
    } else // Parent waiting for status from child
    {
        int status;

        if(wait(&status) == -1)
        {
            syslog(LOG_ERR, "ERROR: check_file_uploads.c : WAIT FAILED");
        }

        if( (WIFEXITED(status)) )
        {
            if( WEXITSTATUS(status) != 0 )
            {
                syslog(LOG_ERR, "ERROR: CHECKING FILES: STATUS %d", WEXITSTATUS(status));
            } else
            {
                syslog(LOG_INFO, "FILES SUCCESSFULLY CHECKED, STATUS %d", WEXITSTATUS(status));
            }
        }
    }
}

      
