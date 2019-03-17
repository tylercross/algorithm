#include <iostream>
#include <vector>

using namespace std;


int getDigSum(int num)
{
    int sum=0;
    while(num>0)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}

bool check(int threshold ,int rows, int cols,\
                       int row,int col,vector<bool>visited)
{
    if(row>=0&&row<rows&&col>=0&&col<cols&&getDigSum(row)+getDigSum(col)<=\
       threshold && !visited[row*cols+col]) return true;
    return false;
}

int movingCounterCore(int threshold ,int rows, int cols,\
                       int row,int col,vector<bool>&visited)//注意visited必须为引用形式
{
    int count=0;
    if(check(threshold,rows,cols,row,col,visited))
    {
        visited[row*cols+col]=true;
        count=1+movingCounterCore(threshold,rows,cols,row-1,col,visited)
        +movingCounterCore(threshold,rows,cols,row+1,col,visited)+\
        movingCounterCore(threshold,rows,cols,row,col-1,visited)+
        movingCounterCore(threshold,rows,cols,row,col+1,visited);

    }
    return count;
}
int movingCounter(int threshold,int rows,int cols)
{
    if(threshold<0||rows<=0||cols<=0) return 0;
    vector<bool> visited(rows*cols,false);
    int count = movingCounterCore(threshold,rows,cols,0,0,visited);
    return count;
}

int main(){
 int k,m,n;
 cin>>k>>m>>n;

 cout<<k<<"can get grids of "<<movingCounter(k,m,n);



return 0;
}
