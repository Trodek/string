#include <iostream>
#include <string>
#include "MyString.h"

int main(){

	MyString some;
	MyString thing = "honey";
	printf("%s ", thing.c_str());
	some = "hello";
	printf("%s ", some.c_str());
	thing += some;
	printf("%s ", some.c_str());
	printf("%s ", thing.c_str());
	MyString a = "He";
	MyString c = "llo";
	c.Prefix(a);
	printf("%s ", c.c_str());
	getchar();
	return 0;
}