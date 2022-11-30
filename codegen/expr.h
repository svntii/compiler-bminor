

typedef enum
{
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MULT,
	EXPR_DIV,
	EXPR_OR,
	EXPR_AND,
	EXPR_LT,
	EXPR_LTE,
	EXPR_GT,
	EXPR_GTE,
	EXPR_EQ,
	EXPR_NEQ,
	EXPR_MOD,
	EXPR_EXP,
	EXPR_NEGATE,
	EXPR_NOT,
	EXPR_POSIN,
	EXPR_POSDEC,
	EXPR_GROUP,
	EXPR_SUBSCRIPT,
	EXPR_SUBSCRIPT_SUB,
	EXPR_FUNCTION_CALL,
	EXPR_ARG,
	EXPR_PRINT_BODY,
	EXPR_ASSIGNMENT,
	EXPR_TERN,
	EXPR_TERN_BODY,
	EXPR_INTEGER_LITERAL,
	EXPR_BOOLEAN_LITERAL,
	EXPR_CHAR_LITERAL,
	EXPR_STRING_LITERAL,
	EXPR_ARRAY_LITERAL,
	EXPR_NAME
} expr_t;

struct expr
{
	expr_t kind;
	struct expr *left;
	struct expr *right;
	const char *name;
	struct symbol *symbol;
	int literal_value;
	const char *string_literal;
};

struct expr *expr_create(expr_t kind, struct expr *left, struct expr *right);

// all the leaf elements of an AST

struct expr *expr_create_integer_literal(int i);		  // an actual number
struct expr *expr_create_boolean_literal(int b);		  // true/false
struct expr *expr_create_char_literal(char c);			  //	'a'
struct expr *expr_create_string_literal(const char *str); // "Notre Dame"
struct expr *expr_create_name(const char *name);
void expr_print(struct expr *e, int tab);
struct type *expr_typecheck(struct expr *e);
void expr_resolve(struct expr *e);
struct expr *expr_copy(struct expr *e);

void expr_codegen(struct expr *e);