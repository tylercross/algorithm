#include <iostream>

#include <vector>

using namespace std;
bool canbedivided(const int& num)
{
    int temp=num;
    while(temp>0)
    {
        int t=temp%10;
        if(t==0||num%t!=0) return false;
        temp/=10;
    }
   // cout<<num<<" Y"<<endl;
    return true;
}
vector<int> selfDividingNumbers(int left, int right) {
      vector<int> res;
      for(int i=left;i<=right;++i)
      {
        bool flag=canbedivided(i);
        if(flag)
            {res.push_back(i);}
      }

      return res;
    }




int main()
{
    int i,j;
   // cin>>i>>j;
   vector<int> ress;
    ress=selfDividingNumbers(1,10);
    for(auto &i:ress)
      {
         cout<<i<<endl;

      }
//   int num;
 //   cin>>num;
  //  canbedivided(num);

 //   cout<<firstUniqChar(s)<<endl;
     return 0;
}
