#include<bits/stdc++.h>
using namespace std;
/* //brute force
void markrow(vector<vector<int>> &a , int n , int m , int i){
    for(int j = 0 ; j < m ; j++){
        if(a[i][j] != 0){
            a[i][j] = -1;
        }
    }
}
void markcol(vector<vector<int>> &a , int n , int m , int j){
    for(int i = 0 ; i < n ; i++){
        if(a[i][j] != 0){
            a[i][j] = -1;
        }
    }
}



bool zeromatrix(vector<vector<int>> &a , int n , int m){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(a[i][j] == 0){
                markrow(a,n , m ,i);
                markcol(a,n,m,j);

            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(a[i][j] == -1){
                a[i][j] = 0;
            }
        }
    }

}
int main(){
    vector<vector<int>> a = {{1,1,1} , {1,0,1} , {1,1,1}};
    int n = a.size();
    int m = a[0].size();
    zeromatrix(a,n,m);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
    */
/*//better approach 
vector<vector<int>> zeromatrix(vector<vector<int>> &a , int n , int m){
    int row[n] = {0};
    int col[m] = {0};
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(a[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }

        }
    }
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ; j++){
            if(row[i] == 1 || col[j] == 1){
                a[i][j] = 0;
            }

        }
    }
    return a;

}
int main(){
    vector<vector<int>> a = {{0,1,2,0} , {3,4,5,2} , {1,3,1,5}};
    int n = a.size();
    int m = a[0].size();
    zeromatrix(a,n,m);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}*/
//optimal approach
vector<vector<int>> zeromatrix(vector<vector<int>> &a , int n , int m){
    int col0 = 1;
    for(int i = 0 ; i < n; i++){
        for(int j= 0 ; j < n ; j++){
            if(a[i][j]==0){
                a[i][0] = 0;
                if(j != 0){
                 a[0][j] = 0;
            }else{
                col0 = 0;
            }
        }
    }
}
for(int i = 1 ; i < n ; i++){
    for(int j = 1 ; j < m ; j++){
        if(a[i][j] != 0){
           if(a[i][0] == 0 || a[0][j] == 0){
               a[i][j] = 0;
           }

        }

    }
}
if(a[0][0] == 0){
    for(int j = 0 ; j < m ; j++){
        a[0][j] = 0;
    }
}
if(col0 == 0){
    for(int i = 0 ; i < n ; i++){
        a[i][0] = 0;
    }
}
return a;
}
int main(){
    vector<vector<int>> a = {{0,1,2,0} , {3,4,5,2} , {1,3,1,5}};
    int n = a.size();
    int m = a[0].size();
    zeromatrix(a,n,m);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}




