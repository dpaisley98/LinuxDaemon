# Daemon Process for Scheduled Tasks

This repository contains a daemon process written in C that performs scheduled tasks using Linux system calls. The daemon is designed to execute specific tasks at predefined times of the day.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)

## Introduction

This daemon process is designed to run in the background and execute various tasks at scheduled times. It incorporates the concept of orphan processes to ensure that the process continues running even after the parent process exits. The daemon handles tasks such as checking uploaded files, performing backups, and generating reports.

## Features

- Scheduled execution of tasks at specific times.
- Implementation of orphan processes to prevent termination when the parent process exits.
- Signal handling for graceful shutdown or interruption.
- Logging using the system logger for monitoring and debugging.
- Shell scripts integration to execute Linux commands for specific tasks.

## Requirements

- C compiler (e.g., gcc)
- Linux environment
- Shell scripts for performing specific tasks (provided separately)

## Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/dpaisley98/LinuxDaemon.git
2. Compile the code with the accompanying make file

## Usage

1. Make sure you have the required shell scripts with Linux commands to perform the actual tasks (e.g., backup, report generation). Place these scripts in the appropriate directory.
2. Modify the C code (daemon.c) to provide the correct paths to the shell scripts.
3. Use the provided Makefile to compile the daemon process:
   - To compile the daemon process, simply navigate to the project directory in your terminal and run:
   
     ```sh
     make
     ```
4. Run the compiled daemon process:
   ```sh
   ./daemon_process

