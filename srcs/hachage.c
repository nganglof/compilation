#include <stdio.h>
#include <string.h>
#include "hachage.h"
#include "parse.h"

gen_t EMPTY_H={"",0,"","",0}; // un symbole vide


void init(hashtab *t) {
  t->HT = NULL;
  int i;
  for (i=0; i<SIZE; i++) t->htab[i]=EMPTY_H;
}

void view(hashtab *t){
  int i=0;
  while (i<SIZE){
    printf("Element %d : name %s reg %s\n",i,t->htab[i].name,t->htab[i].var );
    i++;

  }

}


// 1 if present, 0 if not
int isPresent(hashtab* t, char *s){
  gen_t present = findtab(t,s);
  return !(strcmp(present.name,"")==0 && strcmp(present.var,"")==0 &&  present.type==0 );
}

gen_t findtab(hashtab* t, char *s) {
  if (!strcmp(t->htab[hachage(s)].name,s)) return t->htab[hachage(s)];
  return EMPTY_H;
}

int hachage(char *s) {
  unsigned int hash = 0; 
  while (*s!='\0') hash = hash*31 + *s++;
  return hash%SIZE;
}

void addtab(hashtab* t, char *name,int type, char *var) {
  gen_t *h = &t->htab[hachage(name)];
  h->name=name; h->type=type; h->code=NULL; h->var=var; h->isPointer=1;
}

void setIsPointer(hashtab* t, char* name,int p){
  int i=0;
  while(i<SIZE && hachage(t->htab[i].name)!=hachage(name)){
    i++;
  }
  t->htab[i].isPointer=p;
}

void setVar(hashtab* t, char* name,char* v){
  int i=0;
  while(i<SIZE && hachage(t->htab[i].name)!=hachage(name)){
    i++;
  }
  t->htab[i].var=v;
}





