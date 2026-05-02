count=1
until [[ $count -gt 5 ]]; do
    echo "Count: $count"
    ((count++))
done

echo "Loop finished. Final count: $count"

