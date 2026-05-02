
read -p "Enter your name: " name
echo "Hello, $name!"

# Read multiple variables
read -p "Enter your first and last name: " first last
echo "First: $first, Last: $last"

# Read with a timeout (5 seconds)
read -t 5 -p "Quick! Enter a number (5 sec): " num
if [[ -z $num ]]; then
    echo -e "\nToo slow! No input received."
else
    echo "You entered: $num"
fi

