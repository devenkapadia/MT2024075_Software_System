# /*

# Name: p7.sh
# Author: Kapadia Deven
# Description: Write a program to copy file1 into file2 ($cp file1 file2).
# Date: 26 Aug, 2024

# */

src="$1"
dst="$2"

if [ ! -f "$src" ]; then
    echo "Error: Source file '$src' does not exist."
    exit 1
fi

cp "$src" "$dst"

if [ $? -eq 0 ]; then
    echo "File copied successfully."
else
    echo "Error: File could not be copied."
    exit 1
fi
