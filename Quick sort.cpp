#include <iostream>

using namespace std;

void get(int arr[], int);
void print(int arr[], int);
void quicksortcall(int arr[], int, int);
void quicksort(int arr[], int, int);
int partion(int arr[], int, int);

int main()
{
    int size;
    int arr[100];

    cout << "Size = ";
    cin >> size;

    get(arr, size);

    quicksortcall(arr, 0, size - 1);

    print(arr, size);
}

void get(int arr[], int count)
{
    for (int x = 0; x < count; x++)
    {
        cout << x + 1 << " - ";
        cin >> arr[x];
    }
}

void print(int arr[], int size)
{
    for (int x = 0; x < size; x++)
        cout << x + 1 << " - " << arr[x] << "\n";
}

void quicksortcall(int arr[], int from, int to)
{
    quicksort(arr, from, to);
}

void quicksort(int arr[], int from, int to)
{
    if (from < to)
    {
        int pivotindex = partion(arr, from, to);
        quicksort(arr, from, pivotindex - 1);
        quicksort(arr, pivotindex + 1, to);
    }
}

int partion(int arr[], int from, int to)
{
    int pivot = arr[to];
    int wall = from;

    for (int x = from; x <= to; x++)
    {
        if (arr[x] < pivot)
        {
            int temp = arr[wall];
            arr[x] = arr[wall];
            arr[wall] = temp;
            wall++;
        }
    }

    arr[to] = arr[wall];
    arr[wall] = pivot;

    return wall;
}