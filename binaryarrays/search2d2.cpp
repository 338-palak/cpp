#include<bits/stdc++.h>
using namespace std;
/*//brute force approach
pair<int,int> search2d(vector<vector<int>>& matrix , int target){
    int n= matrix.size();
    int m = matrix[0].size();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(matrix[i][j] == target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}
    //tc 
int main() {
        vector<vector<int>> mat = {
            {1,4,7,11,15},
            {2,5,8,12,19},
            {3,6,9,16,22},
            {10,13,14,17,24},
            {18,21,23,26,30},
           
        };
        int target = 14;

        pair<int,int> pos = search2d(mat, target);
        if(pos.first == -1 && pos.second == -1) {
            cout << "Not found" << endl;
        } else {
            cout << pos.first << "," << pos.second << endl;
        }
        return 0;
    }
*/

/*// better approach
int binarysearch(vector<int>& arr , int target){
    int low = 0 ; int high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }

    }
    return -1;
}
bool search2d(vector<vector<int>>& mat , int target){
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 0 ; i < n ; i++){
       int indx = binarysearch(mat[i], target);
       if(indx != -1){
        return true;
       }

    }
    return false;
}
int main(){
    vector<vector<int>> mat = {
            {1,4,7,11,15},
            {2,5,8,12,19},
            {3,6,9,16,22},
            {10,13,14,17,24},
            {18,21,23,26,30},
           
        };
        int target = 14;

        bool found = search2d(mat , target);
         if(found){
            cout << "Found" << endl;
        }
        else{
            cout << "Not Found" << endl;
        }
}
*/

// optimal approach
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0 , col = m - 1;
        while(row < n && col >= 0){
            if(matrix[row][col] == target ){
                return true;
            }else if(matrix[row][col] < target){
                row++;
            }else{
                col--;
            }
        }
        return false;
        
    }
    int main(){
        vector<vector<int>> mat = {
            {1,4,7,11,15},
            {2,5,8,12,19},
            {3,6,9,16,22},
            {10,13,14,17,24},
            {18,21,23,26,30},
           
        };
        int target = 14;

        bool found = searchMatrix(mat , target);
         if(found){
            cout << "Found" << endl;
        }
        else{
            cout << "Not Found" << endl;
        }
    }


