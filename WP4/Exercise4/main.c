#include <stdio.h>

// Function to search for a number in an array.
// Returns the index of the first occurrence, or -1 if not found.
int search_number(int number, int tab[], int size) {
    for (int i = 0; i < size; i++) {
        if (tab[i] == number)
            return i;
    }
    return -1;
}

// Function to sort an array of integers in ascending order using selection sort.
// 'n' is the number of elements in the array.
void sort(int n, int tab[]) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // Find the index of the minimum element in the unsorted part.
        for (int j = i + 1; j < n; j++) {
            if (tab[j] < tab[minIndex])
                minIndex = j;
        }
        // Swap the found minimum element with the element at index i.
        if (minIndex != i) {
            int temp = tab[i];
            tab[i] = tab[minIndex];
            tab[minIndex] = temp;
        }
    }
}

int main(void) {
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    int size = sizeof(test) / sizeof(test[0]);

    // Test search_number for a number that exists.
    int target = 23;
    int index = search_number(target, test, size);
    if (index != -1)
        printf("Number %d found at index %d.\n", target, index);
    else
        printf("Number %d not found in the array.\n", target);

    // Test search_number for a number that does not exist.
    target = 99;
    index = search_number(target, test, size);
    if (index != -1)
        printf("Number %d found at index %d.\n", target, index);
    else
        printf("Number %d not found in the array.\n", target);

    // Sort the array using selection sort.
    sort(size, test);

    // Print the sorted array.
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test[i]);
    }
    printf("\n");

    return 0;
}
