
#ifndef HACHAGE_H
#define HACHAGE_H
#define SIZE 13 
#include "parse.h"

	gen_t hachtab[SIZE];

	void viewhach();

	int hachage(char *s);
	gen_t findtab(char *s);
	void addtab(char *s,int type, char* var);
	void init();
	int isEmpty(gen_t* g);

#endif