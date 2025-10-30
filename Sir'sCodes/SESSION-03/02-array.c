/*
    @goal:  You will be given a non-empty array of integers.
            The array is filled in such a way that all negative
            numbers are stacked on the left side of the array
            and all non-negative numbers are stacked on the right
            side of the array.

            Your job is to right shift and rotate all non-negative elements.

    @boundary case: There may not be any negative element, in that case
                    the entire array will be right shifted and rorated.
*/


#include <stdio.h>

void display(int arr[], int size);
void right_shift_and_rotate(int arr[], int size);

int main(void)
{
    int a[8] = {-10, -5, -8, -3, 30, 40, 20, 10};
    int b[8] = {30, 10, 2, 25, 30, 16, 28, 40};

    printf("Showing array \'a\' BEFORE right shift and rotate:\n");
    display(a, 8);
    right_shift_and_rotate(a, 8);
    printf("Showing array \'a\' AFTER right shift and rotate:\n");
    display(a, 8);

    printf("Showing array \'b\' BEFORE right shift and rotate:\n");
    display(b, 8);
    right_shift_and_rotate(b, 8);
    printf("Showing array \'b\' AFTER right shift and rotate:\n");
    display(b, 8);

    return (0);
}

void right_shift_and_rotate(int arr[], int size)
{
    int tmp = arr[size-1];
    int i = size - 2;

    while(i >= 0 && arr[i] > 0)
    {
        arr[i+1] = arr[i];
        i = i - 1;
    }

    arr[i+1] = tmp;
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
