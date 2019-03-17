 #include <iostream>
 #include <vector>
using namespace std;
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int x,y;
        x=matrix.size()-1;
       // width=matrix[0].size()-1;
        y=0;

        while(x>=0&&y>=0)
        {
            if(matrix[x][y]>target) x--;
            else if(matrix[x][y]<target) y++;
            else if(matrix[x][y]==target) return true;
        }
        return false;
    }
int main()
{
    //vector<vector<int>> matrix ={{1,2,8,9},\
    {2,4,9,12},{4,7,10,13},{6,8,11,15}} ;
    vector<vector<int>> matrix ;
   // matrix.push_back(vector<int> (1,1));

    int target;
    cin>>target;
    cout<<searchMatrix(matrix,target);
}
