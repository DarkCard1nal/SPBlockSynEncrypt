#pragma once
#include <vector>
#include <bitset>

class SPBlockSynEncrypt
{
public:
	//A static method for encoding and decoding an S-block using the 'arr' and 'key' matrix table makes a replacement 
	//for 0-3 and 4-7 bits of 'block', returns the replaced block, the 'arr' table must contain a column with 
	//the number 'block' and a row with the number 'key', the 'arr' table itself consists of 4-bit unsigned char, 
	//otherwise an error may occur, it is important that the 'arr' table does not have duplicate elements in the rows, 
	//since duplicates cause information loss and make it impossible to restore data, to check the matrix for duplicates or 
	//elements larger than 4 bits, use the static method STableCheck(), also use the STableTransform() method to transform 
	//the table from encryption for decryption and vice versa.
	static unsigned char SCrypt(unsigned char arr[][16], const unsigned char key, const unsigned char block)
	{
		unsigned char resultBlock1 = block >> 4, resultBlock2 = (block & 0xF);

		resultBlock1 = arr[key][resultBlock1];
		resultBlock2 = arr[key][resultBlock2];

		resultBlock1 = resultBlock1 << 4;

		return resultBlock1 | resultBlock2;
	}

	//A static method for encoding and decoding an S-block using the matrix table 'arr' and 'key' replaces each 
	//character of the string 'blocks' using the SCrypt() method for one character, the table 'arr' must contain columns with 
	//numbers corresponding to each character of the string 'blocks' and a row with the number 'key', the table 'arr' itself 
	//consists of a 4-bit unsigned char, otherwise an error may occur, it is important that the 'arr' table does not have duplicate elements in the rows, 
	//since duplicates cause information loss and make it impossible to restore data, to check the matrix for duplicates or 
	//elements larger than 4 bits, use the static method STableCheck(), also use the STableTransform() method to transform 
	//the table from encryption for decryption and vice versa.
	static std::string SCrypt(unsigned char arr[][16], const unsigned char key, const std::string blocks)
	{
		std::string result = blocks;
		for (size_t i = 0; i < blocks.length(); i++)
		{
			result[i] = SCrypt(arr, key, blocks[i]);
		}

		return result;
	}

	//A static method for checking the 'arr' table for S-block encryption functions, 'rows' - the number of rows in the 'arr' 
	//table, the table 'arr' must have 16 columns (4 bits), the method checks the table for duplicate elements or 
	//elements larger than 4 bits in the rows, if no such elements are found, returns -1, otherwise returns 
	//the number of the first row in which a duplicate is found or elements larger than 4 bits in the rows 
	static __int16 STableCheck(unsigned char arr[][16], const unsigned char rows)
	{
		const unsigned char columns = 16;
		unsigned char i, j, z;
		for (i = 0; i < rows; i++)
		{
			for (j = 0; j < columns -1; j++)
			{
				if (arr[i][j] > 0b1111)
					return i;

				for (z = j +1; z < columns; z++)
				{
					if (arr[i][j] == arr[i][z])
						return i;
				}
			}
			if (arr[i][j] > 0b1111)
				return i;
		}

		return -1;
	}

	//A static method for transforming the 'arr' table of an S-block encryption for decryption and vice versa, 
	//'rows' - the number of rows in the 'arr' table, the table 'arr' must have 16 columns (4 bits), 
	//returns true if the 'arr' table was transformed, or false if the 'arr' table failed the duplicate check using 
	//the STableCheck() method, in which case the values of the 'arr' table are not changed.
	static bool STableTransform(unsigned char arr[][16], const unsigned char rows)
	{
		const unsigned char columns = 16;
		if (STableCheck(arr, rows) > -1)
			return false;

		std::vector<unsigned char> row(columns);
		unsigned char i, j;
		for (i = 0; i < rows; i++)
		{
			for (j = 0; j < columns; j++)
				row[j] = arr[i][j];

			for (j = 0; j < columns; j++)
				arr[i][row[j]] = j;
		}

		return true;
	}

	//A static method for encrypting and decrypting a 'block' character using 'key', returns an encrypted/decrypted 'block',
	//depending on the 'key', can return the 'block' unchanged
	static unsigned char PCrypt(const unsigned char key, const unsigned char block)
	{
		unsigned char nkey = key;
		if (key < 0b1111)
			nkey = ~nkey;

		unsigned char i, j, max = 8;
		std::bitset<8> result(block);
		bool tmp;

		for (i = 0; i < max; i++)
		{
			if (nkey & (1 << i))
			{
				for (j = max - 1; j > i; j--)
				{
					max--;
					if (nkey & (1 << i))
					{
						tmp = result[i];
						result[i] = result[j];
						result[j] = tmp;
						break;
					}
				}
			}
		}

		return static_cast<unsigned char>(result.to_ulong());
	}

	//A static method for encrypting and decrypting the string 'blocks' using the 'key' by calling the PCrypt() method 
	//for each character of the string, returns the encrypted/decrypted string 'blocks'.
	static std::string PCrypt(const unsigned char key, const std::string blocks)
	{
		std::string result = blocks;
		for (size_t i = 0; i < blocks.length(); i++)
		{
			result[i] = PCrypt(key, blocks[i]);
		}

		return result;
	}


};

