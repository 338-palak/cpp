#include<bits/stdc++.h>
using namespace std;
/*
bool valid(string& s){
   for(int i = 1 ; i < s.size() ; i++){
    if(s[i] =='1' && s[i-1] == '1'){
        return false;
    } 
   }return true;

}
void generate(string& s , int index , int n , vector<string>& ans){
    if(index == n){
        if(valid(s)){
            ans.push_back(s);
        }
        return;
    }
    s[index] = '0';
    generate(s,index+1,n,ans);

    s[index] = '1';
    generate(s,index+1,n,ans);

}

int main() {
    int n = 3;
    string s(n, '0');
    vector<string> ans;
    generate(s,0,n,ans);
    for(auto x : ans) {
        cout << x << " ";
    }
    return 0;
}
*/
/*
void generate(string& s  , int index , int n , int prev , vector<string>& ans){
     // base case 
     if(index == n){
        ans.push_back(s);
        return;
     }
     s[index] = '0';
     generate(s,index+1,n,0,ans);
     if(prev == 0){
        s[index] = '1';
        generate(s,index+1,n,1,ans);
     }
}
int main() {
    int n = 3;
    string s(n, '0');
    vector<string> ans;
    generate(s,0,n,0,ans);
    for(auto x : ans) {
        cout << x << " ";
    }
    return 0;
}
*/

/*void generate(string& s , int index , int n , vector<string>& ans){
    if(index >= n){
        ans.push_back(s);
        return;

    }
    // put 0
    s[index] = '0';
    generate(s,index+1,n,ans);
    // put 1
    s[index] = '1';
    // next position must remain 0
    generate(s,index+2,n,ans);
    //restore current position
    s[index] = '0';

}
int main() {
    int n = 3;
    string s(n, '0');
    vector<string> ans;
    generate(s,0,n,ans);
    for(auto x : ans) {
        cout << x << " ";
    }
    return 0;
}*/

void generate(string& s, int n, vector<string>& ans){
    if(s.size() == n){
        ans.push_back(s);
        return;
    }
    s.push_back('0');
    generate(s,n,ans);
    s.pop_back();
    if(s.empty() || s.back() != '1'){
        s.push_back('1');
        generate(s,n,ans);
        s.pop_back();
    }

 }
int main() {
    int n = 3;
    string s = "";
    vector<string> ans;
    generate(s, n, ans);
    for(auto x : ans) {
        cout << x << " ";
    }
    return 0;
} 