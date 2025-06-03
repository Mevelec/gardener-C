#!/bin/sh

# Prompt user for choice
echo "Please select a build system:"
echo "1. Visual Studio 2022"
echo "2. Visual Studio 2019"
echo "3. GMake"
while true; do
  read -p "Enter your choice (1/2/3): " choice
  case "$choice" in
    1)
      build_system="vs2022"
      break
      ;;
    2)
      build_system="vs2019"
      break
      ;;
    3)
      build_system="gmake"
      break
      ;;
    *)
      echo "Invalid choice, please try again."
      ;;
  esac
done

# Change to parent directory
cd .. || { echo "Failed to change directory"; exit 1; }

# Call premake with the selected build system
./vendor/premake/premake5.work "$build_system"
result=$?

# Return to previous directory
# (Optional, since script ends here)
# cd -

# Check for error and pause if needed
if [ "$result" -ne 0 ]; then
  read -p "Premake failed. Press Enter to continue..."
fi