#include <iostream>
#include "MyString.h"

int main(){

	MyString some("text");

	std::cout << some.c_str();

	getchar();
	return 0;
}