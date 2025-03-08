#include <stdio.h>

typedef struct
{
    int id;
    char name[20];
    float salary;
} Employee;

int main()
{
    FILE *fp = fopen("employee.bin", "wb"); // Open file in binary write mode
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    Employee e1 = {1, "Alice", 50000.0};
    Employee e2 = {2, "Bob", 60000.0};

    fwrite(&e1, sizeof(Employee), 1, fp); // Write first employee
    fwrite(&e2, sizeof(Employee), 1, fp); // Write second employee

    fclose(fp);
    printf("Data written to employee.bin\n");

    fp = fopen("employee.bin", "rb"); // Open file in binary read mode
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    Employee e;

    printf("\nEmployee Details:\n");
    while (fread(&e, sizeof(Employee), 1, fp))
    { // Read one structure at a time
        printf("ID: %d, Name: %s, Salary: %.2f\n", e.id, e.name, e.salary);
    }

    fclose(fp);
    remove("employee.bin");
    return 0;
}

/*

output:

Employee Details:
ID: 1, Name: Alice, Salary: 50000.00
ID: 2, Name: Bob, Salary: 60000.00
*/
