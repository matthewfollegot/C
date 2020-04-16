#include <stdio.h>
#include <string.h>

void quick_sort(int v[], int left, int right);

int main()
{
    int nums[] = { 11, 23, 83, 90, 45, 56, 70, 21, 68, 7 };
    quick_sort(nums, 0, sizeof(nums)/sizeof(nums[0]) - 1);
    
    for (int i = 0; i < sizeof(nums)/sizeof(nums[i]); i++)
        printf("%d ", nums[i]);
    printf("\n");
}

/* quick_sort: sort v[left], v[right] into increasing order */
void quick_sort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return; /* do nothing if array contains less than 2 elements */
    swap(v, left, (left + right) / 2); /* move partition elem to v[0] */
    last = left;
    for (i = left + 1; i <= right; i++) /* partition */
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    quick_sort(v, left, last-1);
    quick_sort(v, last+1, right);
}

/* swap: interchange v[i] with v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
