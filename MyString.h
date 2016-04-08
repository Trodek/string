#ifndef _MyString_
#define _MyString_

#include <string.h>

#define DEFAULT_SIZE 1

typedef unsigned int uint;

class MyString{
private:
	char* text;
	uint size;
	void alloc(uint lenght){
		text = new char[lenght+1];
		size = sizeof(text);

	}
	
public:
	MyString(){
		alloc(1);
	}

	MyString(const char* input_text){
		uint size = strlen(input_text)+1;
		alloc(size-1);
		strcpy_s(text, size, input_text);
	}

	MyString(MyString& str):text(str.text){}

	~MyString(){
		delete[] text;
		text = nullptr;
	}

	// methods

	unsigned int lenght() const {
		return strlen(text);
	}

	char* c_str()const {
		return text;
	}

	// operators

	bool operator==(MyString& input){
		return strcmp(text, input.text) ? false : true;
	}

	bool operator!=(MyString& input){
		return strcmp(text, input.text) ? true : false;
	}

	MyString& operator=(const char* str){
		int str_len = strlen(str);
		if (str_len > lenght()){
			delete[] text;
			alloc(str_len);
		}
		strcpy_s(text, size, str);

		return *this;
	}
	MyString& operator=(MyString& str){
		if (str.lenght() > lenght()){
			delete[] text;
			alloc(str.lenght());
			strcpy_s(text, str.lenght() + 1, str.text);
		}
		strcpy_s(text, size, str.text);

		return *this;
	}

	void shrink_to_fit(){
		int len = lenght();
		if (sizeof(text)-1 > len){
			char* temp = new char[len + 1];
			strcpy_s(temp, len + 1, text);
			delete[] text;
			alloc(len);
			strcpy_s(text, len + 1, temp);
		}
	}
	MyString& operator+(const char* str){
		int str_len = size-1;
		char* temp = new char[size];
		strcpy_s(temp, size, text);
		delete[] text;
	//	alloc(len + str_len);



	}

};


#endif