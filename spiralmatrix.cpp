#include<bits/stdc++.h>
using namespace std;
vector<int> spiralmatrix(vector<vector<int>> &matrix , int n , int m ){
    int left = 0, right = m-1;
    int top = 0, bottom = n-1;
    vector<int> ans;
while(left <= right && top <= bottom){
    // right
    for(int i = left ; i <= right ; i++){
        ans.push_back(matrix[top][i]);
        
    }
    top++;
    // bottom
    for(int i = top ; i <= bottom ; i++){
        ans.push_back(matrix[i][right]);
    }
    right--;
    //left
    if(top <=bottom){
    for(int i = right ; i >= left ; i--){
        ans.push_back(matrix[bottom][i]);
    }
    bottom--;
    }
    // top
    if(left <= right){
    for(int i = bottom ; i >= top ; i--){
        ans.push_back(matrix[i][left]);
    }
    left++;
}
}
return ans;
}

int main(){
    int n , m;
    cin >> n >> m;
    vector<vector<int>> matrix(n , vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> matrix[i][j];
        }
    }
    vector<int> ans = spiralmatrix(matrix , n , m);
    for(auto it : ans){
        cout << it << " ";
    }
}