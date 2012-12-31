//stack.h


typedef struct {
	int *elems;
	int logicalLen;
	int allocLen;
} stack;

void StackNew(stack *s, int allocLen);
void StackDispose(stack *s);
void StackPush(stack *s, int value);
int StackPop(stack *s);
void StackPrint(stack *s);
