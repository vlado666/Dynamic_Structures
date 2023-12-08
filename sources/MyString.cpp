#include <iostream>

class MyString {

public:
	MyString() {
		str = nullptr;
		length = 0;
	}
	MyString(const char* str) {
		length = strlen(str);
		this->str = new char[length + 1];

		for (size_t i = 0; i < length; ++i) {
			this->str[i] = str[i];
		}

		this->str[length] = '\0';

	}
	~MyString() {
		delete[] this->str;
	}

	MyString(const MyString& other) {
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (size_t i = 0; i < length; ++i) {
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}

	MyString& operator =(const MyString& other) {
		if (this->str != nullptr) {
			delete[] str;
		}
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (size_t i = 0; i < length; ++i) {
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;
	}

	MyString operator +(const MyString& other) {
		MyString newStr;

		newStr.str = new char[strlen(this->str) + strlen(other.str) + 1];
		newStr.length = strlen(this->str) + strlen(other.str);

		size_t i = 0;
		for (; i < strlen(this->str); ++i) {
			newStr.str[i] = this->str[i];
		}
		for (size_t j = 0; j < strlen(other.str); ++j, ++i) {
			newStr.str[i] = other.str[j];
		}
		newStr.str[strlen(this->str) + strlen(other.str)] = '\0';

		return newStr;
	}

	size_t Length() {
		return length;
	}

	bool operator ==(const MyString& other) {
		if (this->length != other.length) {
			return false;
		}
		for (size_t i = 0; i < length; ++i) {
			if (this->str[i] != other.str[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator !=(const MyString& other) {
		return !this->operator==(other);
	}

	char& operator [](int index) {
		return this->str[index];
	}

	MyString(MyString&& other) {
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}

	void Print() {
		std::cout << str << std::endl;
	}

private:
	char* str;
	size_t length;
};

/*MyString str("Test");
	MyString str2("Complited!");
	MyString result;
	result = str + " " + str2;
	result.Print();
	std::cout << str.Length() << std::endl;
	std::cout << str2.Length() << std::endl;
	std::cout << result.Length() << std::endl;*/