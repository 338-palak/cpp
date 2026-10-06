#include<bits/stdc++.h>
using namespace std;
/*// brute force approach
int row(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
int maxones = 0;
int ans = -1;
for(int i = 0 ; i < n ; i++){
    int cnt = 0 ;
    for(int j = 0 ; j< m ; j++){
        if (mat[i][j] == 1) {
            cnt++;
        }
    }
        if(cnt > maxones){
            maxones = cnt;
            ans = i;
        } 
}
    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    cout << "Row with maximum 1s: " << row(mat) << endl;

    return 0;
}*/

// optimal approach
int lowerbound(vector<int> &arr , int n , int x){
    int low  = 0 , high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high - low )/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
int row(vector<vector<int>> &mat , int n){
    int m = mat[0].size();
    int cnt_max = 0;
    int index = -1;
    for(int i = 0 ; i < n ; i++){
        int firstone = lowerbound(mat[i] , m , 1);
        int cnt_ones = m-firstone;
        if(cnt_ones > cnt_max){
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}
int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    cout << "Row with maximum 1s: " << row(mat, mat.size()) << endl;
    return 0;
}