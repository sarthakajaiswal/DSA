#include <stdio.h>  // for declaration of printf() function

// Declaration of display()
void display(int arr[], int size);


int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};
    int b[3] = {1000, 2000, 3000};
    int c[8] = {100, 200, 300, 400, 500, 600, 700, 800};

    printf("Printing array a:\n");
    display(a, 5);  // Call of display()

    printf("Printing array b:\n");
    display(b, 3);  // Call of display()

    printf("Printing array c:\n");
    display(c, 8);  // Call of display()

    return (0);
}

// Definition of display()
void display(int arr[], int size)
{
    int i;

    i = 0;
    while(i < size)
    {
        printf("arr[%d]:%d\n", i, arr[i]);
        i = i + 1;
    }
}

