
#ifndef PARSE_H
#define PARSE_H

typedef enum base {
	INT_T=0,
	FLOAT_T,
	VOID_T
} base;

typedef struct gen_t{
	char *code;
	int type;
	char *var;
	char *name;

} gen_t;

#endif