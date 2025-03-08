#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int a[], int n);
void sort_function(int a[], int n);
void sort_pointer(int *a, int n);
int main()
{
    int n;
    printf("enter total number you want to enter:");
    scanf("%d", &n);
    int a[n];

    // input array of numbers
    for (int i = 0; i < n; i++)
    {
        switch (i + 1)
        {
        case 1:
            printf("enter 1st number");
            break;
        case 2:
            printf("enter 2nd number");
            break;
        case 3:
            printf("enter 3rd number");
            break;
        default:
            printf("\nenter %dth number:", i + 1);
            break;
        }
        scanf("%d", &a[i]);
    }
    system("cls");
    printf("initial numbers:");
    print(a, n);

    // three copies of a
    int a_cpy1[n];
    memcpy(a_cpy1, a, n * sizeof(a[0]));

    int a_cpy2[n];
    memcpy(a_cpy2, a, sizeof(a));

    int a_cpy3[n];
    for (int i = 0; i < n; i++)
    {
        a_cpy3[i] = a[i];
    }

    // bubble sorting by loop

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a_cpy1[i] > a_cpy1[j])
            {
                a_cpy1[i] += a_cpy1[j];
                a_cpy1[j] = a_cpy1[i] - a_cpy1[j];
                a_cpy1[i] = a_cpy1[i] - a_cpy1[j];
            }
        }
    }

    printf("\nrequired sorted form from loop is:");
    print(a_cpy1, n);

    // bubble sorting by function
    sort_function(a_cpy2, n);

    // bubble sorting by pointer
    sort_pointer(a_cpy3, n);
    printf("\nrequired sorted form from pointer function is:");
    print(a_cpy3, n);
    printf("\n");

    return 0;
}

// functions
void print(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

// sorting with function
void sort_function(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nrequired descending from function is:");

    print(a, n);
}

// sorting using pointer function
void sort_pointer(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(a + i) > *(a + j))
            {
                int temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}

/*

output:
initial numbers:2 3 1 4
required sorted form from loop is:1 2 3 4
required descending from function is:4 3 2 1
required sorted form from pointer function is:1 2 3 4


*/