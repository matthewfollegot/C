#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);

int main()
{
    int v[10], i;
    for (i = 0; i < 10; i++) // [0, 4, 8, 12, 16]
        v[i] = i*2;

    int len = sizeof(v)/sizeof(v[0]);
    
    clock_t t;
    t = clock();
    printf("%d\n", binsearch(8, v, len));
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("binsearch() took %f seconds to execute\n", time_taken);
}

int binsearch(int x, int v[], int n)
{
    int mid;
    int high = n - 1;
    int low = 0;
    
    while (low <= high && x != v[mid]) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
    }

    if (x == v[mid])
        return mid;
    else
        return -1;
}
