int binary_search(int x, int *arr, int len)
{
    int low = 0, high = len - 1, mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

// Binary Search for 1st ocurrence
int binary_search_1st(int x, int *arr, int len)
{
    int low = 0, high = len - 1, mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else if (low != mid)
            high = mid;
        else
            return mid;
    }
    return -1;
}
