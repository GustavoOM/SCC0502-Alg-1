#ifndef UTIL_H
#define UTIL_H

//Boolean returns
#define TRUE 1
#define FALSE 0

//Compare types
#define GREATER 1
#define LESSER 2
#define EQUAL 3

typedef int boolean;

char *readLine();
int cpfComparator(char *cpf1, char *cpf2);
void removeDotsAndDashesFromCpf(char *cpf);
void removeLeftZeros(char * zeroValue);

#endif //UTIL_H
