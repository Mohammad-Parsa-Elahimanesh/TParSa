#!/bin/bash

first_dir=$PWD
cd $(dirname "$(realpath "$0")")

result="tempSubtaskOutput.txt"
Quera="../Quera_Test"
inputs=$Quera"/in"

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
    	echo "enter validator $j of subtask $i: "
    	read validator[$j-1]
    	validator[$j-1]="../validator/"${validator[j-1]%.cpp}
    	bash ./Compile.sh ${validator[j-1]} || exit 11 
    done
    
    for test in $inputs/*;do
        is_valid=1
        for ((j=1; j<=count; j++))
    	do
    		./${validator[j-1]} < $test >/dev/null 2>/dev/null || is_valid=0
    	done
        if [ $is_valid -eq 1 ]; then
            number=$(echo "$test" | grep -o '[0-9]\+' | tail -n 1)
            echo $i $number $number >> $result 
        fi
    done
    
    for ((j=1; j<=count; j++))
    do
    	rm ${validator[j-1]}
    done
    
done

bash ./Config.sh < $result && rm $result && mv config.json $Quera 
cd $first_dir
echo Finish
