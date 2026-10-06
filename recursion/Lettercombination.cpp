#include<bits/stdc++.h>
using namespace std;
// Backstracking/Recursion
void solve(string digits, string output, int index, vector<string> &ans, string mapping[]){
    //base case
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }
    int number = digits[index] - '0';
    string value = mapping[number];
   for(char ch : value){
    output.push_back(ch);
    solve(digits,output,index+1,ans,mapping);
    output.pop_back(); //remove the chosen value for next choice
   }
}
vector<string> letterCombinations(string digits ){
    vector<string> ans;
    string output;
    string mapping[10] ={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits,output,0,ans,mapping);
    return ans;
}
int main() {
    string digits;
    cin >> digits;

    vector<string> ans = letterCombinations(digits);

    for (string str : ans) {
        cout << str << " ";
    }

    return 0;
}