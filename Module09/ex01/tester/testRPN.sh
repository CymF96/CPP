#!/bin/bash
BOLD="\033[1m"
RESET="\033[0m"

# Check if a test file is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <test_file>"
    exit 1
fi

# Read the test file line by line
while IFS= read -r line; do
    echo -e "Testing:${BOLD} \"$line\" ${RESET}"
    ../RPN "$line"
    echo -e "------------------------"
done < "$1"