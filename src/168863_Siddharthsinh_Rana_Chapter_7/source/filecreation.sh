#!/bin/bash

# Prompt for input
chapter=7
read -p "Enter Excercise number: " excercise
# Get current date
current_date=$(date +"%d/%m/%Y")

# Loop for Exercise 1 to 24
filename=$(printf "168863_Siddharthsinh_Rana_DR_Ch%d_E%d.c" "$chapter" "$excercise")
exercise_label=$(printf "%d.%d" "$chapter" "$excercise")

if [ -f "$filename" ]; then
    echo "File '$filename' already exists. Skipping creation."
    exit 1
fi
    cat << EOF > "$filename"
/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: $current_date
 * Chapter: 5
 * Exercise: $exercise_label
 * Description:
 */

#include <stdio.h>
#include <stdint.h>

int exerscise${chapter}_${excercise}() {
    // Your code goes here

    return 0;
}

EOF

    echo "Created: $filename with Exercise: $exercise_label"

