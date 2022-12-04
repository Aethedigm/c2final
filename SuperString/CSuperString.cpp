// --------------------------------------------------------------------------------
// Stephen C Sumpter
// 14/8/2022
// C programming 2
// Final
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CSuperString.h"

// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Constructs default object
// --------------------------------------------------------------------------------
CSuperString::CSuperString() {// #1
	m_pstrSuperString = new char[26];
	strcpy(m_pstrSuperString, " This is not a challenge.");
}



// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Constructs default object
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const char* pstrStringToCopy) {// #2
	m_pstrSuperString = new char[strlen(pstrStringToCopy) + 1];
	strcpy(m_pstrSuperString, pstrStringToCopy);
}



// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Constructs default object
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const bool blnBooleanToCopy) {// #3
	m_pstrSuperString = new char[7];

	if (blnBooleanToCopy) {
		strcpy(m_pstrSuperString, "true");
	}
	else {
		strcpy(m_pstrSuperString, "false");
	}
}



// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Constructs default object
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const char chrLetterToCopy) {
	m_pstrSuperString = new char[2];
	sprintf(m_pstrSuperString, "%c", chrLetterToCopy);
}



// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Constructs default object
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const short shtShortToCopy) {
	m_pstrSuperString = new char[7];
	sprintf(m_pstrSuperString, "%d", shtShortToCopy);
}



// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Constructs default object
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const int intIntegerToCopy) {
	m_pstrSuperString = new char[12];
	sprintf(m_pstrSuperString, "%d", intIntegerToCopy);
}



// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Constructs default object
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const long lngLongToCopy) {
	m_pstrSuperString = new char[12];
	sprintf(m_pstrSuperString, "%d", lngLongToCopy);
}



// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Constructs default object
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const float sngFloatToCopy) {
	m_pstrSuperString = new char[32];
	snprintf(m_pstrSuperString, 31, "%f", sngFloatToCopy);
}



// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Constructs default object
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const double dblDoubleToCopy) {
	m_pstrSuperString = new char[32];
	snprintf(m_pstrSuperString, 31, "%f", dblDoubleToCopy);
}



// --------------------------------------------------------------------------------
// Name: Copy Constructor
// Abstract: Constructs default object
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const CSuperString& ssStringToCopy) {
	ClassCopy(ssStringToCopy);
}



// --------------------------------------------------------------------------------
// Name: assignment op
// Abstract: configures assignment op
// --------------------------------------------------------------------------------
void CSuperString::operator=(const CSuperString& ssStringToCopy) {
	ClassCopy(ssStringToCopy);
}



// --------------------------------------------------------------------------------
// Name: Class Copy
// Abstract: Provides a simple deep copy
// --------------------------------------------------------------------------------
void CSuperString::ClassCopy(const CSuperString& ssStringToCopy) {
	char* strNew = new char[strlen(ssStringToCopy.m_pstrSuperString) + 1];
	strcpy(strNew, ssStringToCopy.m_pstrSuperString);

	delete[] m_pstrSuperString;
	m_pstrSuperString = strNew;
}



// --------------------------------------------------------------------------------
// Name: Destructor
// Abstract: Deletes created memory
// --------------------------------------------------------------------------------
CSuperString::~CSuperString() {
	delete[] m_pstrSuperString;
}



// --------------------------------------------------------------------------------
// Name: Length
// Abstract: gets the length of the string
// --------------------------------------------------------------------------------
int CSuperString::Length() const {
	return strlen(m_pstrSuperString);
}



// --------------------------------------------------------------------------------
// Name: assignment op
// Abstract: replaces m_pstrSuperString with provided string
// --------------------------------------------------------------------------------
void CSuperString::operator=(const char* pstrStringToCopy) {
	delete[] m_pstrSuperString;
	m_pstrSuperString = new char[strlen(pstrStringToCopy) + 1];
	strcpy(m_pstrSuperString, pstrStringToCopy);
}



// --------------------------------------------------------------------------------
// Name: assignment op
// Abstract: Assings a single char to m_pstrSuperString
// --------------------------------------------------------------------------------
void CSuperString::operator=(const char chrLetterToCopy) {
	delete[] m_pstrSuperString;
	m_pstrSuperString = new char[2];
	sprintf(m_pstrSuperString, "%c", chrLetterToCopy);
}



