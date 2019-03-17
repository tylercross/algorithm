#include <iostream>
#include <string>
#include <vector>
using namespace std;
string getPermutation(int n, int k) {
    string res;
    vector<int> used(10,0);
    int way=1;
    for(int i=1;i<n;i++)
        way *=i;
    for(int i=0;i<n;i++)
    {
        int index=1;
        if(i==n-1)
            index=1;
        else
        while(k>way)
        k-=way,index+=1;

        for(int i=1;i<=n;i++)
            if(used[i]==0){
                index-=1;
                if(index==0){
                    used[i]=1;
                    res+='0'+i;
                    break;
                }
            }
        if(n-i-1!=0)
            way/=(n-i-1);

    }
    return res;

}
int main()
{

    int n,k;
    cin>>n>>k;
    cout<<getPermutation(n,k);

    return 0;
}
