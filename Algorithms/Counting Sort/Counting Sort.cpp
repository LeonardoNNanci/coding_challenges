void counting_sort(int arr[], int min, int max, int n)
{
    int range = max - min + 1, acc = 0;
    int count[range] = {0};

    for (int i = 0; i < n; i++)
    {
        int index = arr[i] - min;
        count[index]++;
    }

        for (int i = 0; i < range; i++)
        for (int j = 0; j < count[i]; j++)
        {
            arr[acc++] = min + i;
        }
}
