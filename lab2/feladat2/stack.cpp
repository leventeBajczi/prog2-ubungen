#include "stack.hpp"

#include <vector>
#include <iostream>
#include <cstring>

void
stack_init(stack &s)
{
    s.elements = 0;
    (s.pData).resize(0);
}

void
stack_cleanUp(stack &s)
{
    (s.pData).erase((s.pData).begin() + 0, (s.pData).begin() +  s.elements);
    (s.pData).resize(0);
    s.elements = 0;
}

int
stack_push(stack &s, const char newElement)
{
    if(s.elements == MAX_SIZE - 1) return 1;
    (s.pData).resize(++s.elements);
    (s.pData)[s.elements-1] = newElement;
    return 0;
}

int
stack_pop(stack &s)
{
    char save = (s.pData)[s.elements-1];
    (s.pData).resize(--(s.elements));
    return (int)save;
}

bool
stack_isEmpty(const stack &s)
{
    return (((stack&)s).pData.empty());
}

int
stack_push(stack &s, const char *str)
{
    for(int i = 0; i<std::strlen(str); i++)
    {
        if(stack_push(s,str[i])) return 1;
    }
    return 0;
}