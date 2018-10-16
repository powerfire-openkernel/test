from sys import argv, stdout # Arguments and 'stdout' buffer
from os import path # Information about file
from time import ctime # Timestamp to Date String

if len(argv) == 3: # If 2 arguments present
    FileHandle = open(argv[2], "rb") # Creating binary stream

    if argv[1] == "-info": # Information about file
        print("File: %s" % FileHandle.name) # Filename
        print("Location: %s" % path.abspath(argv[2])) # File Location
        print("Modified: %s" % ctime(path.getmtime(argv[2]))) # When last modfied
        print("Acessed: %s" % ctime(path.getatime(argv[2]))) # When last acessed
        print("Size: %sB" % path.getsize(argv[2])) # Size of file

    elif argv[1] == "-raw": # Raw binary file bytes.
        print(FileHandle.read()) # Prints bytes.
    
    FileHandle.close() # Closing binary stream

elif len(argv) == 2: # Reading files
    FileHandle = open(argv[1], "rb") # Creating binary stream
    stdout.buffer.write(FileHandle.read()) # Writing bytes to BufferedWritter
    FileHandle.close() # Closing binary stream

elif len(argv) == 1: # Prints help message
    print("""
╭───────────────╮
│ PyFile │ v1.0 │
╰───────────────╯

Usage: pyf [-info | -raw] sample.txt

Options:

    -info     Information about file.
    -raw      Prints raw binary data.
""") # Printing help message
