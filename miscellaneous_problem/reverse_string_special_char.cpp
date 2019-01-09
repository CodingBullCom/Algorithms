// File: reverse_string_special_char.cpp
// Created on: 6th Jan 2019
// Updated on: 9th Jan 2019
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.
//
// Input: a!!!b.c.d,e'f,ghi
// Output: ed,c,bA!$
// Desciption: Reverse string without affecting the special charactes

#include <iostream>
#include <string>
using namespace std;

bool is_special_char(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
      return false;
    return true;
}

void swap(string &str, int i, int j) {
  char temp = str[i];
  str[i] = str[j];
  str[j] = temp;
}

string reverse_string_without_affecting_special_char(string str) {
     string return_string = str;
     int i = 0, j = return_string.size()-1;
     while ( i < j ) {
         while(is_special_char(return_string[i]))
              i++;
         while(is_special_char(return_string[j]))
              j--;
         if(i < j) {
              swap(return_string, i, j);
              i++;
              j--;
          }
     }
     return return_string;
}

int main() {
    string str = "a!!!b.c.d,e'f,ghi";
    cout << "Original string:: " << str << endl;
    cout << "Reversed string:: ";
    cout << reverse_string_without_affecting_special_char(str) << endl;
    return 0;
}
