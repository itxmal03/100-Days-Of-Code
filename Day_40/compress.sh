#!/bin/bash

set -euo pipefail

if [ $# -ne 4 ]; then 
    echo "Usage: compress <input_file> <start_time 00:00:00> <end_time 00:00:00> <output_name>"
    exit 1
fi

input="$1"
start="$2"
end="$3"
output="$4"
log="compress.log"


if ! command -v ffmpeg &> /dev/null; then
    echo "Error: ffmpeg is not installed!"
    exit 1
fi

if [ ! -f "$input" ]; then  
    echo "Error: File does not exist!"
    exit 1
fi

[[ "$output" != *.mp4 ]] && output="${output}.mp4"
 
 time_regex="^[0-9]{2}:[0-9]{2}:[0-9]{2}$"

if ! [[ "$start" =~ $time_regex && "$end" =~ $time_regex ]]; then
    echo "Error: Time format must be HH:MM:SS"
    exit 1
fi

if [ -f "$output" ]; then
    echo "Error: Output file already exists!"
    exit 1
fi 

if ffmpeg -i "$input" \
    -ss "$start" -to "$end" \
    -vf "hqdn3d=1.5:1.5:6:6" \
    -c:v libx265 -crf 25 -preset medium \
    -c:a aac -b:a 128k \
    "$output"
then
    echo "Compression completed: $output"
    echo "[INFO] $(date) - Input: $input | Output: $output" >> "$log"
else
    echo "Error: Compression failed!"
    exit 1
fi
