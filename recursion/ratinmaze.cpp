#include<bits/stdc++.h>
using namespace std;
/*
void solve(int i , int j , vector<vector<int>>& m,int n,string move,vector<string>&ans,vector<vector<int>>&vis){
    if(i == n-1 && j == n-1){
        ans.push_back(move);
        return;
    }
    //downward
    if(i+1 < n && !vis[i+1][j] && m[i+1][j] == 1){
        vis[i][j] = 1;
        solve(i+1,j,m,n,move+'D',ans,vis);
         vis[i][j] = 0;
    }
    //left
    if(j-1>=0 && !vis[i][j-1] && m[i][j-1]==1){
         vis[i][j] = 1;
        solve(i,j-1,m,n,move+'L',ans,vis);
         vis[i][j] = 0;
    }
    //right
     if(j+1<n && !vis[i][j+1] && m[i][j+1]==1){
         vis[i][j] = 1;
        solve(i,j+1,m,n,move+'R',ans,vis);
         vis[i][j] = 0;
    }
    //upward
     if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1){
         vis[i][j] = 1;
        solve(i-1,j,m,n,move+'U',ans,vis);
         vis[i][j] = 0;
    }


}
vector<string> findPath(vector<vector<int>>& m, int n){
    vector<string> ans;
    vector<vector<int>> vis(n,vector<int>(n,0));//visited array
    if(m[0][0] == 1) solve(0,0,m,n,"",ans,vis);
    return ans;
}

   int main() {
    int n = 4;

    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = findPath(m, n);

    if(paths.empty()) {
        cout << "No path exists";
    }
    else {
        for(string path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}*/
void solve(int i, int j, vector<vector<int>>& m, int n,
           string move, vector<string>& ans,
           vector<vector<int>>& vis, int di[], int dj[]) {

    if(i == n - 1 && j == n - 1) {
        ans.push_back(move);
        return;
    }

    string dir = "DLRU";

    vis[i][j] = 1;   // mark current cell visited

    for(int ind = 0; ind < 4; ind++) {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];

        if(nexti >= 0 && nextj >= 0 &&
           nexti < n && nextj < n &&
           !vis[nexti][nextj] &&
           m[nexti][nextj] == 1) {

            solve(nexti, nextj, m, n,
                  move + dir[ind], ans, vis, di, dj);
        }
    }

    vis[i][j] = 0;   // backtrack
}
vector<string> findPath(vector<vector<int>>& m, int n){
    vector<string> ans;
    vector<vector<int>> vis(n,vector<int>(n,0));//visited array
   int di[] = {1, 0, 0, -1};
int dj[] = {0, -1, 1, 0}; 
    if(m[0][0] == 1) solve(0,0,m,n,"",ans,vis,di,dj);
    return ans;
}

   int main() {
    int n = 4;

    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = findPath(m, n);

    if(paths.empty()) {
        cout << "No path exists";
    }
    else {
        for(string path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}