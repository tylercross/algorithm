#include <iostream>
#include <string>5
#include <vector>
using namespace std;
/*void helper(int m,int n,int i,int j,int &counter)
{
    if(i<m) helper(m,n,i+1,j,counter);

    if(j<n) helper(m,n,i,j+1,counter);
    if(i==m && j==n)  counter++;

}*/
int uniquePaths(int m, int n){
   //int counter=0;
    //helper(m,n,1,1,counter);
    //return counter;
    vector<vector<int> > path(m,vector<int> (n,1));
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
        path[i][j]=path[i-1][j]+path[i][j-1];

    return path[m-1][n-1];


}


int main()
{

    int m,n;
    cin>>m>>n;
    cout<<uniquePaths(m,n);

    return 0;
}
