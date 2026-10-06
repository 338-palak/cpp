#include<bits/stdc++.h>
using namespace std;
/*// also known as rotate image 
//brute force approach
vector<vector<int>> rotate90(vector<vector<int>> &a , int n){
    vector<vector<int>> ans(n,vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            ans[j][n-1-i] = a[i][j];
        }
    }
    return ans;
  
}
int main(){
    vector<vector<int>> a = {{1,2,3} , {4,5,6} , {7,8,9}};
    int n = a.size();
    vector<vector<int>> ans = rotate90(a,n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//time complexity : O(n^2)
//space complexity : O(n^2) for the answer matrix
*/
// optimal approach
vector<vector<int>> rotate90(vector<vector<int>> &a , int n){
    //transpose // tc is o(n/2 * n/2)
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = i+1 ; j < n ; j++){
            swap(a[i][j] , a[j][i]);
        }
    }
    //reverse  // tc is o(n*n/2)
    for(int i = 0 ; i < n ; i++){
      //  row is a[i]
        reverse(a[i].begin() , a[i].end());
    }
    return a;
}
int main(){
    vector<vector<int>> a = {{1,2,3} , {4,5,6} , {7,8,9}};
    int n = a.size();
    rotate90(a,n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// time complexity : O(n^2) for both transpose and reverse
// space complexity : O(1) as we are doing in place rotation
