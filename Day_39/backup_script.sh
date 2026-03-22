#!/bin/bash

if [ $# -ne 2 ]
then 
    echo "Usage: $0 <source directory> <target directory>"
    exit 1
fi

SOURCE_DIR=$1
TARGET_DIR=$2

#check if rsync exist or not 

if ! command -v rsync > /dev/null 2>&1 
then
    echo "This script requires rsync to run. Install it and then try!!!"
    exit 2
fi

#capture date and store it in this format YYYY-MM-DD 
current_date=$(date +%Y-%m-%d)

# rsync_options="-avb --backup-dir $TARGET_DIR/$current_date --delete --dry-run"  this will only simulte because of --dry-run option 

rsync_options="-avb --backup-dir $TARGET_DIR/$current_date --delete"

$(which rsync) $rsync_options "$SOURCE_DIR" "$TARGET_DIR"/current >> backup_"$current_date".log 