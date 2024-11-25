#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quick Sort Functions
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort Functions
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main()
{
    // Example array
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int arrCopy[n];

    // Measure time taken for Quick Sort
    for (int i = 0; i < n; i++)
        arrCopy[i] = arr[i]; // Copy array for Quick Sort
    clock_t start = clock();
    quickSort(arrCopy, 0, n - 1);
    clock_t end = clock();

    printf("Sorted array using Quick Sort:\n");
    printArray(arrCopy, n);

    double time_taken_quick = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Quick Sort: %f seconds\n", time_taken_quick);

    // Measure time taken for Merge Sort
    for (int i = 0; i < n; i++)
        arrCopy[i] = arr[i]; // Copy array for Merge Sort
    start = clock();
    mergeSort(arrCopy, 0, n - 1);
    end = clock();

    printf("Sorted array using Merge Sort:\n");
    printArray(arrCopy, n);

    double time_taken_merge = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Merge Sort: %f seconds\n", time_taken_merge);

    return 0;
}
