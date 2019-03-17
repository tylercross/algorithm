#include <iostream>
#include <vector>


using namespace std;

    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        int begin=0,end=data.size()-1;
        int left=1,right=0;
        while(begin<=end)
        {
            int mid=begin+(end-begin)/2;
            if(data[mid]<k){begin=mid+1;}
            else if(data[mid]>k) {end=mid-1;}
            else if(data[mid]==k)
            {
                left=mid,right=mid;
                while(data[left-1]==k&&left>0) left--;
                while(data[right+1]==k&&right<data.size()-1) right++;
                break;

            }

        }
        if(left==1&&right==0) return 0;
        else
        return right-left+1;
    }

int main()
{
    vector<int> data;
    int i,k;
    while(cin>>i)
    {
        data.push_back(i);
    }
    k=2;
    cout<<GetNumberOfK(data,k);


    return 0;
}
