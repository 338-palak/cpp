#include<bits/stdc++.h>
using namespace std;
/*// Brute Force
bool valid(string& s){
    int balance = 0;
    for(char ch : s){
        if(ch == '('){
            balance++;
        }else{
            balance--;
        }
    if(balance < 0){
        return false;
    }
}
return balance == 0;
}

void generate(string& s , int index , int n , vector<string>& ans){
    if(index == 2*n){
        if(valid(s)){
            ans.push_back(s);
        }
        return;
    }
    s[index] = '(';
    generate(s,index+1,n,ans);
    s[index] = ')';
    generate(s,index+1,n,ans);
}

int main(){
    int n = 3;
    string s(2*n,' ');
    vector<string> ans;
    generate(s,0,n,ans);
    for(auto x : ans){
        cout << x << endl;
    }
    return 0;
}*/
//optimal solution
void generate(string& s,int open,int close,int n,vector<string>& ans){
    if(s.size() == 2*n){
        ans.push_back(s);
        return;
    }
    if(open < n){
        s.push_back('(');
        generate(s,open+1,close,n,ans);
        s.pop_back();
    }
    if(close < open){
        s.push_back(')');
        generate(s,open,close+1,n,ans);
        s.pop_back();
    }
}
int main(){
    int n = 4;
    string s = "";
    vector<string> ans;
    generate(s,0,0,n,ans);
    for(auto x : ans){
        cout << x << endl;
    }
    return 0;
}