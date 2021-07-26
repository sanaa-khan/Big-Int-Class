#include "BigInt.h"

BigInt::BigInt(int val) {

	string str = convertToString(val);

	size = strLen(str);

	cptr = new char[size];

	for (int i = 0; i < size; i++)
		cptr[i] = str[i];
}

BigInt::BigInt(const string& text) {
	int len = 0;

	while (text[len] != '\0')
		len++;

	size = len;

	cptr = new char[size];

	for (int i = 0; i < size; i++)
		cptr[i] = text[i];
}

BigInt::BigInt(const BigInt &copy) {

	size = copy.size;

	cptr = new char[size];

	for (int i = 0; i < size; i++)
		cptr[i] = copy.cptr[i];
}

bool BigInt::allNine() const {

	for (int i = 0; i < size; i++) {
		if (cptr[i] != '9')
			return false;
	}

	return true;
}

bool BigInt::operator==(const BigInt& val) const {

	if (size != val.size)
		return false;

	for (int i = 0; i < size; i++) {
		if (cptr[i] != val.cptr[i])
			return false;
	}

	return true;
}

bool BigInt::operator!=(const BigInt& val) const {

	if (*this == val)
		return false;

	return true;
}

bool BigInt::operator<(const BigInt& val) const {

	if (size > val.size)
		return false;

	else if (size < val.size)
		return true;

	for (int i = size-1; i >= 0; i--) {
		if (cptr[i] > val.cptr[i])
			return false;

		else if (cptr[i] < val.cptr[i])
			return true;

		else
			continue;
	}

	return false;
}

bool BigInt::operator<=(const BigInt& val) const {

	if (*this == val || *this < val)
		return true;

	return false;
}

bool BigInt::operator>(const BigInt& val) const {

	if (size < val.size)
		return false;

	else if (size > val.size)
		return true;

	for (int i = size-1; i >= 0; i--) {
		if (cptr[i] > val.cptr[i])
			return true;

		else if (cptr[i] < val.cptr[i])
			return false;

		else
			continue;
	}

	return false;
}

bool BigInt::operator>=(const BigInt& val) const {

	if (*this == val || *this > val)
		return true;

	return false;
}

int convert(char* str, int index) {

	int ans = str[index] - 48;
	return ans;
}

BigInt& BigInt::operator++() {

	if (this->allNine()) {
		delete []this->cptr;

		this->size++;

		cptr = new char[size];

		cptr[0] = '1';

		for (int i = 1; i < size; i++)
			cptr[i] = '0';

		return *this;
	}

	else {

		int carry = 0;

		for (int i = size-1; i > 0; i--) {

			int val = convert(cptr, i) + carry;

			if (val == 9) {
				cptr[i] = '0';
				carry = 1;
			}

			else {
				cptr[i]++;
				carry = 0;
				return *this;
			}
		}

		return *this;
	}
}

BigInt BigInt::operator++(int) {

	BigInt b(*this);

	if (this->allNine()) {
		delete []this->cptr;

		this->size++;

		cptr = new char[size];

		cptr[0] = '1';

		for (int i = 1; i < size; i++)
			cptr[i] = '0';

		return b;
	}

	else {

		int carry = 0;

		for (int i = size-1; i > 0; i--) {

			int val = convert(cptr, i) + carry;

			if (val == 9) {
				cptr[i] = '0';
				carry = 1;
			}

			else {
				cptr[i]++;
				carry = 0;
				return b;
			}
		}

		return b;
	}
}

BigInt& BigInt::operator--() {

	if (this->cptr[0] == '1') {

		bool allZero = true;

		for (int i = 1; i < size; i++) {
			if (cptr[i] != '0')
				allZero = false;
		}

		if (allZero) {

			delete []this->cptr;

			size--;

			this->cptr = new char[size];

			for (int i = 0; i < size; i++)
				this->cptr[i] = '9';

			return *this;
		}

		else {

			int carry = 0;

			for (int i = size-1; i > 0; i--) {

				int val = convert(cptr, i) - carry;

				if (val == 0) {
					cptr[i] = '9';
					carry = 1;
				}

				else {
					cptr[i]--;
					carry = 0;
					return *this;
				}
		}
	}

	}


	int carry = 0;

	for (int i = size-1; i > 0; i--) {

		int val = convert(cptr, i) - carry;

		if (val == 0) {
			cptr[i] = '9';
			carry = 1;
		}

		else {
			cptr[i]--;
			carry = 0;
			return *this;
		}

	}

	return *this;
}


BigInt BigInt::operator--( int ) {

	BigInt b(*this);

	if (this->cptr[0] == '1') {

		bool allZero = true;

		for (int i = 1; i < size; i++) {
			if (cptr[i] != '0')
				allZero = false;
		}

		if (allZero) {

			delete []this->cptr;

			size--;

			this->cptr = new char[size];

			for (int i = 0; i < size; i++)
				this->cptr[i] = '9';

			return b;
		}

		else {

			int carry = 0;

			for (int i = size-1; i > 0; i--) {

				int val = convert(cptr, i) - carry;

				if (val == 0) {
					cptr[i] = '9';
					carry = 1;
				}

				else {
					cptr[i]--;
					carry = 0;
					return b;
				}
		}
	}

	}


	int carry = 0;

	for (int i = size-1; i > 0; i--) {

		int val = convert(cptr, i) - carry;

		if (val == 0) {
			cptr[i] = '9';
			carry = 1;
		}

		else {
			cptr[i]--;
			carry = 0;
			return b;
		}

	}

	return b;
}

BigInt::operator string() {

	string toReturn;

	for (int i = 0; i < size; i++)
		toReturn += cptr[i];

	return toReturn;
}

BigInt::~BigInt() {
	delete []cptr;
}

string convertToString(int n) {

	stringstream ss;
	ss << n;

	return ss.str();
}

int strLen(string &str) {

	int len = 0;

	while (str[len] != '\0')
		len++;

	return len;
}
