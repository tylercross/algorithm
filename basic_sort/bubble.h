#ifndef BUBBLE_H_INCLUDED
#define BUBBLE_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
void printf(vector<int> a, int count);
void BubbleSort(vector<int> &a, int N)
{
    int i,j;
    bool flag;
    for(i=N-1;i>=0;i--)
    {
        flag=0;
        for(j=0;j<i;j++){
            if (a[j]>a[j+1]) {
                swap(a[j],a[j+1]);
                flag=1;
            }
        }
        if(!flag) break;
        cout<<"The"<<i<<"round:"<<std::endl;
        printf(a,N);
    }
}
void printf(vector<int> a, int count)
{
    for (int i = 0; i< count; i++)
    {
        cout << a[i] <<" ";
    }
    cout << endl;
}


#endif // BUBBLE_H_INCLUDED
