#!/bin/bash

#array creation 
# arr=(a b c)
# echo "${arr[0]} ${arr[1]} ${arr[2]}"
# echo "${arr[@]}"  # for all elements 
# echo "${arr[*]}"  # also for all elements 


# | Feature          | Bash Array  | C++ `vector` | Dart `List` |
# | ---------------- | ----------- | ------------ | ----------- |
# | Dynamic size     | ✅ Yes       | ✅ Yes        | ✅ Yes       |
# | Typed            | ❌ No        | ✅ Yes        | ✅ Yes       |
# | Index access     | `${arr[0]}` | `v[0]`       | `list[0]`   |
# | Out of bounds    | ❌ empty     | ⚠️ undefined | ❌ error     |
# | Built-in methods | ❌ No        | ✅ many       | ✅ many      |


# adding elements 
arr=(a b c)
arr+=(d)   
echo "${arr[*]}"
