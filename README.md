# SPBlockSynEncrypt
C++ Module (library) for using and studying S-blocks and P-blocks for symmetric encryption algorithms.

# installation:

#include "SPBlockSynEncrypt.h"

# Opportunities:

Class Methods:

static unsigned char SCrypt(unsigned char arr[][16], const unsigned char key, const unsigned char block) - a method of encrypting/decrypting a character with an S-block using a table and a key.

static std::string SCrypt(unsigned char arr[][16], const unsigned char key, const std::string blocks) - a method of encrypting/decrypting a string with an S-block using a table and a key, using the SCrypt() method for one character.

static __int16 STableCheck(unsigned char arr[][16], const unsigned char rows) - method for checking the table for 'correctness'.

static bool STableTransform(unsigned char arr[][16], const unsigned char rows) - a method for converting a table from encryption to decryption and vice versa.

static unsigned char PCrypt(const unsigned char key, const unsigned char block) - a method of encrypting/decrypting a character with an P-block using a key.

static std::string PCrypt(const unsigned char key, const std::string blocks) - - a method of encrypting/decrypting a string with an P-block using a key, using the PCrypt() method for one character .

# More information about algorithms and methods in the comments of 'SPBlockSynEncrypt.h'

# Examples and tests in examples.cpp

# An example of a program call:

unsigned char test1 = 0b10101011; //One character for testing
unsigned char result1; //Output result 'test1'
std::cout << "test1: " << std::bitset<8>(test1).to_string() << std::endl;
result1 = SPBlockSynEncrypt::PCrypt(key1, test1);
std::cout << "test1 encrypted: " << std::bitset<8>(result1).to_string() << std::endl;
result1 = SPBlockSynEncrypt::PCrypt(key1, result1);
std::cout << "test1 decrypted: " << std::bitset<8>(result1).to_string() << std::endl;
if (test1 == result1)
	std::cout << "test1 decrypted correctly !" << std::endl << std::endl;
 
The result of the program call:

test1: 10101011
test1 encrypted: 01010111
test1 decrypted: 10101011
test1 decrypted correctly !

