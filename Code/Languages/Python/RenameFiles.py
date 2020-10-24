'''
    Kevin Tran
    February 07, 2018
    Python 3.6.1

    This is a script that will rename all files containing a given sequence of characters in a given directory.
'''


import os
import sys
import time


# Prompt the user for the file path and file names.
def ask_user():
    # Get the file path.
    file_path = get_file_path()

    # Get the target sequence of characters from the old file name.
    old_file_name = get_target_file_name()

    # Get the new file name.
    new_file_name = get_new_file_name()

    return file_path, old_file_name, new_file_name


# Check the given file path.
def check_file_path(file_path):
    if not os.path.exists(file_path):
        print("\nThis file path does not exist! Stopping the script...\n")
        time.sleep(3)
        sys.exit()
    else:
        return file_path


# Tell the user the purpose of this script.
def describe_script():
    print("\nThis script will rename all files with an indicated name within" \
          " a directory that the user indicates to the program. The target" \
          " files will ONLY have the indicated segment of their file name" \
          " changed to the requested character sequence.\n")


# Announce that the script is done.
def end_script():
    print("\nDONE. You may now close the script by pressing the Enter key.")
    input("")
    sys.exit()


# Determine whether this file already exists.
def file_exists(file_name):
    if os.path.exists(file_name):
        return True
    else:
        return False


# Search for the target files within the given directory.
def find_files(file_path, old_substring, new_substring):
    # Mark whether a file name with the matching substring exists.
    substring_exists = False

    # List all files within the directory.
    files = os.listdir(file_path)

    # Search within the directory for matching substrings in the file names.
    for item in files:
        if old_substring in item:
            substring_exists = True
            file_name = os.path.join(file_path, item)  # Get the absolute pathing.
            rename_file(file_name, old_substring, new_substring)

    # If no matching files were found, then tell the user.
    if substring_exists == False:
        print("\nNo matching file names were found! Stopping the script...\n")
        time.sleep(3)
        sys.exit()


# Ask the user for the target file path.
def get_file_path():
    return check_file_path(input("\nPlease provide the file path: "))


# Ask the user for the new file name.
def get_new_file_name():
    return input("\nReplace the characters in those files to: ")


# Ask the user for the target files to rename.
def get_target_file_name():
    return input("\nFind all file names with the characters: ")


# Rename the highlighted file.
def rename_file(target_file, old_substring, new_substring):
    if not file_exists(target_file):
        os.rename(target_file, target_file.replace(old_substring, new_substring))
    else:
        print("\nThere already exists a file with this name!" \
              " Stopping the script...\n")
        time.sleep(3)
        sys.exit()


# Main wrapper function.
def main():
    # Describe the purpose of the script.
    describe_script()

    # Engage with the user.
    file_path, old_file_name, new_file_name = ask_user()

    # Replace the given characters.
    find_files(file_path, old_file_name, new_file_name)

    # Complete the script.
    end_script()


if __name__ == '__main__':
    main()
