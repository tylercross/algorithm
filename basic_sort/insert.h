#ifndef INSERT_H_INCLUDED
#define INSERT_H_INCLUDED
#include<vector>
void InsertSort(vector<int> &A, int N)
{
    int i,j,tmp;
    for( i=1;i<N;i++){
        tmp=A[i];
        for(j=i;j>=1&&A[j-1]>tmp;j--)
            A[j]=A[j-1];
        A[j]=tmp;
    }

}
void ShellSort(vector<int>&  A, int N)
{
    int i,j,tmp,D;
    for (D=N/2;D>0;D/=2){
        for(i=D;i<N;i++){//从D开始逐一插入，并按照D的距离进行插入排序
            tmp=A[i];
            for(j=i;j>=D&&A[j-D]>tmp;j-=D)
                A[j]=A[j-D];
            A[j]=tmp;
    }
    }
}

#endif // INSERT_H_INCLUDED
