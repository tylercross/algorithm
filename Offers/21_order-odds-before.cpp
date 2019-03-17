#include<iostream>
#include<vector>


using namespace std;


void reOrderArray(vector<int> &array) {
        int left=0,right=array.size()-1;
        while(left<right)
        {
            while(left<right&&(array[left]&0x1)) left++;
            while(left<right&&(array[right]&0x1)==0) right--;
            if(left<right) swap(array[left],array[right]);
        }
        return ;
    }


int main()
{
    vector<int> nums={2,1,3,4};
    for(auto i:nums)
        cout<<i<<" ";
    cout<<endl;
    reOrderArray(nums);
    for(auto i:nums)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
