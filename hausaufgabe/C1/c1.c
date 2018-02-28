#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOC_UNIT 20

/*
Iteriert durch den File, und sucht den laengste Wort durch Vergleichung mit dem letzten groeßten Wort. 
Nachteil: falls es mehr Woerter mit dem gleichen Buchstabezahl gibt, dann wird nur das erste gefunden werden.
*/

int laengste(FILE *, char **);

int main()
{
    char* wort = NULL;
    FILE* f = fopen("test.txt", "r");
    int lange = laengste(f, &wort);
    printf("%d: %s", lange, wort);
    free(wort);
    return 0;
}

int laengste(FILE *f, char **lw)
{
    char c;
    int i, lange = 0, k = 0;
    char *buffer = NULL;
    while((c = fgetc(f)) != EOF)
    {
        if(i>=ALLOC_UNIT*k) buffer = (char*)realloc(buffer, ALLOC_UNIT*(++k));
        if(c != '\n')
        {
            buffer[i++] = c;
        }
        else
        {
            if(i>lange)
            {
                buffer[i] = '\0';
                lange = i;
                *lw = (char*)realloc(*lw, (strlen(buffer)+1) * sizeof(char));
                strcpy(*lw, buffer);
            }
            i = 0;
            k = 0;
            free(buffer);
        }
    }

    if(i>lange)
    {
        buffer[i] = '\0';
        lange = i;
        *lw = (char*)malloc((strlen(buffer)+1) * sizeof(char));
        strcpy(*lw, buffer);
        free(buffer);
    }

    return lange;


}