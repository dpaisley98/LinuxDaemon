#include <syslog.h>
#include <stdio.h>
#include <time.h>

void update_timer(struct tm *due_date)
{
	syslog(LOG_INFO, "CURRENT DAY: %d", due_date -> tm_mday);
	due_date -> tm_mday += 1;
  	mktime(due_date);	
	syslog(LOG_INFO, "TIMER UPDATED, DUE NEXT DAY: %d", due_date -> tm_mday);
}
