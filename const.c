#include <stdio.h>
#include <stdlib.h>

union employee
{
    char name[15];
    int age;
    float salary;
};

const union employee e1;

int test3(int **pptr)
{
    /* code */
    int j = 223;
    int *temp = &j;
    printf("Before pptr = 0x%08x\n", *pptr);
    *pptr = temp;
    printf("After pptr = 0x%08x\n", *pptr);
    return 0;
}

int get()
{
    /* code */
    return 20;
}

int test8(int *f)
{
    /* code */
    *f = 10;
    return 0;
}

int main(int argc, const char *argv[])
{
    // test 2
    printf("*** test3 ***\n");
    strcpy(e1.name, "K");
    printf("%s, %d, %f\n", e1.name, e1.age, e1.salary);

    // test 3
    printf("*** test3 ***\n");
    int c = 10;
    const int *ptrc = &c;
    test3(&ptrc);

    // test 4
    printf("*** test4 ***\n");
    const int a = 5;
    const int *ptra;
    ptra = &a;
    printf("Content of ptra %d\n", *ptra);
    //*ptra = 10;
    //printf("Content of ptra %d\n", *ptra);

    // test 5
    printf("*** test5 ***\n");
    int m = 10, n = 20;
    const int *ptr = &m;
    printf("Before m = %d, ptr = 0x%08x\n", *ptr, ptr);
    ptr = &n;
    printf("After  m = %d, ptr = 0x%08x\n", *ptr, ptr);
    //*ptr = n;
    //printf("After  m = %d, ptr = 0x%08x\n", *ptr, ptr);

    // test 6
    printf("*** test6 ***\n");
    const char *s = "";
    char str[] = "Hello";
    s = str;
    while(*s)
        printf("%c\n", *s++);

    // test 7
    printf("*** test7 ***\n");
    const int x = get();
    printf("%d\n", x);
    
    // test 8
    printf("*** test8 ***\n");
    const int arr[5] = {1, 2, 3, 4, 5};
    printf("Before arr[3] %d\n", arr[3]);
    //test8(&arr[3]);
    //printf("After test8 arr[3] %d\n", arr[3]);

    // test 9
    printf("*** test9 ***\n");
    const int i = 0;
    test8(&i);
    printf("%d\n", i);
    //printf("%d\n", i++);

    // test 10
    printf("*** test10 ***\n");
    const u = -11;
    const int d = 32;
    printf("%d, %d\n", u, d);
    return 0;
}
