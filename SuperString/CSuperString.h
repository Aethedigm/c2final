// --------------------------------------------------------------------------------
// Stephen C Sumpter
// 14/8/2022
// C programming 2
// Final
// --------------------------------------------------------------------------------

#pragma once
#define _CRT_SECURE_NO_WARNINGS

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include<iostream>
#include<string.h>
#include<cstdlib>
#include<string>
#include<vector>
// --------------------------------------------------------------------------------
// Class: CSuperString 
// --------------------------------------------------------------------------------
class CSuperString
{

private:
	char* m_pstrSuperString;

public:
	CSuperString();
	CSuperString(const char* pstrStringToCopy);
	CSuperString(const bool blnBooleanToCopy);
	CSuperString(const char chrLetterToCopy);
	CSuperString(const short shtShortToCopy);
	CSuperString(const int intIntegerToCopy);
	CSuperString(const long lngLongToCopy);
	CSuperString(const float sngFloatToCopy);
	CSuperString(const double dblDoubleToCopy);
	CSuperString(const CSuperString& ssStringToCopy);


	virtual ~CSuperString();
	int Length() const;

	void operator = (const char* pstrStringToCopy);
	void operator = (const char chrLetterToCopy);
	void operator = (const CSuperString& ssStringToCopy);

	void operator += (const char* pstrStringToAppend);
	void operator += (const char chrCharacterToAppend);
	void operator += (const CSuperString& ssStringToAppend);

	friend CSuperString operator+ (const CSuperString& ssLeft, const CSuperString& ssRight);
	friend CSuperString operator+ (const char* pstrLeftSide, const CSuperString& ssRightString);
	friend CSuperString operator+ (const CSuperString& ssLeftString, const char* pstrRightSide);

	long FindFirstIndexOf(const char chrLetterToFind);
	long FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex);
	long FindLastIndexOf(const char chrLetterToFind);

	long FindFirstIndexOf(const char* pstrSubStringToFind);
	long FindFirstIndexOf(const char* pstrSubStringToFind, long lngStartIndex);
	long FindLastIndexOf(const char* pstrSubStringToFind);

	std::vector<int> FindAllIndexesOf(const char* pstrFind);

	const char* ToUpperCase();
	const char* ToLowerCase();
	const char* TrimLeft();
	const char* TrimRight();
	const char* Trim();
	const char* Reverse();

	const char* Left(long lngCharactersToCopy);
	const char* Right(long lngCharactersToCopy);
	const char* Substring(long lngStart, long lngSubStringLength);

	const char* Replace(char chrLetterToFind, char chrReplace);
	const char* Replace(const char* pstrFind, const char* pstrReplace);
	char* ReplaceIndexRange(char* strIn, int intStart, int intEnd, const char* pstrFill);
	const char* Insert(const char chrLetterToInsert, long lngIndex);
	const char* Insert(const char* pstrSubString, long lngIndex);

	char& operator [ ] (long lngIndex);
	const char& operator [ ] (long lngIndex) const;

	bool operator == (CSuperString& ssCompare);
	bool operator == (const char* ssCompare);

	bool operator < (CSuperString& ssCompare);
	bool operator < (const char* ssCompare);

	bool operator > (CSuperString& ssCompare);
	bool operator > (const char* ssCompare);

	bool operator != (CSuperString& ssCompare);
	bool operator != (const char* ssCompare);

	bool operator >= (CSuperString& ssCompare);
	bool operator >= (const char* ssCompare);

	bool operator <= (CSuperString& ssCompare);
	bool operator <= (const char* ssCompare);

	const char* ToString();
	bool ToBoolean();
	short ToShort();
	int ToInteger();
	long ToLong();
	float ToFloat();
	double ToDouble();

	friend std::ostream& operator << (std::ostream& osOut, const CSuperString& ssOutput) {
		for (int intIndex = 0; intIndex < ssOutput.Length(); intIndex++) {
			osOut << ssOutput.m_pstrSuperString[intIndex];
		}

		return osOut;
	};

	friend std::istream& operator >> (std::istream& isIn, CSuperString& ssInput) {
		isIn >> ssInput.m_pstrSuperString;
		return isIn;
	};

private:
	void ClassCopy(const CSuperString& ssStringToCopy);
	bool IsEquals(const char* ssCompare);
};