#include <stdio.h>
#include <string.h>
#include "hachage.h"
#include "parse.h"

gen_t EMPTY_H={"",0,"",}; // un symbole vide


int hachage(char *s) {
  unsigned int hash = 0; 
  while (*s!='\0') hash = hash*31 + *s++;
  return hash%SIZE;
}
gen_t findtab(char *s) {
  if (!strcmp(hachtab[hachage(s)].name,s)) return hachtab[hachage(s)];
  return EMPTY_H;
}
void addtab(char *s,int type, char *var) {
  gen_t *h=&hachtab[hachage(s)];
  h->name=s; h->type=type; h->code=NULL; h->var=var;
}
void init() {
  int i;
  for (i=0; i<SIZE; i++) hachtab[i]=EMPTY_H;
}
