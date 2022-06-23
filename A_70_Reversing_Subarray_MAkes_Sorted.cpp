bool checkReverse(int arr[], int n)
{
    if (n == 1)
        return true;
 
    // Find first increasing part
    int i;
    for (i=1; i < n && arr[i-1] < arr[i]; i++);
    if (i == n)
        return true;
 
    // Find reversed part
    int j = i;
    while (j < n && arr[j] < arr[j-1])
    {
        if (i > 1 && arr[j] < arr[i-2])
            return false;
        j++;
    }
 
    if (j == n)
        return true;
 
    // Find last increasing part
    int k = j;
 
    // To handle cases like {1,2,3,4,20,9,16,17}
    if (arr[k] < arr[i-1])
       return false;
 
    while (k > 1 && k < n)
    {
        if (arr[k] < arr[k-1])
            return false;
        k++;
    }
    return true;
}
