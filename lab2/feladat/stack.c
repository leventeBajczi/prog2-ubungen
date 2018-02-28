#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
stack_init(struct stack *s)
{
    if(s -> pData)
    {
        fprintf(stderr, "Stack was already initialized.");
        free(s->pData);
    }
    s->pData = NULL;
    s->elements = 0;
}

void
stack_cleanUp(struct stack *s)
{
    free(s->pData);
    s->elements = 0;
}

int
stack_push(struct stack *s, char newElement)
{
    if(s->elements == MAX_SIZE - 1) return 1;
    s->pData = (char*)realloc(s->pData, sizeof(char)*(++(s->elements)));
    (s->pData)[s->elements-1] = newElement;
    return 0;
}

int
stack_pop(struct stack *s)
{
    if(stack_isEmpty(s)) return -1;
    char save = (s->pData)[s->elements-1];
    s->pData = (char*)realloc(s->pData, sizeof(char)*(--(s->elements)));
   return (int)save;
}

int
stack_isEmpty(struct stack *s)
{
    if(s->pData) return 0;
    return 1;
}

int
stack_pushstring(struct stack *s, char *str)
{
    for(int i = 0; i<strlen(str); i++)
    {
        if(stack_push(s,str[i])) return 1;
    }
    return 0;
}