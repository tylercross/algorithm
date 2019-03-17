 #include <iostream>
 #include <vector>
 #include <algorithm>

using namespace std;
int min_nums(const vector<int>& nums,int j)
{
    int min=nums[j], pos=0;
    for(int i=j;i<nums.size();++i)
        if(nums[i]<min){min=nums[i];pos=i;}
    return pos;

}
void nextPermutation0(vector<int>& nums) {
    int i=0,j=nums.size()-1,pos,min_pos;
    while(i<j)
    {
        if(nums[j]>nums[j-1])
        {   if(j<nums.size()-1)
          {
              pos=min_nums(nums,j);
              if(nums[pos]>nums[j-1]) min_pos=j-1;
              else min_pos=j;
              swap(nums[pos],nums[min_pos]);
              return ;
          }
             else if(j==nums.size()-1)
             {

              swap(nums[j],nums[j-1]);
              return ;

             }
        }
        else
            j--;
    }
    j=nums.size()-1;
    while(i<j)
    {
        swap(nums[i++],nums[j--]);

    }
}
void nextPermutation(vector<int>& nums) {
    int n= nums.size(),k,l;
    for(k = n-2;k>=0;k--)
    {
        if(nums[k]<nums[k+1]) break;
    }

    if(k<0) reverse(nums.begin(),nums.end());
    else
  {
        for(l=n-1;l>k;l--)
    {
        if(nums[l]>nums[k]) break;

    }
    swap(nums[k],nums[l]);
    reverse(nums.begin()+k+1,nums.end());
  }
}
/* 这是个非常经典的数学问题，推荐记忆
1、找出num[k]<nums[k+1]的最大k,如果k<0那么，直接翻转；
2、从右边寻找nums[l]>nums[k], 交换
3、从k+1开始逆序。


*/
int main()
{

    vector<int> nums;
    int num;
    while(cin>>num)
       {
          nums.push_back(num);
       }
    nextPermutation(nums);
    //cout<<min_nums(nums,0);
    for(auto i:nums)
            cout<<i<<" ";


    return 0;
}
