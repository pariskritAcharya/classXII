#include <stdio.h>

struct info
{
    int id;
    char name[10];
    char add[5];
    float salary;
};

int main()
{
    int n;
    printf("enter no. of details:");
    scanf("%d", &n);

    struct info e[n];

    for (int i = 0; i < n; i++)
    {
        e[i].id = i;

        printf("enter name of %d:", i + 1);
        scanf("%s", e[i].name);

        printf("enter add of %s:", e[i].name);
        scanf("%s", e[i].add);

        printf("enter salary of %s:", e[i].name);
        scanf("%f", &e[i].salary);
    }

    printf("\n the details of employee salary above 20k are:\n");
    for (int i = 0; i < n; i++)
    {
        if (e[i].salary > 20000)
        {
            printf("%d  %s  %s  %.2f\n", e[i].id, e[i].name, e[i].add, e[i].salary);
        }
    }

    return 0;
}

/*
output:

enter no. of details:3
enter name of 1:ram
enter add of ram:ktm
enter salary of ram:30000
enter name of 2:shyam
enter add of shyam:llt
enter salary of shyam:4000
enter name of 3:sita
enter add of sita:bkt
enter salary of sita:40000

 the details of employee salary above 20k are:
0  ram  ktm  30000.00
2  sita  bkt  40000.00


*/