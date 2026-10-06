#include<bits/stdc++.h>
using namespace std;

// brute force approach
vector<int> intersection(vector<int> &a , vector<int> &b , int n , int m){
    vector<int> ans;
    int vis[m] = {0};
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(a[i] == b[j] && vis[j] == 0 ){
                ans.push_back(a[i]);
                vis[j] = 1;
                break;
            }
            if(a[i] < b[j]){
                break;
            }
        }
    }  
      return ans;
}
int main(){
    int n , m;
    cout << "Enter the size of first & second array : ";
    cin >> n >> m;
    cout << "Enter the elements of first & second array : ";
    vector<int> a(n) , b(m);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < m ; i++){
        cin >> b[i];
    }
    vector<int> ans = intersection(a , b , n , m);
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
}

// optimal approach
vector<int> intersection(vector<int> &a , vector<int> &b ,int n , int m){
    int i = 0 , j = 0;
    vector<int> ans;
    while(i < n && j < m){
        if(a[i] < b[j]){
            i++;
        }
        else if(a[i] > b[j]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;

}
int main(){
    int n , m;
    cout << "Enter the size of first & second array : ";
    cin >> n >> m;
    cout << "Enter the elements of first & second array : ";
    vector<int> a(n) , b(m);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < m ; i++){
        cin >> b[i];
    }
    vector<int> ans = intersection(a , b , n , m);
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
}
