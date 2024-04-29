#include <stdio.h>

int main()
{
    int arr[100];
    int n, pos, newVal, i;

    // Take user input for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Take user input for the array elements
    printf("Enter %d elements for the array:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Take user input for the position
    printf("Enter the position at which the element is to be inserted: ");
    scanf("%d", &pos);

    // Check if position is valid
    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid position!\n");
        return 1; // exit with error
    }

    // Take user input for the new value
    printf("Enter the new value to be inserted: ");
    scanf("%d", &newVal);

    // increase the size by 1
    n++;

    // shift elements forward
    for (i = n - 1; i >= pos; i--)
        arr[i] = arr[i - 1];

    // insert newVal at pos
    arr[pos - 1] = newVal;

    // print the updated array
    printf("Updated array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
