#!/bin/bash

C_STD="\033[0;39m"
C_GRAY="\033[0;90m"
C_RED="\033[0;91m"
C_GREEN="\033[0;92m"
C_YELLOW="\033[0;93m"
C_BLUE="\033[0;94m"
C_MAGENTA="\033[0;95m"
C_CYAN="\033[0;96m"
C_WHITE="\033[0;97m"

if [ -z "$numbers" ]; then
	read -p "Set the numbers to the test: " numbers
fi

printf "\n$C_MAGENTA➜ Testing push_swap $C_STD\n\n"

printf "rules|amount\n"
printf "%s|%s\n" "-----" "------"
./push_swap $numbers | awk '{
	for (i = 1; i <= NF; i++) {
		count[$i]++
		total++
	}
}
END {
	for (w in count) printf "%-5s|%5d\n", w, count[w]
		printf "%s|%s\n", "-----", "------"
		printf "Total|"
		if (total > 5500)
			printf "\033[0;91m"
		else
			printf "\033[0;92m"
		printf "%5d\n", total
}'

printf "\n"

./push_swap s $numbers | tail -n 1