#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cmn(vector<vector<int>>&res,vector<int> &nums,int start,  int length)
{
    if(start==nums.size()||length==0)
    {
        res.push_back(vector<int> (nums.begin()+start,);
        return;

    }
    for(int i=start;i<nums.size();++i)
    {
        swap(nums[start],nums[i]);
        cmn(res,nums,start+1,length-1);
        swap(nums[start],nums[i]);
    }
}

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> P;
    int i;
    for(int j=0;j<N;j++)
    {

        cin>>i;
        P.push_back(i);
    }
    vector<vector<int>> res;
    cmn(res,P,0,M);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[0].size();j++)
          cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;

}
