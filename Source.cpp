#include <iostream>
#include <string>
#include "MyString.h"
#include "dynArray.h"

int main(){

	dynArray<MyString> tokens;
	MyString thing = "honey I love you";
	thing.Tokenize(' ', tokens);
	for (int i = 0; i<tokens.GetElements();i++)
	printf("%s ", tokens[i].c_str());


	getchar();
	return 0;
}