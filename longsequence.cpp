#include<bits/stdc++.h>
using namespace std;
/*//brute force
bool ls(vector<int> &nums , int x){
    for(int i = 0 ; i < nums.size();i++){
        if(nums[i] == x){
            return true;
        }}
        return false;
    
}
int longestsequence(vector<int> &nums , int n){
    if(n == 0){
        return 0;
    }
    int longest = 1;
    for(int i = 0 ; i < n ; i++){
        int x = nums[i];
        int cnt = 1;
        while(ls(nums , x+1)){
            x = x+1;
            cnt++;
        }
        longest = max(longest , cnt);
    }
    return longest;
}
int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int n = nums.size();
    cout<<longestsequence(nums , n);
    return 0;
}
//time complexity : o(n3)
*/
/*//better approach
int longestsequence(vector<int> &nums , int n){
    if(n==0){
        return 0;
    }
    sort(nums.begin() , nums.end());
    int longest = 1;
    int lastSmaller = INT_MIN;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        if(nums[i] -1 == lastSmaller){
            cnt+=1;
            lastSmaller = nums[i];
        }
        else if(nums[i] != lastSmaller){
            cnt = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest , cnt);
    }
    return longest;
}
int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int n = nums.size();
    cout<<longestsequence(nums , n);
    return 0;
}
*/
//optimal approach
int longestsequence(vector<int> &a , int n){
    
    if(n==0){
        return 0;
    }
    int longest = 1;
    unordered_set<int> s;
    for(int i = 0 ; i < n ; i++){
        s.insert(a[i]);
    }
    for(auto it : s){
        if(s.find(it - 1) == s.end()){
            int cnt = 1;
            int x = it ;
            while(s.find(x+1) != s.end()){
                x = x+1;
                cnt++;
            }
            longest = max(longest , cnt);

        }
    }
return longest;
}
int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int n = nums.size();
    cout<<longestsequence(nums , n);
    return 0;
}