#include <stdio.h>
#include <string.h>
#include "hachage.h"
#include "parse.h"

gen_t EMPTY_H={"",0,"",""}; // un symbole vide

void viewhach(){
	int i=0;
	while (i<10){
		i++;
		printf("Element %d : name %s reg %s\n",i,hachtab[i].name,hachtab[i].var );
	}

}

int isEmpty(gen_t * g){

	printf("%s\n",g->code);

	printf("g : %s %s\n",g->name,g->var);

}

int hachage(char *s) {
  unsigned int hash = 0; 
  while (*s!='\0') hash = hash*31 + *s++;
  return hash%SIZE;
}
gen_t findtab(char *s) {
  if (!strcmp(hachtab[hachage(s)].name,s)) return hachtab[hachage(s)];
  return EMPTY_H;
}
void addtab(char *name,int type, char *var) {
  gen_t *h=&hachtab[hachage(name)];
  h->name=name; h->type=type; h->code=NULL; h->var=var;
}
void init() {
  int i;
  for (i=0; i<SIZE; i++) hachtab[i]=EMPTY_H;
}
