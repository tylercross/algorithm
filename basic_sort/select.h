#ifndef SELECT_H_INCLUDED
#define SELECT_H_INCLUDED
void SimpleSeletionSort(int A[],int N)
{
   int i,j,min,temp;
    for(i=0;i<N-1;i++){
        min=i;
        for(j=i+1;j<N;j++)
            if(A[j]<A[min]) min=A[j];
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}


#endif // SELECT_H_INCLUDED
