#include "utils.h"
#include "iostream"
#include<vcclr.h>
using namespace System;


 int stringToInt(String^ oof) {
	interior_ptr<const Char> ppchar = PtrToStringChars(oof);
	int newValue = 0;
	for (; *ppchar != L'\0'; ++ppchar) {
		char c = *ppchar;
		int offset = (int)L'0';
		int digit = c - offset;
		newValue = newValue * 10 + digit;
		
		
	}
	return newValue;
}

 bool ifIntEntered(String^ poo) {
	
	interior_ptr<const Char> ppchar = PtrToStringChars(poo);
	
	for (; *ppchar != L'\0'; ++ppchar) {
		char c = *ppchar;
		int offset = (int)L'0';
		int digit = c - offset;
		if (digit < 0 || digit > 9) {
			return false;
		}



	}
		
	return true;
}

 String^ intToString(int pee) {
	 return pee.ToString();
 }