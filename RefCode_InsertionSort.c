#include <stdio.h>

#define MAX 10

void printArray(int N, int *A)
{
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int N, int *A)
{
    int j, v; // v = component of array, j = start point of comparing
    for (int i = 1; i < N; i++) { // A[0] is sorted
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) { // j follows i, and should not under 0 since it's index
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;

        // prints array
        printArray(N, A);
    }
}

int main()
{
    int N = 6;
    int arr[MAX] = {5, 2, 4, 6, 1, 3};

    //scanf("%d", &N);
    //for (int i = 0; i < N; i++)
    //    scanf("%d", &arr[i]);

    printArray(N, arr);
    insertionSort(N, arr);
}