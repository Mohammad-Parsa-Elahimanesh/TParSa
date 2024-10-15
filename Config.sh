#!/bin/bash

echo "enter number of subtasks: "
read sub

declare -a score
for ((i=1; i<=sub; i++))
do
    echo "enter score of subtask number : $i"
    read score[$i-1]
done

echo "enter 3 numbers in a range (subtask, l, r) inclusive [l, r], 0 0 0 for ends"
declare -a subs
while true
do
    read s l r
    if [[ $s -lt 0 || $l -lt 0 || $r -lt 0 || $r -lt $l || $s -gt $sub ]]
    then
        continue
    fi
    if [[ $s -eq 0 && $l -eq 0 && $r -eq 0 ]]
    then
        break
    fi
    if [[ $s -eq 0 ]]
    then
        continue
    fi
    for ((i=l; i<=r; i++))
    do
        subs[$s-1]+="$i "
    done
done

rm config.json 2>/dev/null

echo "{" >> config.json
echo "    \"packages\": [" >> config.json
for ((i=0; i<sub; i++))
do
    echo "        {" >> config.json
    echo "            \"score\": ${score[$i]}," >> config.json
    echo "            \"tests\": [" >> config.json

    sorted_subs=($(echo "${subs[$i]}" | tr ' ' '\n' | sort -n | tr '\n' ' '))
    unique_subs=($(echo "${sorted_subs[@]}" | tr ' ' '\n' | uniq | tr '\n' ' '))
    for ((j=0; j<${#unique_subs[@]}; j++))
    do
        echo "                ${unique_subs[$j]}$(if [[ $j -eq $((${#unique_subs[@]}-1)) ]]; then echo ""; else echo ","; fi)" >> config.json
    done
    
    echo "            ]" >> config.json
    echo "        }$(if [[ $i -eq $(($sub-1)) ]]; then echo ""; else echo ","; fi)" >> config.json
done

echo "   ]" >> config.json
echo "}" >> config.json
