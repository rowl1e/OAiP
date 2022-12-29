#pragma once
#include "strg.c"

char* get_str ();
int str_len(char* str);
int isletter_ (char c);
void str_copy(char* str1, char** str2);
void print_string(char** str, int argc);