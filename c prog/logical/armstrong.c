#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("enter a number:");
    scanf("%d", &n);

    int len = (int)log10(n) + 1;
    int new = 0;
    int nc = n;
    while (nc)
    {
        new += pow(nc % 10, len);
        nc /= 10;
    }
    printf("%d\n", new);
    if (new == n)
    {
        printf("armstrong number");
    }
    else
    {
        printf("not armstrong number");
    }
}

/*
enter a number:8208
8208
armstrong number
*/