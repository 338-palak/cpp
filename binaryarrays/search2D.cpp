#include<bits/stdc++.h>
using namespace std;
/*// brute approach
bool search2d(vector<vector<int>> &mat ,int target){
    int n = mat.size();
    int m = mat[0].size();
    int ans = 0;
    for(int i= 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(mat[i][j] == target){
                return true;

            }
        }
    }
    return false;
}
int main() {
    vector<vector<int>> mat = {
        {3, 4,7,9},
        {12,13,16,18},
        {20,21,23,29},
       
    };
    int target = 223;

    cout << boolalpha << search2d(mat, target) << endl;
    return 0;
}*/

/*// better solution
int binarysearch(vector<int> &arr , int target){
    int low = 0 ;
    int high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
}
int search2D(vector<vector<int>> &mat , int target){
    int n= mat.size();
    int m = mat[0].size();
    for(int i = 0 ; i < n ; i++){
        if(target >= mat[i][0] && target <= mat[i][m-1]){
            return binarysearch(mat[i] , target);
        }
    }
    return false;
}
int main() {
    vector<vector<int>> mat = {
        {3, 4,7,9},
        {12,13,16,18},
        {20,21,23,29},
       
    };
    int target = 23;

    cout << boolalpha << search2D(mat, target) << endl;
    return 0;
}*/
// optimal solution
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0 , high = (n*m - 1);
        while(low <= high){
            int mid = low + (high - low)/2;
            int row = mid / n , column = mid % n;
            if(matrix[row][column] == target){
                return true;
            }else if(matrix[row][column] < target ){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return false;
        
    }
    int main() {
        vector<vector<int>> mat = {
            {3, 4,7,9},
            {12,13,16,18},
            {20,21,23,29},
           
        };
        int target = 233;

        cout << boolalpha << searchMatrix(mat, target) << endl;
        return 0;
    }
