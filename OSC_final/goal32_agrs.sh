echo "Script name:        \$0 = $0"
echo "First argument:     \$1 = $1"
echo "Second argument:    \$2 = $2"
echo "Third argument:     \$3 = $3"
echo "Number of arguments:\$# = $#"
echo "All arguments:      \$@ = $@"

echo ""
echo "--- Looping through all arguments ---"
for arg in "$@"; do
    echo "  Argument: $arg"
done
