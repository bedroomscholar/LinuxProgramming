echo "Choose your favorite fruit:"
select fruit in "Apple" "Banana" "Cherry" "Quit"; do
    case $fruit in
        "Apple")  echo "You chose Apple! Good choice." ;;
        "Banana") echo "You chose Banana! Rich in potassium." ;;
        "Cherry") echo "You chose Cherry! Sweet and tasty." ;;
        "Quit")   echo "Goodbye!"; break ;;
        *)        echo "Invalid option. Try again." ;;
    esac
done
