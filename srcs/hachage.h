
#ifndef HACHAGE_H
#define HACHAGE_H
#define SIZE 101 
#include "parse.h"


	typedef struct hashtab{
		struct hashtab* HT;
		gen_t htab[SIZE];
		int depth;
	} hashtab;

	hashtab* mainHT;
	hashtab* currentHT;

	void init(hashtab *t);
	void view(hashtab *t);
	
	int isPresent(hashtab *t,char* s);

	int hachage(char *s);
	gen_t findtab(hashtab* t,char *s);
	void addtab(hashtab*t ,char *s,int type, char* var);
	void setIsPointer(hashtab* t, char* name,int p);
	void setVar(hashtab* t, char* name,char* v);

#endif