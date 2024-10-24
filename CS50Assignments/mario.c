#include <stdio.h>
#include <stdlib.h>

// this is a change teste
void PrintVerticalBricks(int n);
void PrintVerticalSpaces(int n);
void PrintHorizontalSpaces(int n);
void PrintHorizontalBricks(int n);

int main (void)
{
    int input;
    printf("input: ");
    scanf("%d", &input);

    PrintVerticalSpaces(input); 
}


void PrintVerticalSpaces(int n)
{
    const int verticalSpaces = n;

    for(int i = 1; i <= verticalSpaces; i++)
    {
        PrintHorizontalSpaces(n);
        PrintHorizontalBricks(n-(n-i));
        printf("  ");
        PrintHorizontalBricks(n-(n-i));
        printf("\n");
        n--;
    }
}


void PrintHorizontalSpaces(int n)
{

    for (int i = 1; i < n; i++)
    {
        int horizontalSpaces = n-i;
        printf(" ");
    }
}

void PrintVerticalBricks(int n)
{
    for (int i = 0; i < n; i++)
    {
        PrintHorizontalBricks(n);
    }
}

void PrintHorizontalBricks(int n)
{
    int horizontalBricks = n;
    for(int i = 0; i < n; i++)
    {
        printf("#");
    }
}
