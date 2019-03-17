#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int elevator(int N,int K,vector<int> P)
{
    if(N==0||K==0||P.empty()||N!=P.size()) return 0;
    int numP=P.size();
    //sort(P.begin(),P.end());
    int counter=0;
    if(N<=K) return (P[numP-1])*2;
    else
    {
        int group_num=N/K;
        if (group_num*K!=N) group_num++;

        for(int i=group_num,j=numP-1;i>0;i--,j-=K)
        {
            counter += (P[j]-1)*2;

        }
    }
    return counter;
}

int main()
{
    int N,K;
    cin>>N>>K;
    vector<int> P;
    int i;
    for(int j=0;j<N;j++)
    {

      cin>>i;
        P.push_back(i);
    }
    cout<<elevator(N,K,P);
    return 0;

}
