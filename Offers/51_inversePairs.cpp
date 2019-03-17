#include <iostream>
#include <vector>


using namespace std;

int InversePairsCore(vector<int> &data,vector<int>& tmpdata,int l,int rn);
int InversePairs(vector<int> data)
{
    if(data.size()<=1) return 0;
    vector<int> tmpdata(data);

    int count = InversePairsCore(data,tmpdata,0,data.size()-1);
    return count;
}

int InversePairsCore(vector<int> &data,vector<int>& tmpdata,int l,int rn)
{
    if(l==rn)
    {
        tmpdata[l]=data[l];
        return 0;
    }
    int mid=l+(rn-l)/2;
    int left=InversePairsCore(data,tmpdata,l,mid);
    int right=InversePairsCore(data,tmpdata,mid+1,rn);

    int cnt=0;
    int index=rn;
    int pre=mid;
    int post=rn;
    while(pre>=l&&post>=mid+1)
    {
        if(data[pre]>data[post])
        {
            cnt=cnt+(post-mid-1+1);//当前半部分的某个数大于后半部分的post时
            //这意味着它比mid到post之间的数都大
            tmpdata[index--]=data[pre];
            pre--;
        }
        else
        {
            tmpdata[index--]=data[post];
            post--;
        }

    }
    for(;pre>=l;--pre)
        tmpdata[index--]=data[pre];
    for(;post>=mid+1;--post)
        tmpdata[index--]=data[post];
    return left+right+cnt;



}


int main()
{
    vector<int> data;
    int i;
    while(cin>>i)
    {
        data.push_back(i);
    }
    cout<<InversePairs(data);


    return 0;
}
