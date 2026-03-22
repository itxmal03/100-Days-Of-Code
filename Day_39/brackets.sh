#!/bin/bash 

#brackets usage 

#1. {} mostly used for grouping commands like
# {
#     echo "command 1"
#     echo "command 2"
#     ls -alh 
# }>output.txt   ## for sending output to somewhere 

#2.Brace expansion (generate sequences)
# echo file{1..3}.txt    file1.txt file2.txt file3.txt                    expected output 
# echo ot{1..3}.tx       ot1.tx ot2.tx ot3.tx                             expected output 


#3.Variable expansion
# echo "${HOME}"  # braces are needed when you append something
# echo "${HOME}_suffix"


# | Brackets            | Usage                         | Example                                            |   |   |
# | ------------------- | ----------------------------- | -------------------------------------------------- | - | - |
# | `[ condition ]`     | Old-school **test command**   | `[ -f "$file" ]` checks if file exists             |   |   |
# | `[[ condition ]]`   | Modern Bash **extended test** | `[[ -f "$file" && -r "$file" ]]` allows `&&` and ` |   | ` |
# | `(( expression ))`  | Arithmetic evaluation         | `(( n = n + 1 ))`                                  |   |   |
# | `$(( expression ))` | Arithmetic **expansion**      | `total=$((a+b))`                                   |   |   |


# Tip:
# [ ... ] is POSIX compatible
# [[ ... ]] is Bash-specific but safer for string comparison and logical operators



#4.When parentheses ( ) are used
# (cd /tmp; ls)  # current directory outside /tmp is unaffected


