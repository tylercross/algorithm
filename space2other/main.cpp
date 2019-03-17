#include <iostream>

using namespace std;

int counter_space(const string & str)
{
    int counter=0;
    for(int i=0;i<str.size();++i)
    {
        if(str[i]==' ') counter++;

    }
    return counter;
}
string space2other(string &str,const string& target)
{   int old_length=str.size();
    int target_length=target.size();
    int new_length=old_length+counter_space(str)*(target.size()-1);
    string res(new_length,' ');
    cout<<new_length<<endl;
    int i,j;
    for(i=new_length-1,j=old_length-1;i>=0&&j>=0;--i,--j)
    {

        if(str[j]!=' ')  res[i]=str[j];
        else
      {
            int ii,jj;
            for(ii=i,jj=target_length-1;jj>=0;ii--)
               res[ii]=target[jj--];
            i=ii+1;
        }
    }
    return res;
}

int main()
{
    string str="a b c";


    cout<<counter_space(str)<<endl;
    cout<<space2other(str,"123456")<<endl;

    return 0;
}

