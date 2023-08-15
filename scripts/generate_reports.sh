#!/bin/bash

audit_file="audit-report-$(date +'%d-%m-%Y').txt"
syslog_report="syslog-report-$(date +'%d-%m-%Y').txt"

date=$(date +'%b %-d')

#generate audit log 
sudo ausearch -k upload-check | sudo aureport -f -i  > /home/fluffyhobo/systems_software/ca1/src/generated_reports/$audit_file

sudo cat /var/log/daemon.log | grep -a "$date.*MANUFACTURING-REPORT-DAEMON" > /home/fluffyhobo/systems_software/ca1/src/generated_reports/$syslog_report

