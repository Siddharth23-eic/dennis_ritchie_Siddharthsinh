#!/bin/bash

# Prompt for input
chapter=8
read -p "Enter Exercise number: " exercise
# Get current date
current_date=$(date +"%d/%m/%Y")

# Loop for Exercise 1 to 24
filename=$(printf "168863_Siddharthsinh_Rana_DR_Ch%d_E%d.c" "$chapter" "$exercise")
exercise_label=$(printf "%d.%d" "$chapter" "$exercise")

if [ -f "$filename" ]; then
    echo "File '$filename' already exists. Skipping creation."
    exit 1
fi
    cat << EOF > "$filename"
/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: $current_date
 * Chapter: $chapter
 * Exercise: $exercise_label
 * Description:
 */

#include <stdio.h>
#include <stdint.h>

int exerscise${chapter}_${exercise}() {
    // Your code goes here

    return 0;
}

EOF

    echo "Created: $filename with Exercise: $exercise_label"

