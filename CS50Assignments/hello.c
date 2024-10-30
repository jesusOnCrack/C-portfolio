#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    printf("\nOh!...\nWhat's your name stranger?\n");
    char name[20];
    scanf("%s", name);
    
    printf("in that case... strangers nevermore!\nhello, %s!\n", name);
}