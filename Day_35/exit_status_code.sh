#!/bin/bash

: '
    status codes are returned after execution of line of program . its values are from 0 to 255 
'

echo "hello world" 
echo $?

fkgdg
# echo $?   this will return 127 that means command not found !!! 