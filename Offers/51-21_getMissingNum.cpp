#include <iostream>
#include <vector>


using namespace std;

    int getMissingNumber(vector<int> data) {
        if(data.empty()) return 0;
        int begin=0,end=data.size()-1;
        int mid;
        //int left=1,right=0;
        while(begin<=end)
        {
            mid=begin+(end-begin)>>1;
            if(data[mid]!=mid)
                {
                    if(mid==0||mid-1==data[mid-1])
                        return mid;
                    end=mid-1;
                }
            else
                    begin=mid+1;
        }
        if(begin==data.size())
            return data.size();
        return -1;

    }

int main()
{
    vector<int> data;
    int i;
    while(cin>>i)
    {
        data.push_back(i);
    }

    cout<<getMissingNumber(data);


    return 0;
}
