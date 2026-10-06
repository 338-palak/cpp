#include<bits/stdc++.h>
using namespace std;
/*
bool solve(int index, string& s, unordered_set<string>& st) {
    // Entire string has been successfully divided
    if(index == s.length()) {
        return true;
    }

    string word = "";

    for(int i = index; i < s.length(); i++) {
        word += s[i];

        // If current substring exists in dictionary
        if(st.find(word) != st.end()) {
            // Check the remaining string
            if(solve(i + 1, s, st)) {
                return true;
            }
        }
    }

    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> st(wordDict.begin(), wordDict.end());

    return solve(0, s, st);
}

int main() {
    string s = "takeforward";

    vector<string> wordDict = {
        "take", "forward", "pine"
    };

    if(wordBreak(s, wordDict)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}
*/

bool solve(int index, string& s, unordered_set<string>& st,
           vector<int>& dp) {

    // Entire string was successfully segmented
    if(index == s.length()) {
        return true;
    }

    // Already solved this index
    if(dp[index] != -1) {
        return dp[index];
    }

    string word = "";

    for(int i = index; i < s.length(); i++) {
        word += s[i];

        // If current word is in dictionary
        if(st.find(word) != st.end()) {

            // Check remaining string
            if(solve(i + 1, s, st, dp)) {
                return dp[index] = true;
            }
        }
    }

    return dp[index] = false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> st(wordDict.begin(), wordDict.end());

    // -1 = not calculated, 0 = false, 1 = true
    vector<int> dp(s.length(), -1);

    return solve(0, s, st, dp);
}

int main() {
    string s = "takeforward";

    vector<string> wordDict = {
        "take", "forward", "you", "u"
    };

    if(wordBreak(s, wordDict)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}