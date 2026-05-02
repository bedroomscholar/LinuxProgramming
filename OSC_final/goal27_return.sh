is_even() {
    if [[ $(($1 % 2)) -eq 0 ]]; then
        return 0    # 0 = true/success in bash
    else
        return 1    # non-zero = false/failure
    fi
}

# Test return with $?
is_even 4
echo "Is 4 even? Exit status: $? (0=yes, 1=no)"

is_even 7
echo "Is 7 even? Exit status: $? (0=yes, 1=no)"

# Method 2: echo + $() for string/number results
get_max() {
    if [[ $1 -gt $2 ]]; then
        echo $1
    else
        echo $2
    fi
}

max=$(get_max 15 42)
echo "Max of 15 and 42 is: $max"
