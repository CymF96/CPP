#!/bin/bash
RESET="\033[0m"
BOLD="\033[1m"
BLUE="\033[34m"
MAGENTA="\033[35m"
GREEN="\033[32m"


# comparing 2nd line of program output with variable saving sorted number -- if same number print OK else WRONG SORTING
compare() {
    # variable with random number
    initSequence=$(shuf -i 1-100 -n 30000 | tr "\n" " ")
    # variable saving sorting number
    sortedSequence=$(echo -e "$initSequence" | tr ' ' '\n' | sort -n | tr '\n' ' ')

    # execute ./PmergeMe with initSequence
    pmergeOutput=$(./PmergeMe $initSequence)

    # Extract the 2nd and 6th lines from the output, removing the "After:" part
    pmergeSequenceCont1=$(echo -e "$pmergeOutput" | sed -n '3p' | sed 's/After://g')
    pmergeSequenceCont2=$(echo -e "$pmergeOutput" | sed -n '7p' | sed 's/After://g')

    # Remove any spaces and extra whitespace from the sequences
    sortedSequenceNoSpaces=$(echo -e "$sortedSequence" | tr -d '[:space:]')
    pmergeSequenceCont1NoSpaces=$(echo -e "$pmergeSequenceCont1" | tr -d '[:space:]')
    pmergeSequenceCont2NoSpaces=$(echo -e "$pmergeSequenceCont2" | tr -d '[:space:]')

    # Debugging information to help with understanding the output
    #echo -e "initSequence: $initSequence"
    #echo -e "sortedSequenceNoSpaces: $sortedSequenceNoSpaces"
    #echo -e "pmergeSequenceCont1NoSpaces: $pmergeSequenceCont1NoSpaces"
    #echo -e "pmergeSequenceCont2NoSpaces: $pmergeSequenceCont2NoSpaces"

    # String comparison of the sequences
    if [[ "$pmergeSequenceCont1NoSpaces"="$sortedSequenceNoSpaces" && "$pmergeSequenceCont2NoSpaces"="$sortedSequenceNoSpaces" ]]; then
        echo "OK"
    else
        echo "WRONG SORTING"
    fi
}

compare