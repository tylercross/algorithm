#include <iostream>
#include <vector>

using namespace std;


int getMaxValue(vector<int>  vals,int rows,int cols)
{
    if(vals.empty()) return 0;
    vector<int> maxVals(cols);
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
        {
            int left=0,up=0;
            if(i>0) up=maxVals[j];
            if(j>0) left=maxVals[j-1];
            maxVals[j]=max(up,left)+vals[i*cols+j];
        }

    }

   return maxVals[cols-1];
}


int main()
{
    vector<int> vals;
    int val;
    while(cin>>val)
        vals.push_back(val);
    cout<<getMaxValue(vals,4,4);


    return 0;
}
