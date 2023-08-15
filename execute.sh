#!/bin/bash

# Find the process ID of ./daemon
pid=$(pgrep -f "./daemon")

# Kill the process
kill -2 $pid
