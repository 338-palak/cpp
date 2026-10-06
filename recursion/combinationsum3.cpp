#include<bits/stdc++.h>
using namespace std;
/*// Pick or not pick
void solve(int num,int k , int n , vector<vector<int>>&ans,vector<int>&ds){
    //base case
    if(k == 0){
        if(n == 0){
            ans.push_back(ds);
        }
        return;
    }
    if(num > 9 || n < 0) return;
    // To pick
    ds.push_back(num);
    solve(num+1,k-1,n-num,ans,ds);
    //backstracking
    ds.pop_back();
    // not pick
     solve(num+1,k,n,ans,ds);


}
 vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int>ds;
    solve(1,k,n,ans,ds);
    return ans;
 }
int main() {
    int k, n;
    cin >> k >> n;

  
    vector<vector<int>> ans = combinationSum3(k, n);

    for (auto combination : ans) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}*/

// for-loop
void solve(int start , int k , int n, vector<vector<int>>& ans,vector<int>& ds){
    if(k == 0){
        if(n == 0){
            ans.push_back(ds);
        }
        return;
    }
   for(int num = start; num <= 9 ;num++){
      if(num > n) break;
      ds.push_back(num);
      solve(num+1,k-1,n-num,ans,ds);
      ds.pop_back();
   }
}
 vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int>ds;
    solve(1,k,n,ans,ds);
    return ans;
 }
int main() {
    int k, n;
    cin >> k >> n;
    vector<vector<int>> ans = combinationSum3(k, n);

    for (auto combination : ans) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}