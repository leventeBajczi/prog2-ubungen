#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Daten {
    char buchstabe;
    struct Daten* left;
    struct Daten* right;
} Baum;


Baum* add_to_bbaum(Baum *,  const char*, const char);
Baum* new_node(const char);

int main()
{
    Baum* head = NULL;
    head = add_to_bbaum(head, ".-", 'A');
    return 0;
}

Baum* add_to_bbaum(Baum *head,  const char* path , const char buchstabe)
{
    Baum* hilfe = NULL;
    for(int i = 0; i<strlen(path); i++)
    {
        if(!head)head=new_node('\0');
        if(hilfe)
        {
            if(path[i] == '-')hilfe->right = head;
            if(path[i] == '.')hilfe->left = head;
        }
        hilfe = head;
        if(path[i] == '-') head=head->right;
        if(path[i] == '.') head=head->left;
    }    

}

Baum* new_node(const char buchstabe)
{
    Baum *new_baum = (Baum*)malloc(sizeof(Baum));
    new_baum->buchstabe = buchstabe;
    new_baum->right = NULL; 
    new_baum->left = NULL;
}