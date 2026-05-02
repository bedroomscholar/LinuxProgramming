
# Example 1: Loop over a list of words
echo "=== Fruits ==="
for fruit in Apple Banana Cherry; do
    echo "I like $fruit"
done

# Example 2: Loop over a range of numbers
echo ""
echo "=== Numbers 1 to 5 ==="
for i in {1..5}; do
    echo "Number: $i"
done

# Example 3: Loop over files
echo ""
echo "=== Shell scripts in current directory ==="
for file in *.sh; do
    echo "Found script: $file"
done
