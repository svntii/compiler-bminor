#include <stdlib.h>
#include <stdio.h>

// Special Functions

void *special_xmalloc(size_t size);
void special_tabprinter(int tab);
void special_expr_error_handler(struct expr *e, struct type *lt, struct type *rt);
void special_stmt_error_handler(struct stmt *s, struct type *t);
void special_decl_error_handler(struct decl *d, struct type *t);