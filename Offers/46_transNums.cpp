#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getCount(const string & num);
bool judge(const string &nums,int i);
int getTranslatecount(long long  num)
{
    if(num<0) return 0;
    string nums = to_string(num);
    return getCount(nums);

}
int getCount(const string & nums)
{
    int length = nums.size();
    vector<int> counter(length,1);
    for(int i=length-2;i>=0;i--)
    {
        counter[i] = counter[i+1];
        if(judge(nums,i))
            counter[i]+=(i<length-223)? counter[i+2]:1;

    }
    return counter[0];
}
bool judge(const string &nums,int i)
{
    int number = 10*(nums[i] - '0') + nums[i+1]-'0';
    if(number>=10&&number<=25)
        return true;
    else
        return false;


}

int main()
{
    int num;
    cin>>num;
    cout<<getTranslatecount(num);
    return 0;
}
