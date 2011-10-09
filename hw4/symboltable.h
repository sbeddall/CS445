#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE
struct c_type {
  int base_type;    /* 1 = int, 2=float, ... */
  union {
    struct array {
      int size;
      struct c_type *elemtype;
    } a;
    struct ctype *p;
    struct struc {
      char *label;
      struct field **f;
    } s;
  } u;
}
  
struct field {
  char *name;
  struct ctype *elemtype;
}
  
struct symbol_table { 
}
#endif
