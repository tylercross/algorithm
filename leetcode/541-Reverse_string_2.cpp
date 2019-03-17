 #include <iostream>


using namespace std;
 void reversesubstr(string&s,int left,int right)
 {
     while(left<right)
     {
         char t;
         t=s[left];
         s[left++]=s[right];
         s[right--]=t;
        // left++;
       //  right--;
     }

 }
 string reverseStr(string s, int k) {
      string res=s;
     // if(k>res.size()) reversesubstr(res,0,res.size()-1);
   //   else
      for(int i=0;i<s.size();i+=2*k)
      {
          if(i+k-1<s.size())
          reversesubstr(res,i,i+k-1);
          else
            reversesubstr(res,i,s.size()-1);
     //     cout<<i<<endl;

      }
      return res;
    }

int main()
{
    int k;
    string str;
  //  cin>>str;
  //  reversesubstr(str,0,2);
   // cout<<str<<endl;
   cin>>str>>k;
    cout<<reverseStr(str,k)<<endl;
    return 0;
}
