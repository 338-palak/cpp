#include<bits/stdc++.h>
using namespace std;

/*//if row and col are given we have to find the elment at that position in pascal triangle
int pascal(int n , int r){
   long long res = 1;
    for(int i = 0 ; i < r ; i++){
         res = res * (n-i);
        res = res/(i+1);
    }
    return res;
}
int main(){
    int row , col;
    cin >> row >> col;
    cout << pascal(row-1 , col-1) << endl;
    return 0;
}*/

/*//fund the row of pascal triangle
int pascalrow(int n){
    long long res = 1 ;
    cout << res << " ";
    for(int col = 1 ; col < n ; col++){
        res = res*(n-col);
        res = res/col;
        cout << res << " ";
    }
  
}
int main(){
    int n;
    cin >> n;
     pascalrow(n) ;
    return 0;

}
*/
/*//print the pascal triangle with tc o(n3)
int pascal(int n , int r){
    int res = 1;
    for(int i = 0 ; i < r ; i++){
         res = res * (n-i);
        res = res/(i+1);
    }
    return res;
}
vector<vector<int>> pascaltraingle(int n){
    vector<vector<int>> ans;
    for(int row = 1 ; row <= n ; row++){
       vector<int> temp; //to store the current row of pascal triangle
       for(int col = 1 ; col <= row ; col++){
        temp.push_back(pascal(row-1 , col-1));
       }
       ans.push_back(temp);
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> ans = pascaltraingle(n);
    for(int i = 0 ; i < ans.size() ; i++){
        for(int j = 0 ; j < ans[i].size() ; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/
//print the pascal triangle with tc o(n2)
vector<int> generate(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(ans);
    for(int col = 1 ; col < row ; col++){
        ans = ans * (row-col);
        ans = ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;

}
vector<vector<int>> pascaltriangle(int n){
    vector<vector<int>> ans;
    for(int i=1 ; i <= n ; i++){
        ans.push_back(generate(i));
    }
    return ans;

}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> ans = pascaltriangle(n);
    for(int i = 0 ; i < ans.size() ; i++){
        for(int j = 0 ; j < ans[i].size() ; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}




