
#ifndef PARSE_H
#define PARSE_H

typedef struct gen_t {
	char *code;
	int type;
	char *var;
	char *name;
} gen_t;

typedef enum base_t {
	VOID_T,
	INT_T,
	FLOAT_T
} base_t;

typedef enum assign_t {
  ASSIGN_T,
  MUL_ASSIGN_T,
  ADD_ASSIGN_T,
  SUB_ASSIGN_T
} assign_t;

#endif
