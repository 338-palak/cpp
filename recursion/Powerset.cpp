#include<bits/stdc++.h>
using namespace std;
void generate(string& s , string& temp, int index ,vector<string>& ans){
    if(index == s.size()){
        if(!temp.empty()){
        ans.push_back(temp);
    }
        return;
    }
    temp.push_back(s[index]);
    generate(s,temp,index+1,ans);
    temp.pop_back();
    generate(s,temp,index+1,ans);
}
int main(){
    string s = "abcd";
    string temp = "";
    vector<string> ans;

    generate(s,temp,0,ans);

    for(auto x : ans){
        cout << x << " ";
    }

    return 0;
}