#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool hasPathCore(string matrix,int rows,int cols,int row, int col,\
                 const string str,int& pathLength, vector<bool> visited)
{
    if(pathLength>=str.size()) return true;//
    bool hasPath=false;
    if(row>=0&&row<rows&&col>=0&&col<cols&&matrix[row*cols+col]\
       ==str[pathLength]&&!visited[row*cols+col])

    {
        ++pathLength;

        visited[row*cols+col]=true;
        hasPath=hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited)||\
        hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited)||\
        hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited)||\
        hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited);


    if(!hasPath){



        --pathLength;
        visited[row*cols+col]=false;
            }
    }
    return hasPath;
}
bool hasPath(string matrix,int rows,int cols,string str)
{
    if(matrix.size()==0||rows<1||cols<1||str.empty())
        return false;
   vector<bool> visited(rows*cols,false);
    int pathLen=0;
    for(int row=0;row<rows;row++)
        for(int col=0;col<cols;col++)
    {
        if(hasPathCore(matrix,rows,cols,row,col,str,pathLen,visited))
            return true;
    }
    return false;
}


int main(){
 string matrix="abtgcfcsjdeh";
 string str;
 cin>>str;
 int rows=3,cols=4;
 if(hasPath(matrix,rows,cols,str)) cout<<"there is a path for "<<str;
 else cout<<"no way!";


return 0;
}
