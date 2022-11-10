// Header file for statements in BMinor

typedef enum
{
	STMT_DECL,
	STMT_EXPR,
	STMT_IF_ELSE,
	STMT_IF,
	STMT_FOR,
	STMT_PRINT,
	STMT_RETURN,
	STMT_WHILE,
	STMT_BLOCK
} stmt_t;

struct stmt
{
	stmt_t kind;
	struct decl *decl;
	struct expr *init_expr;
	struct expr *expr;
	struct expr *next_expr;
	struct stmt *body;
	struct stmt *else_body;
	struct stmt *next;
};

struct stmt *stmt_create(stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next);
struct stmt *stmt_create_decl(struct decl *decl);
struct stmt *stmt_create_expr(struct expr *expr);
struct stmt *stmt_create_if_else(struct expr *expr, struct stmt *body, struct stmt *else_body);
struct stmt *stmt_create_if(struct expr *expr, struct stmt *body);
struct stmt *stmt_create_for(struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body);
struct stmt *stmt_create_print(struct expr *expr);
struct stmt *stmt_create_return(struct expr *expr);
struct stmt *stmt_create_while(struct expr *expr, struct stmt *body);
struct stmt *stmt_create_block(struct stmt *body);
void *stmt_print(struct stmt *s, int tab);

void stmt_resolve(struct stmt *s);
void stmt_typecheck(struct stmt *s);
