#include<bits/stdc++.h>
using namespace std;
/*// brute 
int median2(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ls;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            ls.push_back(mat[i][j]);
        }
    }
    sort(ls.begin() , ls.end());
    int k = (n*m)/2;
    return ls[k];
}
int main() {
    vector<vector<int>> mat = {
        {1,5,7,9,11},
        {2,3,4,5,10},
        {9,10,12,14,16}
    };

    cout << "Median is: " << median2(mat) << endl;

    return 0;
}*/

// binary soln
 int upperbound(vector<int> &row, int x) {
        return upper_bound(row.begin(), row.end(), x) - row.begin();
    }
int median(vector<vector<int>>& mat , int x){
    int cnt = 0 ;
    int n = mat.size();
    for(int i = 0 ; i < n ; i++){
        cnt += upperbound(mat[i] , x);
    }
    return cnt;
}
    int findMedian(vector<vector<int>>&matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
          int low = INT_MAX;
        int high = INT_MIN;
        for(int i = 0 ; i < n ; i++){
         low = min(low , matrix[i][0]);
         high = max(high , matrix[i][m-1]);}
         int require = (n * m)/2;
        while(low <= high){
            int mid = low + (high - low)/2;
            int smallrequirements = median(matrix , mid);
            if(smallrequirements <= require){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
    int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Median = " << findMedian(matrix) << endl;
    return 0;
}