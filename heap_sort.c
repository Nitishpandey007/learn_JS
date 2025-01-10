#include <stdio.h>

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i) {
    int largest = i;          
    int left = 2 * i;         
    int right = 2 * i + 1;  

    if (left <= n && arr[left] > arr[largest])
        largest = left;

    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
	int i;
    for (i = n / 2; i >= 1; i--)
        heapify(arr, n, i);
    for (i = n; i > 1; i--) {
        swap(&arr[1], &arr[i]);

        heapify(arr, i - 1, 1);
    }
}

void printArray(int arr[], int n) {
	int i;
    for (i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n,i;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d element\n",n);
    for(i=1;i<=n;i++)
    scanf("%d",&arr[i]);
    heapSort(arr,n);
    printf("Sorted array:\n");
    printArray(arr,n);
    return 0;
}