// --------------------------------------------------------------------------------
// Name: addition assignment op
// Abstract: Adds provided string to m_pstrSuperString
// --------------------------------------------------------------------------------
void CSuperString::operator+=(const char* pstrStringToAppend) {
	char* strNew = new char[strlen(m_pstrSuperString) + strlen(pstrStringToAppend) + 1];
	sprintf(strNew, "%s%s", m_pstrSuperString, pstrStringToAppend);

	delete[] m_pstrSuperString;
	m_pstrSuperString = strNew;
}



// --------------------------------------------------------------------------------
// Name: addition assignment op
// Abstract: Adds provided string to m_pstrSuperString
// --------------------------------------------------------------------------------
void CSuperString::operator+=(const char chrCharacterToAppend) {
	char* strNew = new char[strlen(m_pstrSuperString) + 2];
	sprintf(strNew, "%s%c", m_pstrSuperString, chrCharacterToAppend);

	delete[] m_pstrSuperString;
	m_pstrSuperString = strNew;
}



// --------------------------------------------------------------------------------
// Name: addition assignment op
// Abstract: Adds provided string to m_pstrSuperString
// --------------------------------------------------------------------------------
void CSuperString::operator+=(const CSuperString& ssStringToAppend) {
	char* strNew = new char[strlen(m_pstrSuperString) + strlen(ssStringToAppend.m_pstrSuperString) + 1];
	sprintf(strNew, "%s%s", m_pstrSuperString, ssStringToAppend.m_pstrSuperString);

	delete[] m_pstrSuperString;
	m_pstrSuperString = strNew;
}



// --------------------------------------------------------------------------------
// Name: addition op
// Abstract: Adds two strings together and returns them
// --------------------------------------------------------------------------------
CSuperString operator+(const CSuperString& ssLeft, const CSuperString& ssRight) {
	char* strNew = new char[ssLeft.Length() + ssRight.Length() + 1];
	return CSuperString(strNew);
}



// --------------------------------------------------------------------------------
// Name: addition op
// Abstract: Adds two strings together and returms them
// --------------------------------------------------------------------------------
CSuperString operator+(const char* pstrLeftSide, const CSuperString& ssRightString) {
	char* strNew = new char[strlen(pstrLeftSide) + ssRightString.Length() + 1];
	return CSuperString(strNew);
}



// --------------------------------------------------------------------------------
// Name: addition op
// Abstract: Adds two strings together and returns them
// --------------------------------------------------------------------------------
CSuperString operator+(const CSuperString& ssLeftString, const char* pstrRightSide) {
	char* strNew = new char[ssLeftString.Length() + strlen(pstrRightSide) + 1];
	return CSuperString(strNew);
}



// --------------------------------------------------------------------------------
// Name: Find First Index Of
// Abstract: Find First Index of character
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char chrLetterToFind) {
	int intIndex = 0;

	for (; intIndex < strlen(m_pstrSuperString); intIndex++) {
		if (m_pstrSuperString[intIndex] == chrLetterToFind) {
			return intIndex;
		}
	}

	return -1;
}



// --------------------------------------------------------------------------------
// Name: Find First Index Of
// Abstract: Find First Index of provided character after a certain point
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex) {
	int intIndex = lngStartIndex;
	for (; m_pstrSuperString[intIndex] != '\0'; intIndex++) {
		if (m_pstrSuperString[intIndex] == chrLetterToFind) {
			return intIndex;
		}
	}

	return -1;
}



// --------------------------------------------------------------------------------
// Name: Find Last Index Of 
// Abstract: Finds last index of provided character
// --------------------------------------------------------------------------------
long CSuperString::FindLastIndexOf(const char chrLetterToFind) {
	int intLength = strlen(m_pstrSuperString);
	int intIndex = intLength;

	for (; intIndex > 0; intIndex--) {
		if (m_pstrSuperString[intIndex] == chrLetterToFind) {
			return intIndex;
		}
	}

	return -1;
}



// --------------------------------------------------------------------------------
// Name: Find First Index Of
// Abstract: Find's the first index of a string
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind) {
	return FindFirstIndexOf(pstrSubStringToFind, 0);
}



