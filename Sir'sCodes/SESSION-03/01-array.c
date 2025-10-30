#include <stdio.h>

void display(int arr[], int size);

int main(void)
{
    int a[8] = {-15, -5, -8, 20, 10, 50, 40, 80};

    printf("ARRAY BEFORE SHIFTING POSITIVE NUMBERS TO THE RIGHT:\n");
    display(a, 8);

    int tmp = a[7]; // save the last indexed element in tmp variable
    int i = 6;      // initialize i to the second last element

    // Keep shifting array elements to their right index
    // until negative element is encountered
    // Assumptions: There is at least one negative number
    while(a[i] >= 0)
    {
        a[i+1] = a[i];
        i = i - 1;
    }
    a[i+1] = tmp;   // Save the last indexed element
                    // at the first positive index
    printf("ARRAY AFTER SHIFTING POSITIVE NUMBERS TO THE RIGHT:\n");
    display(a, 8);

    return (0);
}

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
