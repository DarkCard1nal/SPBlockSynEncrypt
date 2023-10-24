# SPBlockSynEncrypt
C++ Module (library) for using and studying S-blocks and P-blocks for symmetric encryption algorithms.
____
### Task description Cryptography for Developers (Distributed Lab):
>>>> Реалізуйте свої власні функції для прямого і зворотного перетворення за алгоритмом S-блоку, а також за алгоритмом P-блоку. Мову програмування для реалізації оберіть на власний розсуд. Таблицю констант для реалізації S-блоку оберіть з рекомендованих, що доступні публічно або сгенеруйте самостійно. Формулу перестановки для реалізації P-блоку оберіть на власний розсуд.
Для S-блоку алгоритмом зворотного перетворення може бути той самий алгоритм, але з застосуванням функції обчислення зворотної таблиці констант. Фактично така функція має приймати таблицю констант для прямого перетворення і повертати таблицю констано для зворотного перетворення.
Важливо написати тести для власної реалізації алгоритмів S-блоку та P-блоку, з метою переконатися в правильності функціонування. Для певного набору даних, якщо виконати послідовно пряме та зворотне перетворення, то маємо отримати початковий набір даних.
Ваш репозиторій на GitHub має містити файли з прокоментованим вихідним кодом та README.md файл з описом завдання, інструкцією щодо запуска коду, приклад визову програми, приклад результату виконання програми. За потреби можете додати перелік залежностей вашої програми та зразки скріншотів.

>>> Вимоги до S-блоку наступні:
>>> * розмір вхідних даних 8 бітів
>>> * розмір вихідних даних 8 бітів
>>> * вхідний блок даних розбивається на дві тетради по 4 біти

>>> Вимоги до P-блоку наступні:
>>> * розмір вхідних даних 8 бітів
>>> * розмір вихідних даних 8 бітів

____
# installation:

`#include "SPBlockSynEncrypt.h"`

# Opportunities:

Class Methods:

`static unsigned char SCrypt(unsigned char arr[][16], const unsigned char key, const unsigned char block)` - a method of encrypting/decrypting a character with an S-block using a table and a key.

`static std::string SCrypt(unsigned char arr[][16], const unsigned char key, const std::string blocks)` - a method of encrypting/decrypting a string with an S-block using a table and a key, using the SCrypt() method for one character.

>>> //A static method for encoding and decoding an S-block using the 'arr' and 'key' matrix table makes a replacement 
//for 0-3 and 4-7 bits of 'block', returns the replaced block, the 'arr' table must contain a column with 
//the number 'block' and a row with the number 'key', the 'arr' table itself consists of 4-bit unsigned char, 
//otherwise an error may occur, it is important that the 'arr' table does not have duplicate elements in the rows, 
//since duplicates cause information loss and make it impossible to restore data, to check the matrix for duplicates or 
//elements larger than 4 bits, use the static method STableCheck(), also use the STableTransform() method to transform 
//the table from encryption for decryption and vice versa.

`static __int16 STableCheck(unsigned char arr[][16], const unsigned char rows)` - method for checking the table for 'correctness'.

>>> //A static method for checking the 'arr' table for S-block encryption functions, 'rows' - the number of rows in the 'arr' 
//table, the table 'arr' must have 16 columns (4 bits), the method checks the table for duplicate elements or 
//elements larger than 4 bits in the rows, if no such elements are found, returns -1, otherwise returns 
//the number of the first row in which a duplicate is found or elements larger than 4 bits in the rows

`static bool STableTransform(unsigned char arr[][16], const unsigned char rows)` - a method for converting a table from encryption to decryption and vice versa.

>>> //A static method for transforming the 'arr' table of an S-block encryption for decryption and vice versa, 
//'rows' - the number of rows in the 'arr' table, the table 'arr' must have 16 columns (4 bits), 
//returns true if the 'arr' table was transformed, or false if the 'arr' table failed the duplicate check using 
//the STableCheck() method, in which case the values of the 'arr' table are not changed.

`static unsigned char PCrypt(const unsigned char key, const unsigned char block)` - a method of encrypting/decrypting a character with an P-block using a key.

`static std::string PCrypt(const unsigned char key, const std::string blocks)` - - a method of encrypting/decrypting a string with an P-block using a key, using the PCrypt() method for one character .

>>> //A static method for encrypting and decrypting a 'block' character using 'key', returns an encrypted/decrypted 'block',
//depending on the 'key', can return the 'block' unchanged

#### More information about algorithms and methods in the comments of 'SPBlockSynEncrypt.h'
____
# Examples and tests in examples.cpp

## An example of a program call:
```c++
unsigned char test1 = 0b10101011; //One character for testing
unsigned char result1; //Output result 'test1'

std::cout << "test1: " << std::bitset<8>(test1).to_string() << std::endl;

result1 = SPBlockSynEncrypt::PCrypt(key1, test1);
std::cout << "test1 encrypted: " << std::bitset<8>(result1).to_string() << std::endl;

result1 = SPBlockSynEncrypt::PCrypt(key1, result1);
std::cout << "test1 decrypted: " << std::bitset<8>(result1).to_string() << std::endl;

if (test1 == result1)
	std::cout << "test1 decrypted correctly !" << std::endl << std::endl;
```
## The result of the program call:
```c++
test1: 10101011
test1 encrypted: 01010111
test1 decrypted: 10101011
test1 decrypted correctly !
```
