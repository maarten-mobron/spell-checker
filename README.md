# Spell-checker

The following code implements a spell-checker program in C. It reads a dictionary file containing a list of correctly spelled words, loads it into memory, and then reads a text file to spell-check the words in it.

## Usage

Compile the code and create an executable named `speller`.

Run the program using the following command: `./speller [DICTIONARY] text`, where:

- `[DICTIONARY]` (optional) is the path to the dictionary file to be used. If not provided, it uses the default dictionary file "dictionaries/large".
- `text` is the path to the text file to be spell-checked.

Upon running, the program performs the following steps:

1. Checks if the correct number of command-line arguments is provided. If not, it displays the correct usage and exits.
2. Initializes variables for benchmarking and timing data.
3. Determines the dictionary file to be used based on the command-line arguments.
4. Loads the dictionary file into memory using the `load` function. It measures the time taken for loading the dictionary.
5. If the dictionary fails to load, it displays an error message and exits.
6. Opens the text file specified by the command-line arguments for spell-checking.
7. Starts spell-checking each word in the text file.
8. Ignores non-alphabetical characters, collects alphabetical characters to form words, and checks their spelling against the loaded dictionary using the `check` function. It measures the time taken for each word check and counts the misspelled words.
9. Prints the misspelled words found during spell-checking.
10. Closes the text file.
11. Determines the size of the loaded dictionary using the `size` function. It measures the time taken for determining the size.
12. Unloads the dictionary from memory using the `unload` function. It measures the time taken for unloading.
13. Prints statistics including the number of misspelled words, the number of words in the dictionary, the number of words in the text, and the time taken for each step of the spell-checking process.
14. Exits the program with a success status.

The `dictionary.h` and `dictionary.c` files contain the implementation of the dictionary-related functions used in the main program.

Note: The code assumes that the dictionary file and text file are formatted correctly and that the `dictionary.h` file is available in the same directory as the main program.
