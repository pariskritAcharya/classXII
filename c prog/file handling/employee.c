#include <stdio.h>
#include <conio.h>

typedef struct
{
    int id;
    char name[10];
    char add[5];
    float salary;
} info;

int main()
{

    FILE *fp = fopen("employee.txt", "w");
    if (fp == NULL)
    {
        printf("failed to create file");
        return 1;
    }

    int i = 0;
    char y;

    info e;

    do
    {
        e.id = i + 1;

        printf("enter name of %d:", i + 1);
        scanf("%s", e.name);

        printf("enter add of %s:", e.name);
        scanf("%s", e.add);

        printf("enter salary of %s:", e.name);
        scanf("%f", &e.salary);
        i++;
        fwrite(&e, sizeof(info), 1, fp);

    } while (getch() != 'n');
    fclose(fp);

    fp = fopen("employee.txt", "r");

    printf("\n the details of employee salary above 20k are:\n");
    info e2;
    while (fread(&e2, sizeof(info), 1, fp))
    {
        if (e2.salary > 20000)
        {
            printf("%d  %s  %s  %.2f\n", e2.id, e2.name, e2.add, e2.salary);
        }
    }

    return 0;
}

/*
output:

enter name of 1:ram
enter add of ram:llt
enter salary of ram:30000
enter name of 2:sita
enter add of sita:ktm
enter salary of sita:40000
enter name of 3:hari
enter add of hari:ktm
enter salary of hari:20000

 the details of employee salary above 20k are:
1  ram  llt  30000.00
2  sita  ktm  40000.00


*/