#include<bits/stdc++.h>
using namespace std;
bool ispalindrome( string& s,int start , int end){
    while (start < end){
        if(s[start] != s[end]){
        return false;}
        start++;
        end--;
    }
    
    return true;
}
void solve(int index , string& s , vector<vector<string>>& ans ,vector<string>& current){
    // base case 
    if(index == s.size()){
        ans.push_back(current);
        return;
    }
    for(int i = index ; i < s.size();i++){
        if(ispalindrome(s,index,i)){
            current.push_back(s.substr(index,i-index+1));
            solve(i+1,s,ans,current);
            current.pop_back();
        }
    }

}
 vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    vector<string> current;
    solve(0 ,s, ans , current);
    return ans;
 }
int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    vector<vector<string>> ans = partition(s);

    cout << "Palindrome partitions:\n";

    for(auto part : ans) {
        cout << "[ ";
        for(auto word : part) {
            cout << "\"" << word << "\" ";
        }
        cout << "]\n";
    }

    return 0;
}