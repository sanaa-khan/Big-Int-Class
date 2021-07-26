#ifndef BIGINT_H_
#define BIGINT_H_

#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
using std::string;
using std::stringstream;
using std::ostream;
using std::istream;

class BigInt {

	int size;
	char *cptr;

public:
	BigInt(int val = 0);
	BigInt(const string& text);
	BigInt(const BigInt& copy); // copy constructor

	bool allNine() const;

	// Binary Operators
	// Arithmetic Operators
	BigInt operator+(const BigInt& val) const;
	BigInt operator+(int val) const;
	BigInt operator-(const BigInt& val) const;
	BigInt operator-(int val) const;
	BigInt operator*(const BigInt& val) const;
	// Compound Assignment Operators
	BigInt operator+=(const BigInt& rhs);
	BigInt operator-=(const BigInt& rhs);
	BigInt operator*=(const BigInt& rhs);
	// Logical Operators
	bool operator==(const BigInt& val) const;
	bool operator!=(const BigInt& val) const;
	bool operator<(const BigInt& val) const;
	bool operator<=(const BigInt& val) const;
	bool operator>(const BigInt& val) const;
	bool operator>=(const BigInt& val) const;

	// Unary Operators
	BigInt& operator++();  // Pre-increment Operator
	BigInt operator++(int);  // Post-increment Operator
	BigInt& operator--();  // Pre-decrement Operator
	BigInt operator--( int ); // Post-decrement Operator

	//Conversion Operator
	operator string();    // return value of the BigInt as string
	~BigInt(); // destructor
};

int convertToInt(string s);
string convertToString(int n);
int strLen(string &s);

ostream& operator<<(ostream& output, const BigInt& val); // outputs the BigInt
istream& operator>>(istream& input, BigInt& val); // inputs the BigInt


#endif /* BIGINT_H_ */
