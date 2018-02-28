#ifndef STACK_H
#define STACK_H

#include <vector>

const int MAX_SIZE = 20;

struct stack
{
    int elements;
	std::vector<char> pData;
};

void stack_init(stack &s);
void stack_cleanUp(stack &s);
int stack_push(stack &s, const char newElement);
int stack_pop(stack &s);
bool stack_isEmpty(const stack &s);
int stack_push(stack &s, const char *str);

#endif // STACK_H
