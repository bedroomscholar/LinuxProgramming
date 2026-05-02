
read -p "Enter a number: " num

if [[ $num -gt 0 ]]; then
    echo "$num is positive"
elif [[ $num -eq 0 ]]; then
    echo "$num is zero"
else
    echo "$num is negative"
fi

