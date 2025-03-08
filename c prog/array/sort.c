#include <stdio.h>
#include <string.h>

// sort int using function pointer
int *sort(int *a, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (*(a + i) > *(a + j))
            {
                int temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }

    return a;
}

// sort char using function pointer
char *sortc(char *a, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (*(a + i) > *(a + j))
            {
                int temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }

    return a;
}

// sort char using function pointer
void sorts(char *a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (strcmp(a[i], a[j]) > 0)
            {
                char *temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{

    // declare array and their length
    int i[] = {6, 5, 3, 2, 4, 1};
    int len = sizeof(i) / sizeof(i[0]);

    char c[] = {'e', 'f', 'd', 'c', 'b', 'a'};
    int lenc = sizeof(c) / sizeof(c[0]);

    char *s[] = {"apple", "ball", "cat", "ape", "doll", "ball"};
    int lens = sizeof(s) / sizeof(s[0]);

    int *ic = sort(i, len);
    char *cc = sortc(c, lenc);
    sorts(s, lens);

    // outputs
    printf("\nsorted int\n");
    for (int i = 0; i < len; i++)
    {
        printf(" %d ", *(ic + i));
    }

    printf("\nsorted char\n");
    for (int i = 0; i < len; i++)
    {
        printf(" %c ", *(cc + i));
    }

    printf("\nsorted string\n");
    for (int i = 0; i < len; i++)
    {
        printf(" %s ", s[i]);
    };

    return 0;
}

/*
output:

sorted int
 1  2  3  4  5  6
sorted char
 a  b  c  d  e  f
sorted string
 ape  apple  ball  ball  cat  doll

*/