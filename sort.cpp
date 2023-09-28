#include <iostream>
#include <cstring>

using namespace std;

void Print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }

    Print(a, n);
}

void op_BubbleSort(int a[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        cnt++;
        if (!flag)
            break;
    }

    cout << cnt << '\n';
    Print(a, n);    
}

void SelectSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int t = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[t]) t = j;
        }
        if(t != i)
            swap(a[i], a[t]);
    }

    Print(a, n);
}

void op_SelectSort(int a[], int n)
{
    int l = 0, r = n - 1;
    while(l < r)
    {
        int minpos = l, maxpos = r;
        for (int j = l ; j <= r; j++)
        {
            if (a[j] < a[minpos]) minpos = j;
            if (a[j] > a[maxpos]) maxpos = j;
        }
        if(minpos != l)
            swap(a[l], a[minpos]);
        //如果最大值的位置在l处，而且l处已经被交换了，所以maxpos需要修改为minpos
        if(maxpos == l) maxpos = minpos;
        if(maxpos != r)
            swap(a[r], a[maxpos]);
        l ++, r --;
    }

    Print(a, n);
}

void InsertSort(int a[], int n)
{
    for(int i = 1; i < n; i ++)
    {
        int temp = a[i];
        int j;
        for(j = i - 1; j >=0; j --)
        {
            if(a[j] > temp)
            {
                a[j + 1] = a[j];
            }
            else break;
        }
        a[j + 1] = temp;
    }

    Print(a, n);
}

void op_InsertSort(int a[], int n)
{
    Print(a, n);
    //优化：1.寻找插入时用二分，2.将数据链表化，移动更方便快捷，3.希尔排序
}

void groupsort(int *a, int n, int start, int step)
{
    for(int i = start + step; i < n; i += step)
    {
        int temp = a[i];
        int j;
        for(j = i - step; j >=0; j -= step)
        {
            if(a[j] > temp)
            {
                a[j + step] = a[j];
            }
            else break;
        }
        a[j + step] = temp;
    }

}
void ShellSort(int a[], int n)
{
    for(int step = n / 2; step > 0; step /= 2)
    {
        for(int i = 0; i < step; i ++)
        {
            groupsort(a, n, i, step);
        }
    }

    Print(a, n);
}

void quickSort(int a[], int l, int r)
{
    if(l >= r) return;
    int x = a[(l + r) >> 1];
    int i = l - 1, j = r + 1;
    while(i < j)
    {
        do i ++ ; while(a[i] < x);
        do j -- ; while(a[j] > x);
        if(i < j) swap(a[i], a[j]);
    }
    quickSort(a, l, j);
    quickSort(a, j + 1, r);
}
void QuickSort(int a[], int n)
{
    quickSort(a, 0, n - 1);
    Print(a, n);
}

int temp[20];
void mergeSort(int a[], int l, int r)
{
    if(l >= r) return;
    int mid = (l + r) >> 1;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);

    int i = l, j = mid + 1;
    int k = 0;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];
    for(int i = l, j = 0; i <= r; i ++, j ++) a[i] = temp[j]; 
}
void MergeSort(int a[], int n)
{
    mergeSort(a, 0, n - 1);
    Print(a, n);
}

// start  待排树的节点下标， end待排序数组最后一个元素的下标 
void heapify(int a[], int start, int end)
{
    int dad = start; //父节点
    int son = start * 2 + 1; // 左子节点

    while(son <= end)
    {
        if((son + 1 <= end) && a[son] < a[son + 1]) son ++;
        if(a[dad] < a[son]) 
        {
            swap(a[dad], a[son]);
            dad = son;
            son = dad * 2 + 1;
        }
        else return;
    }
}
void HeapSort(int a[], int n)
{
    for(int i = (n - 1) / 2; i >= 0; i --) heapify(a, i, n - 1);
    for(int i = n - 1; i > 0; i --)
    {
        swap(a[0], a[i]);
        heapify(a, 0, i - 1);
    }
    Print(a, n);
}

void CountSort(int a[], int n)
{
    int ma = INT_MIN;
    for(int i = 0; i < n; i ++) ma = max(ma, a[i]);
    int temp[ma + 1];
    memset(temp, 0, sizeof(temp));

    for(int i = 0; i < n; i ++) temp[a[i]]++;

    int k = 0;
    for(int i = 0; i < ma + 1; i ++)
    {
        for(int j = 0; j <temp[i]; j ++)
            a[k++] = i;
    }
    Print(a, n);
}

//优化空间
void op_CountSort(int a[], int n)
{
    int ma = INT_MIN;
    int mi = INT_MAX;
    for(int i = 0; i < n; i ++) ma = max(ma, a[i]), mi = min(mi, a[i]);
    int temp[ma - mi + 1];
    memset(temp, 0, sizeof(temp));

    for(int i = 0; i < n; i ++) temp[a[i] - mi]++;

    int k = 0;
    for(int i = 0; i < ma - mi + 1; i ++)
    {
        for(int j = 0; j <temp[i]; j ++)
            a[k++] = i + mi;
    }
    Print(a, n);
}

void BucketSort(int a[], int n)
{
    int bucket[5][10]; // 分配5个桶(根据实际情况调整桶的个数和大小)
    int bucketSize[5]; // 每个桶中元素个数计数器

    memset(bucket, 0, sizeof(bucket));
    memset(bucketSize, 0, sizeof(bucketSize));
    for(int i = 0; i < n; i ++)
    {
        int x = a[i] / 10;
        bucket[x][bucketSize[x]++] = a[i];
    }

    for(int i = 0; i < 5; i ++) quickSort(bucket[i], 0, bucketSize[i] - 1);

    int k = 0;
    for(int i = 0; i < 5; i ++)
    {
        for(int j = 0; j < bucketSize[i]; j ++)
        {
            a[k ++ ] = bucket[i][j];
        }
    }

    Print(a, n);
}

void radixsort(int a[], int n, int cnt)
{
    int res[n];
    int bucket[10] = {0};
    for(int i = 0; i < n; i ++)
    {
        bucket[a[i]/cnt%10] ++; 
    }

    for(int i = 1; i < 10; i ++)
    {
        bucket[i] = bucket[i - 1] + bucket[i];
    }

    for(int i = n - 1; i >= 0; i --)
    {
        int e = a[i] / cnt % 10;
        res[bucket[e] - 1] = a[i];
        bucket[e] --;
    }

    memcpy(a, res, n * sizeof(int));
}
void CardinalSort(int a[], int n)
{
    int ma = INT_MIN;
    for(int i = 0; i < n; i ++) ma = max(ma, a[i]);

    for(int i = 1; ma / i > 0;  i *= 10)
    {
        radixsort(a, n, i);
    }

    Print(a, n);
}

int main()
{
    // int a[15] = {8, 15, 5, 12, 6, 11, 4, 1, 13, 7, 2, 14, 3, 9, 10};
    int a[] = {144,203,738,905,347,215,836,26,527,602,946,504,219,750,848};

    CardinalSort(a, 15);
    return 0;
}