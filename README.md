# speller-program
 Scans a given text file for any misspelled words

Directories:
1. dictionaries: a file that contains all words in the dictionary
2. texts: contains sample text files with misspelled words to be used as input to the program
3. keys: contains corrected text files which the program should return

Files: 
1. Makefile: a configuration file which defines the make function
2. dictionary.c: defines the functions to load, hash, and check the text files input into the program
3. dictionary.h: defines the prototype for functions which simplifies the design of the code in dictionary.c
4. speller.c: the program iteslf which double-checks a file after loading a "dictionary" of words from disk into memory. (implemented in dictionary.c)

