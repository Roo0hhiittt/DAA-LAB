#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int crossingSum(int arr[], int low, int mid, int high)
{
    int sum = 0;
    int leftSum = INT_MIN;

    for (int i = mid; i >= low; i--)
    {
        sum = sum + arr[i];

        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = INT_MIN;

    for (int i = mid + 1; i <= high; i++)
    {
        sum = sum + arr[i];

        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubarray(int arr[], int low, int high)
{
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    int left = maxSubarray(arr, low, mid);
    int right = maxSubarray(arr, mid + 1, high);
    int cross = crossingSum(arr, low, mid, high);

    return max(max(left, right), cross);
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5};
    int n = 8;

    int answer = maxSubarray(arr, 0, n - 1);

    printf("Maximum subarray sum = %d", answer);

    return 0;
}