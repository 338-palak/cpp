#include<bits/stdc++.h>
using namespace std;
/*// optimal approach
 string longestCommonPrefix(vector<string>& strs){
    string ans = "";
    // Traverse the first string character by character
   for(int i = 0 ; i < strs[0].size(); i++){
     // Compare this character with every other string
    for(int j = 1 ; j < strs.size(); j++){
        if(i >= strs[j].size() || strs[0][i] != strs[j][i]){
            return ans;
        }

    }
    ans += strs[0][i];


   }
   return ans;
 }
 int main() {

    vector<string> strs = {"flower", "flow", "flight"};

    cout << longestCommonPrefix(strs);

    return 0;
}*/

// brute approach
string longestCommonPrefix(vector<string>& strs) {
    string first = strs[0];
    string ans = "";
    for(int i = 0 ; i < first.size() ; i++){
        string prefix = first.substr(0, i+1);
          bool flag = true;
          for(int j = 1 ; j < strs.size(); j++){
            if(strs[j].substr(0,i+1) != prefix){
                flag = false;
                break;
            }
          }
          if(flag){
            ans = prefix;
          }else{break;}
         
    }
     return ans;
}
 int main() {

    vector<string> strs = {"flower", "flow", "flight"};

    cout << longestCommonPrefix(strs);

    return 0;}