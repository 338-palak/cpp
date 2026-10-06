#include<bits/stdc++.h>
using namespace std;

  string removeOuterParentheses(string s) {
      int cnt = 0 ; 
        string result = "";
        int len = s.length();
        for(char c : s){
            if(c == '('){
                if(cnt > 0) result+= c;
                cnt++;
            }else{
                cnt--;
                if(cnt > 0) result+=c;
            }
        }
        return result;
       
    }
    int main(){
        string s = "(())";
        if (getline(cin, s)) {
            cout << removeOuterParentheses(s);
        }
        return 0;
    }