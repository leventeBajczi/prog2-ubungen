#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 20

struct stack
{
    int elements;
	char* pData;
};

void stack_init(struct stack *s);
void stack_cleanUp(struct stack *s);
int stack_push(struct stack *s, char newElement);
int stack_pop(struct stack *s);
int stack_isEmpty(struct stack *s);
int stack_pushstring(struct stack *s, char *str);

#endif // STACK_H
