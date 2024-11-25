#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function for Linear Search
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Element found
        }
    }
    return -1; // Element not found
}

// Function for Binary Search (requires sorted array)
int binarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
        {
            return mid; // Element found
        }

        // If target is greater, ignore left half
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else
        {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    // Example array
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    // Linear Search
    clock_t start = clock();
    int linearResult = linearSearch(arr, n, target);
    clock_t end = clock();
    double time_taken_linear = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Output results for Linear Search
    if (linearResult != -1)
    {
        printf("Element found at index %d using Linear Search.\n", linearResult);
    }
    else
    {
        printf("Element not found using Linear Search.\n");
    }
    printf("Time taken for Linear Search: %f seconds\n", time_taken_linear);

    // Binary Search
    start = clock();
    int binaryResult = binarySearch(arr, n, target);
    end = clock();
    double time_taken_binary = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Output results for Binary Search
    if (binaryResult != -1)
    {
        printf("Element found at index %d using Binary Search.\n", binaryResult);
    }
    else
    {
        printf("Element not found using Binary Search.\n");
    }
    printf("Time taken for Binary Search: %f seconds\n", time_taken_binary);

    return 0;
}
