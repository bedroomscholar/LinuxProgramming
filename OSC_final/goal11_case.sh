read -p "Enter a letter: " letter

case $letter in
    [aeiouAEIOU])
        echo "'$letter' is a vowel"
        ;;
    [a-zA-Z])
        echo "'$letter' is a consonant"
        ;;
    [0-9])
        echo "'$letter' is a digit"
        ;;
    *)
        echo "'$letter' is a special character"
        ;;
esac

