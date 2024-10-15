#!/bin/bash

result="tempSubtaskOutput.txt"
inputs="Quera_Test/in"

rm $result 2>/dev/null
touch $result

echo "enter number of subtasks: "
read sub
echo $sub >> $result

declare -a score
for ((i=1; i<=sub; i++))
do
    echo "enter score of subtask number : $i"
    read score[$i-1]    
    echo ${score[i-1]} >> $result
done

for ((i=1; i<=sub; i++))
do
    echo "enter count of validators $i"
    read count
    declare -a validator
    
    for ((j=1; j<=count; j++))
    do
    	echo "enter validator $j"
    	read validator[$j-1]
    	validator[$j-1]="validator/"${validator[j-1]%.cpp}
    	Compile ${validator[j-1]} || exit 11 
    done
    
    for test in $inputs/*;do
    	for ((j=1; j<=count; j++))
    	do
    		./${validator[j-1]} < $test >/dev/null 2>/dev/null || break
    		if [[ $j -eq $count ]]; then
    			echo $i ${test:19:-4} ${test:19:-4} >> $result 
    		fi
    	done
    done
done

bash ./Config.sh < $result && rm $result
echo Finish

