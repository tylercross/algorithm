#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED
void Merge (vector<int> &A, vector<int> &tmpA,int L, int R, int RN )
{
    int LN=R-1;
    int tmp=L;
    int Num_Elements=RN-L+1;
    while(L<=LN&&R<=RN)
    {
        if(A[L]<=A[R]) tmpA[tmp++]=A[L++];
        else           tmpA[tmp++]=A[R++];
    }
        while(L<=LN) tmpA[tmp++]=A[L++];
        while(R<=RN) tmpA[tmp++]=A[R++];
        for(int i=0;i<Num_Elements;i++,RN--)
            A[RN]=tmpA[RN];
}

void MSort(vector<int> &A,vector<int> &tmpA, int L, int RN)
{
    int Center;
    if(L<RN){
        Center = (L+RN)/2;
        MSort(A,tmpA, L,Center);
        MSort(A,tmpA, Center+1,RN);
        Merge(A,tmpA,L,Center+1,RN);
    }
}

void Merge_Sort(vector<int> &A, int N)
{
    vector<int> tmpA(N,0);
    if(!tmpA.empty())
    {
        MSort(A,tmpA,0,N-1);
      //  free(tmpA)
    }
  //  else Error("�ռ䲻��");
}

//-----�����㷨
void Merge1 (vector<int> &A, vector<int> & tmpA,int L, int R, int RN )
{
    int LN=R-1;
    int tmp=L;
//    int Num_Elements=RN-L+1;
    while(L<=LN&&R<=RN)
    {
        if(A[L]<=A[R]) tmpA[tmp++]=A[L++];
        else           tmpA[tmp++]=A[R++];
    }
        while(L<=LN) tmpA[tmp++]=A[L++];
        while(R<=RN) tmpA[tmp++]=A[R++];

}
void Merge_pass(vector<int> &A,vector<int> & tmpA, int N, int length)
{
    int i,j;
    for(i=0;i<=N-2*length;i+=2*length)//��Ϊ���һ��������ӣ�����������ִ�е������ڶ��Ծͽ���
        Merge1(A,tmpA,i,i+length,i+2*length-1);
    if (i+length<N)//�������гɶ�
        Merge1(A,tmpA,i,i+length,N-1);
    else
        for(j=i;j<N;j++) tmpA[j]=A[j];
}

void Merge_Sort_pass(vector<int> &A, int N)
{
    vector<int> tmpA(N,0);
    int length=1;
    if(!tmpA.empty())
    {  while(length<N){
        Merge_pass(A,tmpA,N,length );

        length*=2;
        Merge_pass(tmpA,A,N,length);
        length*=2;
      //  free(tmpA)
    }
    }
  //  else Error("�ռ䲻��");
}
//�鲢�����ȶ������Ӷ�ΪNlogN��������Ҫ�����Ŀռ䣬������������

#endif // MERGE_H_INCLUDED
