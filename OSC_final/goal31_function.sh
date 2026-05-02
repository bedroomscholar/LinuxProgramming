greet() {
    local name=$1        # $1 = first parameter passed to function
    local greeting=$2    # $2 = second parameter
    echo "$greeting, $name!"
    return 0             # 0 means success
}

# Function 2: add — returns result via echo
add() {
    local a=$1
    local b=$2
    local sum=$((a + b))
    echo $sum            # "return" the result by printing it
}

# Call greet function
greet "Hong" "Hello"
greet "World" "Hi"

# Call add function and capture result
result=$(add 10 25)
echo "10 + 25 = $result"

result=$(add 100 200)
echo "100 + 200 = $result"
