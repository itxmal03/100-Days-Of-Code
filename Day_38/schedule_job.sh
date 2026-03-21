#!/bin/bash


#practiced using at command 
# file=log_results.log

# echo "then command ran at: $(date)!!!!!!" > $file  


#using cronjob / crontab 
# we prefer using full path instead of just command name while working crontab 

/usr/bin/echo "hi"

file=~/log_r.log

echo "then command ran at: $(date)!!!!!!" > $file  




