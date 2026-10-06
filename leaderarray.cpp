#include<bits/stdc++.h>
using namespace std;
/*//brute force approach
vector<int> leaderarray(vector<int> &a){
    int n = a.size();
    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        int leader = true;
        for(int j = i+1 ; j < n ;j++){
            if(a[i] < a[j]){
                leader = false;
                break;
            }  
        }
        if(leader == true) ans.push_back(a[i]);
    }
return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    vector<int> ans = leaderarray(arr);
    cout << "Leader array is : " << endl;
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
}*/
//optimal approach
vector<int> leaderarray(vector<int> &a){
    int n = a.size();
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i = n-1 ; i >=0 ; i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
           
        }
        maxi = max(maxi , a[i]);

    }
    sort(ans.begin() , ans.end());
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    vector<int> ans = leaderarray(arr);
    cout << "Leader array is : " << endl;
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
}