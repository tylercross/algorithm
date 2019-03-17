#include <iostream>
#include <vector>


using namespace std;
   bool isUgly0(int num) {
        if(num<=0) return false;
        if(num==1||num==2||num==3||num==5) return true;
        else if(isUgly0(num/5*5==num?num/5:0)||\
                isUgly0(num/3*3==num?num/3:0)||isUgly0(num/2*2==num?num/2:0)) return true;
        return false;
    }
    bool isUgly1(int num) {
        while(num%2==0) num/=2;
        while(num%3==0) num/=3;
        while(num%5==0) num/=5;
        return  (num==1)?true:false;

    }
    int nthUglyNumber0(int n) {
        if(n<=0) return 0;
        int count=0;
        int num=1;
        vector <int> dict;
        while(count<n)
        {
            if(isUgly1(num++)) {count++; }
          //  else num++;
        }
        return num-1;
    }
    int nthUglyNUmber1(int n)
    {

        if(n<=0) return 0;
        int count=0;
        int num=1;
        vector <int> dict;
        while(count<n)
        {
            int temp=count;
            while(num%2==0) num/=2;
            while(num%3==0) num/=3;
            while(num%5==0) num/=5;
      //      if (num==1)?dict[n]=count:n++;

          //  else num++;
        }
        return num-1;

    }


int main()
{
    int num;
 //   cin>>num;
  //  cout<<isUgly1(num)<<endl;
  // int n;
  // cin>>n;
  // cout<<nthUglyNumber(n);
  vector<int> dict(5,1);
  vector<int>*p =&dict;
  cout<<p[1]<<endl;
  for(auto i:dict)
  {
      cout<<i<<endl;
  }
    return 0;
}
