#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
 bool solve(int row, int col, int index, vector<vector<char>>& board, string& word) {
           //base case
           if(index == word.size()){
            return true;
           }

           //Invalid conditions
           if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[index] ){
            return false;
           }

           char ch = board[row][col];
           board[row][col] = '#';

           bool ans = solve(row+1,col,index+1,board,word) || 
                        solve(row-1,col,index+1,board,word) ||
                                solve(row,col+1,index+1,board,word) ||
                                solve(row,col-1,index+1,board,word);

            board[row][col] = ch;
            return ans;

               }



 bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(board[row][col] == word[0]){
                    if(solve(row,col,0,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
        
        
    }
    };
    int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word;
    cout << "Enter word: ";
    cin >> word;

    Solution solution;
    if(solution.exist(board, word)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}
