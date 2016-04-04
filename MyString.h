#ifndef _MyString_
#define _MyString_

#include <string.h>

#define DEFAULT_SIZE 1

class MyString{
private:
	char* text;
	void alloc(unsigned int lenght){
		text = new char[lenght+1];
	}
	
public:
	MyString(){
		alloc(1);
	}

	MyString(const char* input_text){
		unsigned int size = strlen(input_text)+1;
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
};


#endif