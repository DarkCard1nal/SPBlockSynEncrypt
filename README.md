# SPBlockSynEncrypt
C++ Module (library) for using and studying S-blocks and P-blocks for symmetric encryption algorithms.

# installation:

#include "SPBlockSynEncrypt.h"

# Opportunities:

Class Methods:

static unsigned char SCrypt(unsigned char arr[][16], const unsigned char key, const unsigned char block) - a method of encrypting/decrypting a character with an S-block using a table and a key.
//A static method for encoding and decoding an S-block using the 'arr' and 'key' matrix table makes a replacement 
//for 0-3 and 4-7 bits of 'block', returns the replaced block, the 'arr' table must contain a column with 
//the number 'block' and a row with the number 'key', the 'arr' table itself consists of 4-bit unsigned char, 
//otherwise an error may occur, it is important that the 'arr' table does not have duplicate elements in the rows, 
//since duplicates cause information loss and make it impossible to restore data, to check the matrix for duplicates or 
//elements larger than 4 bits, use the static method STableCheck(), also use the STableTransform() method to transform 
//the table from encryption for decryption and vice versa.

static std::string SCrypt(unsigned char arr[][16], const unsigned char key, const std::string blocks) - a method of encrypting/decrypting a string with an S-block using a table and a key, using the SCrypt() method for one character (same as above).

static __int16 STableCheck(unsigned char arr[][16], const unsigned char rows) - method for checking the table for 'correctness'.
//A static method for checking the 'arr' table for S-block encryption functions, 'rows' - the number of rows in the 'arr' 
//table, the table 'arr' must have 16 columns (4 bits), the method checks the table for duplicate elements or 
//elements larger than 4 bits in the rows, if no such elements are found, returns -1, otherwise returns 
//the number of the first row in which a duplicate is found or elements larger than 4 bits in the rows

static bool STableTransform(unsigned char arr[][16], const unsigned char rows) - a method for converting a table from encryption to decryption and vice versa.
//A static method for transforming the 'arr' table of an S-block encryption for decryption and vice versa, 
//'rows' - the number of rows in the 'arr' table, the table 'arr' must have 16 columns (4 bits), 
//returns true if the 'arr' table was transformed, or false if the 'arr' table failed the duplicate check using 
//the STableCheck() method, in which case the values of the 'arr' table are not changed.

static unsigned char PCrypt(const unsigned char key, const unsigned char block) - a method of encrypting/decrypting a character with an P-block using a key.
//A static method for encrypting and decrypting a 'block' character using 'key', returns an encrypted/decrypted 'block',
//depending on the 'key', can return the 'block' unchanged

static std::string PCrypt(const unsigned char key, const std::string blocks) - - a method of encrypting/decrypting a string with an P-block using a key, using the SCrypt() method for one character (same as above).


# Examples and tests in examples.cpp
