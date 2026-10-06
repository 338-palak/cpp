#include<bits/stdc++.h>
using namespace std;
/*// brute approach
 vector<int>  peakelement2(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();
   for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
        bool up = (i == 0 || mat[i][j] > mat[i -1][j]);
        bool down = (i == n - 1 ||  mat[i][j] > mat[i + 1][j]);
        bool left = (j == 0 || mat[i][j] > mat[i][j - 1]);
        bool right = (j == m - 1 || mat[i][j] > mat[i][j + 1]);
        if(up && down && left && right){
              return {i, j};
        }
    }
   }
   return {-1,-1};
}
int main() {
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    vector<int> ans = peakelement2(mat);

    cout << "Peak Element Index: (" << ans[0] << ", " << ans[1] << ")" << endl;
    cout << "Peak Element Value: " << mat[ans[0]][ans[1]] << endl;

    return 0;
}
*/

// optimal appproach / binary approach
  int row(vector<vector<int>>& mat , int col){
    int n = mat.size();
    int maxvalue = -1;
    int index = 0;
    for(int i = 0 ; i < n ; i++){
        if(mat[i][col] > maxvalue){
            maxvalue = mat[i][col];
            index = i;
        }
    }
    return index;
  }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0 , high = m-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int maxelement = row(mat , mid);
           int left = (mid - 1) >= 0 ? mat[maxelement][mid - 1] : -1;
           int right = (mid + 1) < m ? mat[maxelement][mid + 1] : -1;
           if(mat[maxelement][mid] > left && mat[maxelement][mid] > right){
            return {maxelement , mid};
           }
           else if(mat[maxelement][mid] < left){
            high = mid - 1;
           }else{
            low = mid + 1;
           }
        }
        return {-1,-1};
    }
  
     int main() {
   
    vector<vector<int>> mat = {
        {92, 91, 57},
        {98, 24, 34}
    };

    vector<int> peak = findPeakGrid(mat);

    cout << "Peak element found at index: [" << peak[0] << ", " << peak[1] << "]" << endl;
    cout << "Peak value is: " << mat[peak[0]][peak[1]] << endl;

    return 0;
}
    

