 #include <iostream>
 #include <vector>
 #include <algorithm>

using namespace std;
void helper(vector<vector<int>>& res,vector<int> &nums,int start)
{
    if(start==nums.size())
    {
        res.push_back(nums);
        return ;
    }
    for(int i=start;i<nums.size();++i)
    {
        swap(nums[start],nums[i]);
        helper(res,nums,start+1);
        swap(nums[start],nums[i]);
    }

}
void helper1(vector<vector<int>>& res,vector<int> nums,int start)
{
    if(start==nums.size()-1)
    {
        res.push_back(nums);
        return ;
    }
    for(int i=start;i<nums.size();++i)
    {
        if(i!=start&&nums[i]==nums[start]) continue;

        //else if(start>0&&i!=start&&nums[i]==nums[start])
          // ;
        swap(nums[start],nums[i]);
        helper1(res,nums,start+1);
       // swap(nums[start],nums[i]);}
    }

}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.empty()) return res;
    helper(res,nums,0);
    return res;

    }
vector<vector<int>> permuteUnique(vector<int>& nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    if (nums.empty()) return res;
    helper1(res,nums,0);
    return res;
}


int main()
{

    vector<int> nums;
    int num;
    while(cin>>num)
       {
    //     cout<<num<<" ";
        nums.push_back(num);
       }
 //   for(auto i:nums)
  //    cout<<i<<endl;
    vector<vector<int> >res;

    //res=permute(nums);
    res=permuteUnique(nums);
    for(int i=0;i<res.size();++i)
    {
           for(auto j:res[i])
            cout<<j<<" ";
            cout<<endl;
    }
    return 0;
}