// --------------------------------------------------------------------------------
// Name: Find First Index Of
// Abstract: Finds the first index of a string after the beginning point provided
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind, long lngStartIndex) {
	int intIndex = lngStartIndex;
	int intSubIndex = 0;
	int intStartIndex = 0;

	for (; intIndex < strlen(m_pstrSuperString); intIndex++) {
		if (m_pstrSuperString[intIndex] == pstrSubStringToFind[intSubIndex]) {
			intSubIndex++;
			if (intSubIndex >= strlen(pstrSubStringToFind)) {
				return intStartIndex + 1;
			}
		}
		else {
			intSubIndex = 0;
			intStartIndex = intIndex;
		}
	}

	return -1;
}



// --------------------------------------------------------------------------------
// Name: Find Last Index Of
// Abstract: Finds the Last Index of a string
// --------------------------------------------------------------------------------
long CSuperString::FindLastIndexOf(const char* pstrSubStringToFind){
	std::vector<int> instances = FindAllIndexesOf(pstrSubStringToFind);

	for (auto it = instances.rbegin(); it != instances.rend(); it++) {
		return *it;
	}

	return -1;
}



// --------------------------------------------------------------------------------
// Name: To Upper Case
// Abstract: Returns m_pstrSuperString as an uppercase string
// --------------------------------------------------------------------------------
const char* CSuperString::ToUpperCase() {
	char* strResult = new char[strlen(m_pstrSuperString) + 1];

	strcpy(strResult, m_pstrSuperString);

	for (int intIndex = 0; intIndex < strlen(strResult); intIndex++) {
		if (strResult[intIndex] >= 'a' && strResult[intIndex] <= 'z') {
			strResult[intIndex] -= ' ';
		}
	}

	return strResult;
}



// --------------------------------------------------------------------------------
// Name: To Lower Case
// Abstract: returns m_pstrSuperString as a lowercase string
// --------------------------------------------------------------------------------
const char* CSuperString::ToLowerCase() {
	char* strResult = new char[strlen(m_pstrSuperString)];

	strcpy(strResult, m_pstrSuperString);

	for (int intIndex = 0; intIndex < strlen(strResult); intIndex++) {
		if (strResult[intIndex] >= 'A' && strResult[intIndex] <= 'Z') {
			strResult[intIndex] += ' ';
		}
	}

	return strResult;
}



// --------------------------------------------------------------------------------
// Name: Trim Left
// Abstract: Trims all spaces on left side
// --------------------------------------------------------------------------------
const char* CSuperString::TrimLeft() {
	int intSpaceCount = 0;

	for (int intIndex = 0; m_pstrSuperString[intIndex] == ' '; intIndex++) {
		if (m_pstrSuperString[intIndex] != ' ') break;
		intSpaceCount++;
	}

	return Substring(intSpaceCount, strlen(m_pstrSuperString) - intSpaceCount);
}



// --------------------------------------------------------------------------------
// Name: Trim Right
// Abstract: Trims all spaces on right side
// --------------------------------------------------------------------------------
const char* CSuperString::TrimRight() {
	int intSpaceCount = 0;
	for (int intIndex = strlen(m_pstrSuperString) - 1; intIndex > 0; intIndex--) {
		if (m_pstrSuperString[intIndex] != ' ') break;
		intSpaceCount++;
	}

	return Substring(0, strlen(m_pstrSuperString) - intSpaceCount);
}



// --------------------------------------------------------------------------------
// Name: Trim
// Abstract: Calls Trim Left and Trim Right
// --------------------------------------------------------------------------------
const char* CSuperString::Trim() {
	CSuperString left = CSuperString(TrimLeft());
	CSuperString right = left.TrimRight();

	return right.Substring(0, right.Length() + 1);
}



// --------------------------------------------------------------------------------
// Name: Reverse
// Abstract: Reverses m_pstrSuperString, returns new string
// --------------------------------------------------------------------------------
const char* CSuperString::Reverse() {
	int intIndex = 0;
	int intOther = strlen(m_pstrSuperString)-1;

	char* strNew = new char[strlen(m_pstrSuperString) + 1];
	strcpy(strNew, m_pstrSuperString);
	while (intIndex < intOther) {
		char temp = strNew[intOther];
		strNew[intOther] = strNew[intIndex];
		strNew[intIndex] = temp;
		
		intIndex++;
		intOther--;
	}

	return strNew;
}



