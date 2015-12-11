
#ifndef HACHAGE_H
#define HACHAGE_H
#define SIZE 1013 
#include "parse.h"


	gen_t hachtab[SIZE];

	int hachage(char *s);
	gen_t findtab(char *s);
	void addtab(char *s,int type, char* var);
	void init();

#endif