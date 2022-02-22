template <class T>
void quicksort(T arr[], int low, int high)
{
    if (low >= high)
        return;

    int left = low, right = high, pivot = arr[(high + low) / 2];
    while (left <= right)
    {
        while (arr[left] < pivot)
            left++;
        while (arr[right] > pivot)
            right--;

        int temp = arr[left];
        arr[left++] = arr[right];
        arr[right--] = temp;
    }

    quicksort<T>(arr, low, right);
    quicksort<T>(arr, left, high);
}