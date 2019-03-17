#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class Solution {
    vector <string> res;
public:
    vector<string> Permutation(string str) {
        if(str.empty()) return res;
        sort(str.begin(),str.end());
        PermutationCore(str,0);

        return res;
    }

    void PermutationCore(string  str,int seg)
    {
        if(seg==str.size()-1) {
            {res.push_back(str); return;}
        }
        for(int i = seg; i<str.size(); i++)
        {
            if(i>seg&&str[i]==str[i-1]) continue;
            swap(str[i],str[seg]);

            PermutationCore(str, seg+1);

            //swap(str[i],str[seg]);
        }
        return ;

    }
};
int main()
{
    string str;
    cin>>str;
    vector<string> ress;
    Solution s ;
    ress = s.Permutation(str);
    for(auto i:ress)
        cout<<i<<endl;


    return 0;
}
