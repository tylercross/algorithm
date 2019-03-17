#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool checkValidString(const vector<char>& s);

void helper(vector<vector<char>>& res,vector<char>& temp,const vector<char>& l1,
            const vector<char>& l2,int s1,int s2);
long valid_strings(const vector<char>& l1, const vector<char>& l2)
{
    //vector<char> res(l1);
    //res.insert(res.end(),l2.begin(),l2.end());
    vector<vector<char>> ress;
    vector<char> res;
    helper(ress,res,l1,l2,0,0);

    long counter=0;
    cout<<"nums="<<ress.size()<<endl;
    for(auto i:ress)
    {
        if(checkValidString(i)) counter++;

    }
    return counter;



}
void helper(vector<vector<char>>& res,vector<char>& temp,const vector<char>& l1,
            const vector<char>& l2,int s1,int s2)
{

    if(s1==l1.size()&&s2==l2.size()) {res.push_back(temp); return;}
    if(s1<l1.size()||s2<l2.size())
    {
        if(s1<l1.size())
        {


            temp.push_back(l1[s1]);
            helper(res,temp,l1,l2,s1+1,s2);
            temp.pop_back();
        }
        if(s2<l2.size())
        {
            temp.push_back(l2[s2]);
            helper(res,temp,l1,l2,s1,s2+1);
            temp.pop_back();

        }

    }

}


bool checkValidString(const vector<char>& s) {
        int lower = 0, upper = 0;
        for (auto c : s) {
            if (c=='(') {
                lower++;
                upper++;
            } else if (c==')') {
                lower--;
                upper--;
            } else { // * encountered
                lower--;
                upper++;
            }
            lower = max(lower, 0);
            if (upper<0) // unmatched ')' found in the middle of string
                return false;
        }
        return lower==0;
    }
int main()
{
    string temp,temp2;
    vector<char> l1;
    vector<char> l2;
    cin>>temp;
    cin>>temp2;
    for(auto i:temp)
        l1.push_back(i);
    for(auto i:temp2)
        l2.push_back(i);
    long res = valid_strings(l1,l2);
    long poww = pow(10,9) +7;
    long ress = res%poww;
    cout<<ress;


    return 0;
}
