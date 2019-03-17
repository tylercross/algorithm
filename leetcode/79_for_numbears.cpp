#include <iostream>
#include <vector>
using namespace std;
 bool adjacentSearch(vector<vector<int>>& board, const int& num, int i, int j, int index)
    {
        if(index == to_string(num).length()) // end condition
            return true;
        if(i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1) // boundary of matrix
            return false;
        if(board[i][j] != num[index]) // do not match
            return false;
        // match!
        board[i][j] = '*'; // change the content, to avoid duplicated search
        bool furtherSearch = adjacentSearch(board, num, i + 1, j, index + 1) || // up
                             adjacentSearch(board, num, i - 1, j, index + 1) || // down
                             adjacentSearch(board, num, i, j - 1, index + 1) || // left
                             adjacentSearch(board, num, i, j + 1, index + 1);   // right

        board[i][j] = num[index]; // modify it back!
        return furtherSearch;
    }
    bool exist(vector<vector<int>>& board, int num) {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(adjacentSearch(board, num, i, j, 0))
                    return true;
            }
        }
        return false;

    }



int main()
{
    vector<vector<int>> board{{1,3,2},{,5,6,4},{9,8,7}};
    int num;
    cin>>num;
    //if (exist(board,num)) cout<<nums<<"is existed!"<<endl;
    cout<<num.length();
    return 0;

}
