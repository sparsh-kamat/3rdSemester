//show all sorting algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selection_sort_nonrecursive(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}



void insertion_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//heap sort
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heap_sort(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

//quick sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

//radix sort
int getMax(int arr[], int n)
{
    int mx = arr[0];
    int i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radix_sort(int arr[], int n)
{
    int m = getMax(arr, n);
    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

//bucket sort
void bucket_sort(int arr[], int n)
{
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        (count[arr[i]])++;
    }
    for (i = 0, j = 0; i < n; i++)
    {
        for (; count[i] > 0; (count[i])--)
        {
            arr[j++] = i;
        }
    }
}

//shell sort
void shell_sort(int arr[], int n)
{
    int gap = n / 2;
    int i, j, temp;
    while (gap > 0)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}



void print_array(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    print_array(arr, n);
    //bubble_sort(arr, n);
    //selection_sort(arr, n);
    //insertion_sort(arr, n);
    //merge_sort(arr, 0, n - 1);
    //heap_sort(arr, n);
    //quick_sort(arr, 0, n - 1);
    //radix_sort(arr, n);
    //bucket_sort(arr, n);
    //shell_sort(arr, n);
    printf("Sorted array is \n");
    print_array(arr, n);
    return 0;
}