// --------------------------------------------------------------------------------
// Name: index op
// Abstract: returns the character at the index
// --------------------------------------------------------------------------------
char& CSuperString::operator[](long lngIndex) {
	return m_pstrSuperString[lngIndex];
}



// --------------------------------------------------------------------------------
// Name: index op
// Abstract: returns the character at the index
// --------------------------------------------------------------------------------
const char& CSuperString::operator[](long lngIndex) const {
	return m_pstrSuperString[lngIndex];
}



// --------------------------------------------------------------------------------
// Name: To String
// Abstract: Now that the strings can be directly bit shifted, this is useless
// --------------------------------------------------------------------------------
const char* CSuperString::ToString() {
	return m_pstrSuperString;
}



// --------------------------------------------------------------------------------
// Name: Left
// Abstract: I don't know what this is supposed to do
// --------------------------------------------------------------------------------
const char* CSuperString::Left(long lngCharactersToCopy) {
	char* strNew = new char[lngCharactersToCopy + 1];
	int intIndex;

	for (intIndex = 0; intIndex < lngCharactersToCopy; intIndex++) {
		strNew[intIndex] = m_pstrSuperString[intIndex];
	}
	strNew[intIndex] = '\0';

	return strNew;
}



// --------------------------------------------------------------------------------
// Name: Right
// Abstract: I don't know what this is supposed to do
// --------------------------------------------------------------------------------
const char* CSuperString::Right(long lngCharactersToCopy) {
	char* strNew = new char[lngCharactersToCopy+1];
	
	strNew[lngCharactersToCopy] = '\0';
	int intIndex;

	int intOffset = strlen(m_pstrSuperString) - lngCharactersToCopy;

	for (intIndex = intOffset; intIndex < strlen(strNew) + intOffset; intIndex++) {
		strNew[intIndex - intOffset] = m_pstrSuperString[intIndex];
	}
	strNew[intIndex] = '\0';

	int whatthis = strlen(strNew);
	return strNew;
}



// --------------------------------------------------------------------------------
// Name: Substring
// Abstract: returns a substring
// --------------------------------------------------------------------------------
const char* CSuperString::Substring(long lngStart, long lngSubStringLength) {
	char* strNew = new char[lngSubStringLength + 1];
	int intIndex;

	for (intIndex = 0; intIndex < lngSubStringLength; intIndex++) {
		strNew[intIndex] = m_pstrSuperString[intIndex + lngStart];
	}
	strNew[intIndex] = '\0';

	return strNew;
}



// --------------------------------------------------------------------------------
// Name: Replace
// Abstract: Replace all instances of chrLetterToFind with chrReplace
// --------------------------------------------------------------------------------
const char* CSuperString::Replace(char chrLetterToFind, char chrReplace) {
	for (int intIndex = 0; intIndex < strlen(m_pstrSuperString); intIndex++) {
		if (m_pstrSuperString[intIndex] == chrLetterToFind)
			m_pstrSuperString[intIndex] = chrReplace;
	}

	return m_pstrSuperString;
}



// --------------------------------------------------------------------------------
// Name: Replace
// Abstract: Replace all instances of pstrFind with pstrReplace
// --------------------------------------------------------------------------------
const char* CSuperString::Replace(const char* pstrFind, const char* pstrReplace) {
	std::vector<int> instances = FindAllIndexesOf(pstrFind);
	
	char* strNew = m_pstrSuperString;

	for (auto it = instances.rbegin(); it != instances.rend(); it++) {
		strNew = ReplaceIndexRange(strNew, *it, *it + strlen(pstrFind), pstrReplace);
	}

	return strNew;
}



// --------------------------------------------------------------------------------
// Name: Replace Index Range
// Abstract: Replaces index ranges with new substrings
// --------------------------------------------------------------------------------
char* CSuperString::ReplaceIndexRange(char* strIn, int intStart, int intEnd, const char* pstrFill) {
	char* strNew = new char[strlen(strIn) + (intEnd - intStart) + strlen(pstrFill) + 1];
	int intAdjust = strlen(pstrFill);
	int intIndex;

	// Copy to start
	for (intIndex = 0; intIndex < intStart; intIndex++) {
		strNew[intIndex] = strIn[intIndex];
	}

	// Copy replace
	for (intIndex = intStart; intIndex < intAdjust + intStart; intIndex++) {
		strNew[intIndex] = pstrFill[intIndex - intStart];
	}

	// Copy rest
	for (intIndex = intEnd; intIndex < strlen(strIn); intIndex++) {
		strNew[intIndex + (strlen(pstrFill) - intEnd) + intStart] = strIn[intIndex];
	}

	strNew[intIndex + (strlen(pstrFill) - intEnd) + intStart] = '\0';

	return strNew;
}



