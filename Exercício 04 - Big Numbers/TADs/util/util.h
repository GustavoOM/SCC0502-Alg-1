#ifndef UTIL_H
#define UTIL_H

//Boolean returns
#define TRUE 1
#define FALSE 0

//Interface
#define DIGITS 399

//Errors list
#define TOTAL_NUMBER_NULL_ERROR -30000
#define PART_NUMBER_NODE_NULL_ERROR -30001

typedef int boolean;

void converterInteiro(boolean valor);
int countChars(char * word);
void itoa(int n, char s[]);
void reverse(char s[]);

#endif //UTIL_H
