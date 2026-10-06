#include <bits/stdc++.h>
using namespace std;
/*
bool isSafe(int row, int col, vector<string>& board, int n) {
    int dupRow = row;
    int dupCol = col;
    // Check upper-left diagonal
    while(row >= 0 && col >= 0) {
        if(board[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }

    // Check left row
    row = dupRow;
    col = dupCol;
    while(col >= 0) {
        if(board[row][col] == 'Q') {
            return false;
        }
        col--;
    }
    // Check lower-left diagonal
    row = dupRow;
    col = dupCol;
    while(row < n && col >= 0) {
        if(board[row][col] == 'Q') {
            return false;
        }
        row++;
        col--;
    }
    return true;
}
void solve(int col, vector<string>& board,
           vector<vector<string>>& ans, int n) {
    // Queen has been placed in every column
    if(col == n) {
        ans.push_back(board);
        return;
    }
    // Try placing the queen in every row of this column
    for(int row = 0; row < n; row++) {
        if(isSafe(row, col, board, n)) {

            board[row][col] = 'Q';

            solve(col + 1, board, ans, n);

            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    // Make n x n board filled with '.'
    vector<string> board(n, string(n, '.'));
    solve(0, board, ans, n);
    return ans;
}
int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    vector<vector<string>> ans = solveNQueens(n);
    cout << "\nTotal solutions: " << ans.size() << "\n\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for(int row = 0; row < n; row++) {
            cout << ans[i][row] << "\n";
        }
        cout << "\n";
    }
    return 0;
}*/
void solve(int col , vector<string>& board ,  vector<vector<string>>& ans,int n ,vector<int>& leftRow,vector<int>& upperDiagonal,vector<int>& lowerDiagonal){
    // base case
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row = 0 ; row < n ; row++){
        if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0){
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n-1+col-row] = 1;
            solve(col+1,board,ans,n,leftRow,upperDiagonal,lowerDiagonal);
            board[row][col] = '.';
              leftRow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n-1+col-row] = 0;


        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n,string(n,'.'));
    vector<int> leftRow(n,0) , upperDiagonal(2*n - 1) , lowerDiagonal(2*n - 1);
    solve(0,board,ans,n,leftRow,upperDiagonal,lowerDiagonal);
    return ans;
}
int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    vector<vector<string>> ans = solveNQueens(n);
    cout << "\nTotal solutions: " << ans.size() << "\n\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for(int row = 0; row < n; row++) {
            cout << ans[i][row] << "\n";
        }
        cout << "\n";
    }
    return 0;}


