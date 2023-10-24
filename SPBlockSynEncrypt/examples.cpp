#include <iostream>
#include <string>
#include "SPBlockSynEncrypt.h"

int main()
{
	std::cout << "Start Test!" << std::endl << std::endl;

	//Binary table for S-block of methods with 2 bit keys and 4 bit block.
	unsigned char table1[4][16] =
	{  //0b0000  0b0001  0b0010  0b0011  0b0100  0b0101  0b0110  0b0111  0b1000  0b1001  0b1010  0b1011  0b1100  0b1101  0b1110  0b1111  - block (column)
		{0b0010, 0b0100, 0b0110, 0b0111, 0b1001, 0b0101, 0b1000, 0b1100, 0b0011, 0b0000, 0b1111, 0b1110, 0b0001, 0b1101, 0b1010, 0b1011}, //0b00 (0) - key (row)
		{0b0000, 0b0010, 0b1011, 0b1010, 0b0111, 0b0001, 0b1100, 0b1110, 0b0011, 0b0110, 0b1101, 0b1111, 0b0101, 0b1000, 0b1001, 0b0100}, //0b01 (1) - key (row)
		{0b0100, 0b1001, 0b0011, 0b1101, 0b0000, 0b1110, 0b0110, 0b1100, 0b1111, 0b0010, 0b1011, 0b0111, 0b1010, 0b1000, 0b0101, 0b0001}, //0b10 (2) - key (row)
		{0b1000, 0b0101, 0b1101, 0b0011, 0b1110, 0b1111, 0b1100, 0b0010, 0b1010, 0b0110, 0b0111, 0b1011, 0b1001, 0b0000, 0b0100, 0b0001}, //0b11 (3) - key (row)
	};

	//Dimensions of the matrix 'table1'.
	unsigned char rows1 = sizeof(table1) / sizeof(table1[0]); //Number of rows

	//Binary table for S-block of methods with 4 bit keys and 4 bit block.
	unsigned char table2[16][16] =
	{  //0b0000  0b0001  0b0010  0b0011  0b0100  0b0101  0b0110  0b0111  0b1000  0b1001  0b1010  0b1011  0b1100  0b1101  0b1110  0b1111  - block (column)
		{0b0010, 0b0100, 0b0110, 0b0111, 0b1001, 0b0101, 0b1000, 0b1100, 0b0011, 0b0000, 0b1111, 0b1110, 0b0001, 0b1101, 0b1010, 0b1011}, //0b0000 (0) - key (row)
		{0b0000, 0b0010, 0b1011, 0b1010, 0b0111, 0b0001, 0b1100, 0b1110, 0b0011, 0b0110, 0b1101, 0b1111, 0b0101, 0b1000, 0b1001, 0b0100}, //0b0001 (1) - key (row)
		{0b0100, 0b1001, 0b0011, 0b1101, 0b0000, 0b1110, 0b0110, 0b1100, 0b1111, 0b0010, 0b1011, 0b0111, 0b1010, 0b1000, 0b0101, 0b0001}, //0b0010 (2) - key (row)
		{0b1000, 0b0101, 0b1101, 0b0011, 0b1110, 0b1111, 0b1100, 0b0010, 0b1010, 0b0110, 0b0111, 0b1011, 0b1001, 0b0000, 0b0100, 0b0001}, //0b0011 (3) - key (row)
		{0b0100, 0b0011, 0b0010, 0b0001, 0b0111, 0b0110, 0b0000, 0b0101, 0b1000, 0b1111, 0b1100, 0b1101, 0b1010, 0b1110, 0b1011, 0b1001}, //0b0100 (4) - key (row)
		{0b0010, 0b0110, 0b1001, 0b0100, 0b0111, 0b0101, 0b0011, 0b1000, 0b1111, 0b1100, 0b0000, 0b1110, 0b0001, 0b1010, 0b1011, 0b1101}, //0b0101 (5) - key (row)
		{0b0010, 0b0000, 0b1010, 0b1011, 0b0111, 0b0001, 0b1110, 0b1100, 0b0100, 0b0101, 0b1111, 0b1101, 0b0011, 0b0110, 0b1001, 0b1000}, //0b0110 (6) - key (row)
		{0b0110, 0b1111, 0b1011, 0b1101, 0b0011, 0b0000, 0b0010, 0b1110, 0b1100, 0b1001, 0b0100, 0b1010, 0b1000, 0b0001, 0b0101, 0b0111}, //0b0111 (7) - key (row)
		{0b0000, 0b1101, 0b0101, 0b0110, 0b1111, 0b1010, 0b1110, 0b0011, 0b1001, 0b0010, 0b1000, 0b0001, 0b0111, 0b1100, 0b1011, 0b0100}, //0b1000 (8) - key (row)
		{0b0011, 0b1101, 0b0010, 0b1001, 0b1100, 0b1011, 0b0001, 0b1010, 0b1111, 0b1110, 0b1000, 0b0100, 0b0110, 0b0101, 0b0111, 0b0000}, //0b1001 (9) - key (row)
		{0b0011, 0b1101, 0b0010, 0b1001, 0b1100, 0b1011, 0b0001, 0b1010, 0b1111, 0b1110, 0b1000, 0b0100, 0b0110, 0b0101, 0b0111, 0b0000}, //0b1010 (10) - key (row)
		{0b0110, 0b1001, 0b0101, 0b1010, 0b1011, 0b0000, 0b1110, 0b1111, 0b0011, 0b1101, 0b1100, 0b0001, 0b0111, 0b0010, 0b1000, 0b0100}, //0b1011 (11) - key (row)
		{0b1001, 0b1000, 0b0000, 0b1010, 0b0111, 0b1100, 0b0001, 0b1011, 0b1101, 0b0010, 0b1110, 0b1111, 0b0011, 0b0110, 0b0101, 0b0100}, //0b1100 (12) - key (row)
		{0b0101, 0b0100, 0b0111, 0b0011, 0b0110, 0b1110, 0b1101, 0b0010, 0b1111, 0b1000, 0b1011, 0b1100, 0b0000, 0b0001, 0b1001, 0b1010}, //0b1101 (13) - key (row)
		{0b0011, 0b1010, 0b1110, 0b0000, 0b0101, 0b1001, 0b1101, 0b0110, 0b0001, 0b0100, 0b0111, 0b0010, 0b1011, 0b1000, 0b1111, 0b1100}, //0b1110 (14) - key (row)
		{0b0111, 0b1101, 0b1111, 0b1001, 0b1000, 0b0000, 0b0010, 0b1010, 0b0011, 0b0101, 0b0110, 0b0001, 0b1100, 0b1011, 0b1110, 0b0100}  //0b1111 (15) - key (row)
	};

	//Dimensions of the matrix 'table2'.
	unsigned char rows2 = sizeof(table2) / sizeof(table2[0]); //Number of rows

	//The same as 'table2' but in decimal form of filling the table.
	unsigned char table3[16][16] =
	{  //0b0000  0b0001  0b0010  0b0011  0b0100  0b0101  0b0110  0b0111  0b1000  0b1001  0b1010  0b1011  0b1100  0b1101  0b1110  0b1111  - block (column)
		{2, 4, 6, 7, 9, 5, 8, 12, 3, 0, 15, 14, 1, 13, 10, 11}, //0b0000 (0) - key (row)
		{0, 2, 11, 10, 7, 1, 12, 14, 3, 6, 13, 15, 5, 8, 9, 4}, //0b0001 (1) - key (row)
		{4, 9, 3, 13, 0, 14, 6, 12, 15, 2, 11, 7, 10, 8, 5, 1}, //0b0010 (2) - key (row)
		{8, 5, 13, 3, 14, 15, 12, 2, 10, 6, 7, 11, 9, 0, 4, 1}, //0b0011 (3) - key (row)
		{4, 3, 2, 1, 7, 6, 0, 5, 8, 15, 12, 13, 10, 14, 11, 9}, //0b0100 (4) - key (row)
		{2, 6, 9, 4, 7, 5, 3, 8, 15, 12, 0, 14, 1, 10, 11, 13}, //0b0101 (5) - key (row)
		{2, 0, 10, 11, 7, 1, 14, 12, 4, 5, 15, 13, 3, 6, 9, 8}, //0b0110 (6) - key (row)
		{6, 15, 11, 13, 3, 0, 2, 14, 12, 9, 4, 10, 8, 1, 5, 7}, //0b0111 (7) - key (row)
		{0, 13, 5, 6, 15, 10, 14, 3, 9, 2, 8, 1, 7, 12, 11, 4}, //0b1000 (8) - key (row)
		{3, 13, 2, 9, 12, 11, 1, 10, 15, 14, 8, 4, 6, 5, 7, 0}, //0b1001 (9) - key (row)
		{3, 13, 2, 9, 12, 11, 1, 10, 15, 14, 8, 4, 6, 5, 7, 0}, //0b1010 (10) - key (row)
		{6, 9, 5, 10, 11, 0, 14, 15, 3, 13, 12, 1, 7, 2, 8, 4}, //0b1011 (11) - key (row)
		{9, 8, 0, 10, 7, 12, 1, 11, 13, 2, 14, 15, 3, 6, 5, 4}, //0b1100 (12) - key (row)
		{5, 4, 7, 3, 6, 14, 13, 2, 15, 8, 11, 12, 0, 1, 9, 10}, //0b1101 (13) - key (row)
		{3, 10, 14, 0, 5, 9, 13, 6, 1, 4, 7, 2, 11, 8, 15, 12}, //0b1110 (14) - key (row)
		{7, 13, 15, 9, 8, 0, 2, 10, 3, 5, 6, 1, 12, 11, 14, 4}  //0b1111 (15) - key (row)
	};

	//Dimensions of the matrix 'table3'.
	unsigned char rows3 = sizeof(table3) / sizeof(table3[0]); //Number of rows

	__int16 check;

	unsigned char test1 = 0b10101011; //One character for testing
	unsigned char result1; //Output result 'test1'

	std::string test2 = "1234567890StriNG!"; //String for testing
	std::string result2(test2.length(), '\0'); //Output result 'test2'

	unsigned char key1 = 0b11; //Key 1
	unsigned char key2 = 0b1011; //Key 2


	//Checking 'table1' for correctness of filling (no duplicates and all elements are 4-bit).
	check = SPBlockSynEncrypt::STableCheck(table1, rows1);
	if (check < 0)
		std::cout << "table1 has passed the STableCheck() test!" << std::endl;
	else
		std::cout << "table1 failed the STableCheck() test !!! The problem is in the string: " << check << std::endl;
	
	//Checking 'table2' for correctness of filling (no duplicates and all elements are 4-bit).
	check = SPBlockSynEncrypt::STableCheck(table2, rows2);
	if (check < 0)
		std::cout << "table2 has passed the STableCheck() test!" << std::endl;
	else
		std::cout << "table2 failed the STableCheck() test !!! The problem is in the string: " << check << std::endl;

	//Checking 'table3' for correctness of filling (no duplicates and all elements are 4-bit).
	check = SPBlockSynEncrypt::STableCheck(table3, rows3);
	if (check < 0)
		std::cout << "table3 has passed the STableCheck() test!" << std::endl;
	else
		std::cout << "table3 failed the STableCheck() test !!! The problem is in the string: " << check << std::endl;


	std::cout << std::endl << "Test1 of the S-block 'table1' with 'key1'!" << std::endl;
	std::cout << "test1: " << std::bitset<8>(test1).to_string() << std::endl;
	result1 = SPBlockSynEncrypt::SCrypt(table1, key1, test1);
	std::cout << "test1 encrypted: " << std::bitset<8>(result1).to_string() << std::endl;
	//Transform a table for decryption
	if (SPBlockSynEncrypt::STableTransform(table1, rows1))
		std::cout << "table1 has been converted!" << std::endl;
	else
		std::cout << "table1 is not converted!!!" << std::endl;
	//Checking 'table1' for correctness of filling (no duplicates and all elements are 4-bit).
	check = SPBlockSynEncrypt::STableCheck(table1, rows1);
	if (check < 0)
		std::cout << "table1 has passed the STableCheck() test!" << std::endl;
	else
		std::cout << "table1 failed the STableCheck() test !!! The problem is in the string: " << check << std::endl;
	result1 = SPBlockSynEncrypt::SCrypt(table1, key1, result1);
	std::cout << "test1 decrypted: " << std::bitset<8>(result1).to_string() << std::endl;
	if (test1 == result1)
		std::cout << "test1 decrypted correctly !" << std::endl << std::endl;
	else
		std::cout << "test1 decrypted incorrectly !!!" << std::endl << std::endl;

	
	std::cout << "Test2 of the S-block 'table2' with 'key2'!" << std::endl;
	std::cout << "test2: " << test2 << std::endl;
	result2 = SPBlockSynEncrypt::SCrypt(table2, key2, test2);
	std::cout << "test2 encrypted: " << result2 << std::endl;
	//Transform a table for decryption
	if (SPBlockSynEncrypt::STableTransform(table2, rows2))
		std::cout << "table2 has been converted!" << std::endl;
	else
		std::cout << "table2 is not converted!!!" << std::endl;
	//Checking 'table2' for correctness of filling (no duplicates and all elements are 4-bit).
	check = SPBlockSynEncrypt::STableCheck(table2, rows2);
	if (check < 0)
		std::cout << "table2 has passed the STableCheck() test!" << std::endl;
	else
		std::cout << "table2 failed the STableCheck() test !!! The problem is in the string: " << check << std::endl;
	result2 = SPBlockSynEncrypt::SCrypt(table2, key2, result2);
	std::cout << "test2 decrypted: " << result2 << std::endl;
	if (test2 == result2)
		std::cout << "test2 decrypted correctly !" << std::endl << std::endl;
	else
		std::cout << "test2 decrypted incorrectly !!!" << std::endl << std::endl;


	std::cout << "Test2 of the S-block 'table3' with 'key2'!" << std::endl;
	std::cout << "test2: " << test2 << std::endl;
	result2 = SPBlockSynEncrypt::SCrypt(table3, key2, test2);
	std::cout << "test2 encrypted: " << result2 << std::endl;
	//Transform a table for decryption
	if (SPBlockSynEncrypt::STableTransform(table3, rows2))
		std::cout << "table3 has been converted!" << std::endl;
	else
		std::cout << "table3 is not converted!!!" << std::endl;
	//Checking 'table3' for correctness of filling (no duplicates and all elements are 4-bit).
	check = SPBlockSynEncrypt::STableCheck(table3, rows2);
	if (check < 0)
		std::cout << "table3 has passed the STableCheck() test!" << std::endl;
	else
		std::cout << "table3 failed the STableCheck() test !!! The problem is in the string: " << check << std::endl;
	result2 = SPBlockSynEncrypt::SCrypt(table3, key2, result2);
	std::cout << "test2 decrypted: " << result2 << std::endl;
	if (test2 == result2)
		std::cout << "test2 decrypted correctly !" << std::endl << std::endl;
	else
		std::cout << "test2 decrypted incorrectly !!!" << std::endl << std::endl;
	
	std::cout << std::endl << "Test1 of the P-block with 'key1'!" << std::endl;
	std::cout << "test1: " << std::bitset<8>(test1).to_string() << std::endl;
	result1 = SPBlockSynEncrypt::PCrypt(key1, test1);
	std::cout << "test1 encrypted: " << std::bitset<8>(result1).to_string() << std::endl;
	result1 = SPBlockSynEncrypt::PCrypt(key1, result1);
	std::cout << "test1 decrypted: " << std::bitset<8>(result1).to_string() << std::endl;
	if (test1 == result1)
		std::cout << "test1 decrypted correctly !" << std::endl << std::endl;
	else
		std::cout << "test1 decrypted incorrectly !!!" << std::endl << std::endl;

	std::cout << "Test2 of the P-block with 'key2'!" << std::endl;
	std::cout << "test2: " << test2 << std::endl;
	result2 = SPBlockSynEncrypt::PCrypt(key2, test2);
	std::cout << "test2 encrypted: " << result2 << std::endl;
	result2 = SPBlockSynEncrypt::PCrypt(key2, result2);
	std::cout << "test2 decrypted: " << result2 << std::endl;
	if (test2 == result2)
		std::cout << "test2 decrypted correctly !" << std::endl << std::endl;
	else
		std::cout << "test2 decrypted incorrectly !!!" << std::endl;


	std::cout << std::endl << "End Test!" << std::endl;
}
