#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
    char *check = malloc(6 * sizeof(char));
    scanf("%s", check);
    //char *nobody = malloc(6 * sizeof(char));
    
    //strcpy(nobody, check);
    scanf("%s", check);

    
    printf("%s\n", check);
    //free(nobody);
    free(check); 
    return 0;
}
