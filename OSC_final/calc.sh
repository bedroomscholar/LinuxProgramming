#!/bin/bash
# calc.sh — Shell Calculator
# Usage: ./calc.sh <number_of_calculations>

# ── Math functions ──────────────────────────────────

Add() {
    echo $(( $1 + $2 ))
}

Minus() {
    echo $(( $1 - $2 ))
}

Multiply() {
    echo $(( $1 * $2 ))
}

Divide() {
    if [[ $2 -eq 0 ]]; then
        echo "ERROR: Division by zero"
        return 1
    fi
    echo "scale=2; $1 / $2" | bc
}

# ── Calc: dispatches to the correct operation ──────

Calc() {
    local a=$1
    local b=$2
    local op=$3

    case $op in
        '+') Add $a $b ;;
        '-') Minus $a $b ;;
        '*') Multiply $a $b ;;
        '/') Divide $a $b ;;
        *)   echo "Unknown operation: $op"; return 1 ;;
    esac
}

# ── Main program ───────────────────────────────────

# Check command line argument
if [[ $# -ne 1 ]]; then
    echo "Usage: $0 <number_of_calculations>"
    exit 1
fi

count=$1

for (( i=1; i<=count; i++ )); do
    echo "--- Calculation $i of $count ---"
    read -p "Give 1st argument: " num1
    read -p "Give 2nd argument: " num2
    read -p "Give operation (+, -, *, /): " op

    result=$(Calc $num1 $num2 "$op")

    if [[ $? -eq 0 ]]; then
        echo "$num1 $op $num2 = $result"
    else
        echo "Error: $result"
    fi
    echo
done

echo "Done! Completed $count calculation(s)."
