#include <stdio.h>

typedef struct
{
    int a;
    int b;
} z;

z add_z(z w1, z w2)
{
    z wSum = {.a = w1.a + w2.a, .b = w1.b + w2.b};
    return wSum;
}

int main()
{

    z w1 = {.a = 6, .b = 3};
    z w2 = {.a = 3, .b = 2};

    z wSum = add_z(w1, w2);
    printf("(%d,%d) + (%d,%d) = (%d,%d)", w1.a, w1.b, w2.a, w2.b, wSum.a, wSum.b);

    return 0;
}

/*

output
(6,3) + (3,2) = (9,5)


*/