// --------------------------------------------------------------------------------
// Name: Find All Indexes Of
// Abstract: Finds all indexes of the given sub string and itemizes them
// --------------------------------------------------------------------------------
std::vector<int> CSuperString::FindAllIndexesOf(const char* pstrFind) {
	int adjust = strlen(pstrFind);
	std::vector<int> vals;

	int intIndex2 = 0;
	for (int intIndex = 0; intIndex < strlen(m_pstrSuperString); intIndex++) {
		if (m_pstrSuperString[intIndex] == pstrFind[intIndex2]) {
			intIndex2++;
			if (intIndex2 >= adjust) {
				vals.push_back(intIndex - adjust + 1);
				intIndex2 = 0;
			}
		}
		else {
			intIndex2 = 0;
		}
	}

	return vals;
}



// --------------------------------------------------------------------------------
// Name: Insert
// Abstract: Inserts character into m_pstrSuperString, returns new string
// --------------------------------------------------------------------------------
const char* CSuperString::Insert(const char chrLetterToInsert, long lngIndex) {
	lngIndex = lngIndex < strlen(m_pstrSuperString) ? lngIndex : strlen(m_pstrSuperString) - 1;

	char* strNew = new char[strlen(m_pstrSuperString) + 2];

	int intIndex = 0;
	int intModifier = 0;

	while (intIndex < strlen(m_pstrSuperString)) {
		if (intIndex == lngIndex) {
			intModifier = 1;
		}
		strNew[intIndex + intModifier] = m_pstrSuperString[intIndex];
		intIndex++;
	}

	strNew[lngIndex] = chrLetterToInsert;
	strNew[intIndex + intModifier] = '\0';

	return strNew;
}



// --------------------------------------------------------------------------------
// Name: Insert
// Abstract: Inserts string into m_pstrSuperString, returns new string combo
// --------------------------------------------------------------------------------
const char* CSuperString::Insert(const char* pstrSubString, long lngIndex) {
	int intIndex;
	int intModifier = 0;
	char* strNew = new char[strlen(m_pstrSuperString) + strlen(pstrSubString) + 1];

	for (intIndex = 0; intIndex < strlen(m_pstrSuperString); intIndex++) {
		strNew[intIndex + intModifier] = m_pstrSuperString[intIndex];
		if (intIndex == lngIndex) {
			intModifier += strlen(pstrSubString);
		}
	}
	strNew[intIndex + intModifier] = '\0';

	for (intIndex = 0; intIndex < strlen(pstrSubString); intIndex++) {
		strNew[intIndex + lngIndex + 1] = pstrSubString[intIndex];
	}

	return strNew;
}



// --------------------------------------------------------------------------------
// Name: To Short
// Abstract: Attempts to convert the value in m_pstrSuperString into a short
// --------------------------------------------------------------------------------
short CSuperString::ToShort() {
	return ToInteger();
}



// --------------------------------------------------------------------------------
// Name: To Integer
// Abstract: Attempts to convert the value in m_pstrSuperString into an integer
// --------------------------------------------------------------------------------
int CSuperString::ToInteger() {
	return atoi(m_pstrSuperString);
}



// --------------------------------------------------------------------------------
// Name: To Long
// Abstract: Attempts to convert the value in m_pstrSuperString into a long
// --------------------------------------------------------------------------------
long CSuperString::ToLong() {
	return ToInteger();
}



// --------------------------------------------------------------------------------
// Name: To Float
// Abstract: Attempts to convert the value in m_pstrSuperString into a float
// --------------------------------------------------------------------------------
float CSuperString::ToFloat() {
	return atof(m_pstrSuperString);
}



// --------------------------------------------------------------------------------
// Name: To Double
// Abstract: Attempts to convert the value in m_pstrSuperString into a double
// --------------------------------------------------------------------------------
double CSuperString::ToDouble() {
	return ToFloat();
}



