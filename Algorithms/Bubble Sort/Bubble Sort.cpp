template <class T>
void bubble_sort(T arr[], int n)
{
    int count = INT_MAX;
    for (int i = 0; i < n - 1 && count > 0; i++)
    {
        count = 0;
        for (int j = 0; j < n - 1; j++)
            if (arr[j] > arr[j + 1]) // increasing or decreasing order
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
    }
}