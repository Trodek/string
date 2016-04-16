#ifndef _MyString_
#define _MyString_

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "dynArray.h"

#define DEFAULT_SIZE 1

typedef unsigned int uint;

class MyString{
private:
	char* text;
	uint size;

private:
	void alloc(uint lenght){
		text = new char[lenght+1];
		size = lenght+1;

	}
	
public:
	// Constructors

	MyString(){
		alloc(1);
		text[0] = '\0';
	}

	MyString(const char* input_text){
		uint size = strlen(input_text)+1;
		alloc(size-1);
		strcpy_s(text, size, input_text);
	}

	MyString(MyString& other){ 
		alloc(other.size - 1);
		strcpy_s(text, other.size, other.text);
		size = other.size;
	}

	// Destructor
	~MyString(){
		delete[] text;
		text = nullptr;
	}

	// Methods

	unsigned int lenght() const {
		return strlen(text);
	}

	char* c_str() const {
		return text;
	}

	void ShrinkToFit(){
		int len = size - 1;
		if (sizeof(text)-1 > len){
			char* temp = new char[len + 1];
			strcpy_s(temp, len + 1, text);
			delete[] text;
			alloc(len);
			strcpy_s(text, len + 1, temp);
		}
	}

	void Prefix(MyString& str){
		int total_len = (size - 1) + str.lenght();
		char* temp = new char[total_len+1];
		strcpy_s(temp, total_len+1, str.text);
		strcat_s(temp, total_len+1, text);
		text = temp;
		size = total_len+1;
	}

	void Prefix(const char* str){
		int total_len = (size - 1) + strlen(str);
		char* temp = new char[total_len + 1];
		strcpy_s(temp, total_len + 1, str);
		strcat_s(temp, total_len + 1, text);
		text = temp;
		size = total_len + 1;
	}

	void Tokenize(const char separator, dynArray<MyString>& tokens){
		uint i = 0;
		while (*(text+i) != 0){
			MyString temporal;
			while (*(text + i) != separator && *(text + i) && *(text + i) != '\n'){
				temporal.Sufix(*(text + i));
				i++;
			}
			tokens.PushBack(temporal);
			if (*(text + i)) i++;
		}
	}

	void Sufix(const char c){
		char* temp = new char[size];
		strcpy_s(temp, size, text);
		delete[] text;
		*(temp+size-1) = '\0';
		*(temp+size-2) = c;
		text = temp;
		size += 1;
	}

	void tolowercase(){
		for (int i = 0; i < size - 1; i++){
			text[i] = tolower(text[i]);
		}
	}

	// Operators

	bool operator==(const MyString& str){
		return strcmp(text, str.text) ? false : true;
	}

	bool operator==(const char* str){
		return strcmp(text, str) ? false : true;
	}

	bool operator!=(const MyString& str){
		return strcmp(text, str.text) ? true : false;
	}

	bool operator!=(const char* str){
		return strcmp(text, str) ? true : false;
	}

	MyString& operator=(const char* str){
		uint str_len = (uint)strlen(str);
		if (str_len > size-1){
			delete[] text;
			alloc(str_len);
		}
		strcpy_s(text, size, str);

		return *this;
	}
	MyString& operator=(const MyString& str){
		if (str.lenght() > lenght()){
			delete[] text;
			alloc(str.lenght());
		}
		strcpy_s(text, size, str.text);

		return *this;
	}

	MyString& operator+=(const char* str){
		int str_len = strlen(str);
		char* temp = new char[size];
		strcpy_s(temp, size, text);
		delete[] text;
		alloc((size-1) + str_len);
		strcpy_s(text, size, temp);
		delete[] temp;
		strcat_s(text, size, str);

		return *this;
	}

	MyString& operator+=(const MyString& str){
		char* temp = new char[size];
		strcpy_s(temp, size, text);
		delete[] text;
		alloc((size - 1) + str.lenght());
		strcpy_s(text, size, temp);
		delete[] temp;
		strcat_s(text, size, str.c_str());

		return *this;
	}

	MyString& operator+=(const char c){
		char* temp = new char[size];
		strcpy_s(temp, size, text);
		delete[] text;
		alloc(size);
		strcpy_s(text, size, temp);
		delete[] temp;
		text[size - 2] = c;
		text[size-1] = '\0';

		return *this;
	}
};


#endif