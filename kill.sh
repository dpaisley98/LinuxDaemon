#!/bin/bash

# Find the process ID of ./daemon
pid=$(pgrep -f "./daemon")

# Kill the process
kill $pid
