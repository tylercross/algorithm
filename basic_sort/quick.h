#ifndef QUICK_H_INCLUDED
#define QUICK_H_INCLUDED
#include<vector>
/*

int Median3(vector<int>& A,int left,int right)
{
    int center =(left+right)/2;
    if(A[left]>A[center]) swap(A[left],A[center]);
    if(A[left]>A[right]) swap(A[left],A[right]);
    if(A[center]>A[right]) swap(A[center],A[right]);
    swap (A[center],A[right-1]);//将Privot放在倒数第二位，将未排序的数据放在一个连续区间
    return A[right-1];

}
void Quicksort(vector<int>& A,int left, int right )
{
    int Cutoff=1;
    if(Cutoff<=right-left)
    {
        int Privot=Median3(A,left,right);
     //  int Privot=(left+right)/2;
        int i=left;
        int j=right-1;
        while(1)
        {
            while(A[++i]<Privot){}
            while(A[--j]>Privot){}
            if(i<j)
            swap(A[i],A[j]);
            else break;
        }
        swap(A[i],A[right-1]);
        Quicksort(A,left,i-1);
        Quicksort(A,i+1,right);

    }
    else
        ;
    //InsertSort(A, right-left+1);
}

// QUICK_H_INCLUDED
void Quick_sort(vector<int> &A,int N)
{

    Quicksort(A,0,N-1);
}
*/
int partition(vector<int> &arr, int left, int right)  //找基准数 划分
{
    int i = left + 1 ;
    int j = right;
    int temp = arr[left];

    while(i <= j)
    {
        while (arr[i] < temp)
        {
            i++;
        }
        while (arr[j] > temp )
        {
            j--;
        }
        if (i < j)
            swap(arr[i++], arr[j--]);
        else i++;
    }
    swap(arr[j], arr[left]);
    return j;

}

void quick_sort(vector<int> &arr, int left, int right)
{
    if (left > right)
        return;
    int j = partition(arr, left, right);
    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}

void Quick_sort(vector<int> &A,int N)
{

    quick_sort(A,0,N-1);
}




#endif
