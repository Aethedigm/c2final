// --------------------------------------------------------------------------------
// Stephen C Sumpter
// 14/8/2022
// C programming 2
// Final
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include"CSuperString.h"
#include<iostream>

// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
void MuahahahTest1();
void MuahahahTest2();

// --------------------------------------------------------------------------------
// Name: Main
// Abstract: Main entry point - Used to test CSuperString features
// --------------------------------------------------------------------------------
int main() {

	CSuperString ssString;
	CSuperString ssString2;
	CSuperString ssString3(ssString2);
	CSuperString ssString4;
	CSuperString ssString5(5.2f);
	CSuperString ssString6(9.9);
	CSuperString ssString7(12342);
	CSuperString ssString8('a');
	CSuperString ssString9(true);
	CSuperString ssString10("This was a triumph");
	CSuperString ssString11("  trim test  ");

	ssString = "Hello folks";
	ssString2 = 'A';
	ssString3 = ssString;

	ssString += "!";
	ssString += '!';
	ssString += ssString2;
	
	ssString4 = ssString3 + ssString2;
	ssString7 + "hi";
	"hello" + ssString6;

	int firstIndex = ssString.FindFirstIndexOf('l');
	int secondIndex = ssString.FindFirstIndexOf('o', 5);
	int thirdIndex = ssString.FindLastIndexOf('k');

	ssString11 = ssString11.Trim();

	std::cout << ssString.ToString() << std::endl;
	std::cout << ssString.ToLowerCase() << std::endl;
	std::cout << ssString3.ToUpperCase() << std::endl;
	std::cout << ssString5.ToString() << std::endl;
	std::cout << ssString6.ToString() << std::endl;
	std::cout << ssString7.ToString() << std::endl;
	std::cout << ssString8.ToString() << std::endl;
	std::cout << ssString9.ToString() << std::endl;
	std::cout << ssString10.ToString() << std::endl;
	std::cout << ssString.Reverse() << std::endl;
	std::cout << ssString11 << std::endl;
	const char* test = ssString11.Insert(" hi ", 3);
	std::cout << test << std::endl;
	const char* test2 = ssString11.Insert(' ', 1);
	std::cout << test2 << std::endl;

	std::cout << "First index of l: " << firstIndex << std::endl;
	std::cout << "First index of o, after index 5: " << secondIndex << std::endl;
	std::cout << "First last index of k: " << thirdIndex << std::endl;
	std::cout << std::boolalpha << ssString7.ToBoolean() << std:: endl;
	std::cout << (ssString < ssString2) << std::endl;
	std::cout << (ssString2 < ssString) << std::endl;
	std::cout << (ssString3 < "hi             ") << std::endl;

	CSuperString ssFloat(1.212331f);
	CSuperString ssInt(45);
	CSuperString ssBool(true);

	std::cout << ssFloat.ToFloat() << std::endl;
	std::cout << ssInt.ToInteger() << std::endl;
	std::cout << ssBool.ToBoolean() << std::endl;


	MuahahahTest1();
	MuahahahTest2();

	std::cout << ssString << std::endl;
	ssString = ssString;
	std::cout << ssString << std::endl;
	std::cout << "Self-assigned without the world exploding." << std::endl;

	CSuperString ssNew("12345654321");

	std::cout << ssNew.Left(4) << std::endl;
	std::cout << ssNew.Right(8) << std::endl;

	return 0;
}

// --------------------------------------------------------------------------------
// Name: MuahahahTest1
// Abstract: A very simple test.
// --------------------------------------------------------------------------------
void MuahahahTest1() {
	CSuperString ssTest;
	std::cout << "Muahahah Test #1:" << ssTest << std::endl;
}

// --------------------------------------------------------------------------------
// Name: MuahahahTest2
// Abstact: A very simple test.
// --------------------------------------------------------------------------------
void MuahahahTest2() {
	CSuperString ssTest = "I Love Star Wars and I Love Star Trek";

	ssTest = ssTest.Replace("Love", "Really Love Love");

	std::cout << "Muahahah Test #2:" << ssTest << std::endl;
}
