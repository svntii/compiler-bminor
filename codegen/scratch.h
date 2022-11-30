
int scratch[] = {0, 0, 0, 0, 0, 0, 0};
char *scratch_register[] = {"%rbx", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15"};

int scratch_alloc(void);
void scratch_free(int r);
const char *scratch_name(int r);