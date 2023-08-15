date=$(date +'%d-%m-%Y')


tar -czf /home/fluffyhobo/systems_software/ca1/src/backups/backup_dashboard-${date}.tar.gz -C /home/fluffyhobo/systems_software/ca1/src/dashboard --transform "s|dashboard|backup_dashboard-${date}|" -p .