// --------------------------------------------------------------------------------
// Name: To Boolean
// Abstract: Attempt to convert the value in m_pstrSuperString into a bool value
// --------------------------------------------------------------------------------
bool CSuperString::ToBoolean() {
	if (*this == "true") return true;
	return false;
}



// --------------------------------------------------------------------------------
// Name: Is Equals
// Abstract: Compares underlying strings for the length of the shorter one
// --------------------------------------------------------------------------------
bool CSuperString::IsEquals(const char* ssCompare) {
	int intLength = strlen(ssCompare);

	intLength = strlen(m_pstrSuperString) < intLength ? strlen(m_pstrSuperString) : intLength;

	for (int intIndex = 0; intIndex < intLength; intIndex++) {
		if (m_pstrSuperString[intIndex] != ssCompare[intIndex]) return false;
	}

	return true;
}



// --------------------------------------------------------------------------------
// Name: comparison operator
// Abstract: compares strings
// --------------------------------------------------------------------------------
bool CSuperString::operator==(CSuperString& ssCompare) {
	return IsEquals(ssCompare.m_pstrSuperString);
}



// --------------------------------------------------------------------------------
// Name: comparison operator
// Abstract: compares strings
// --------------------------------------------------------------------------------
bool CSuperString::operator==(const char* ssCompare) {
	return IsEquals(ssCompare);
}



// --------------------------------------------------------------------------------
// Name: Less than operator
// Abstract: checks if this object is less in length - undefined behaviour 
// --------------------------------------------------------------------------------
bool CSuperString::operator<(CSuperString& ssCompare) {
	return strlen(m_pstrSuperString) < strlen(ssCompare.m_pstrSuperString);
}



// --------------------------------------------------------------------------------
// Name: Less than operator
// Abstract: checks if this object is less in length - undefined behaviour
// --------------------------------------------------------------------------------
bool CSuperString::operator<(const char* ssCompare) {
	return strlen(m_pstrSuperString) < strlen(ssCompare);
}



// --------------------------------------------------------------------------------
// Name: Greater Than Operator
// Abstract: checks if this object is larger in length - undefined behaviour
// --------------------------------------------------------------------------------
bool CSuperString::operator>(CSuperString& ssCompare) {
	return strlen(m_pstrSuperString) > strlen(ssCompare.m_pstrSuperString);
}



// --------------------------------------------------------------------------------
// Name: Greater Than Operator
// Abstract: checks if this object is larger in length - undefined behaviour
// --------------------------------------------------------------------------------
bool CSuperString::operator>(const char* ssCompare) {
	return strlen(m_pstrSuperString) > strlen(ssCompare);
}



// --------------------------------------------------------------------------------
// Name: Not Equals
// Abstract: Opposite of equals
// --------------------------------------------------------------------------------
bool CSuperString::operator!=(CSuperString& ssCompare) {
	return !(*this == ssCompare);
}



// --------------------------------------------------------------------------------
// Name: Not Equals
// Abstract: Opposite of equals
// --------------------------------------------------------------------------------
bool CSuperString::operator!=(const char* ssCompare) {
	return !(*this == ssCompare);
}



// --------------------------------------------------------------------------------
// Name: Greater than or equal to
// Abstract: Checks if this is greater or equal
// --------------------------------------------------------------------------------
bool CSuperString::operator>=(CSuperString& ssCompare) {
	return (*this == ssCompare) || (*this > ssCompare);
}



// --------------------------------------------------------------------------------
// Name: Greater than or equal to
// Abstract: Checks if this is greater or equal
// --------------------------------------------------------------------------------
bool CSuperString::operator>=(const char* ssCompare) {
	return (*this == ssCompare) || (*this > ssCompare);
}



// --------------------------------------------------------------------------------
// Name: Less than or equal to
// Abstract: Checks if this is less than or equal
// --------------------------------------------------------------------------------
bool CSuperString::operator<=(CSuperString& ssCompare) {
	return (*this == ssCompare) || (*this < ssCompare);
}



// --------------------------------------------------------------------------------
// Name: Less than or equal to
// Abstract: Checks if this is less than or equal
// --------------------------------------------------------------------------------
bool CSuperString::operator<=(const char* ssCompare) {
	return (*this == ssCompare) || (*this < ssCompare);
}