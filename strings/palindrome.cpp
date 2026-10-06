#include<bits/stdc++.h>
using namespace std;

/*//optimal soln
    string reverseWords(string s) {
       string result;
       int i = s.length() - 1;
       while(i >= 0){
        // skipping the spaces 
        while(i >= 0 && s[i] == ' ')
            i--;
            if( i < 0) {break;}
            int j = i;
            while(i >= 0 && s[i] != ' ')
                i--;
            if(!result.empty()){
                result += ' ';

            }
            // j is the last char and i is on empty space so we did  j - i so that we can get its length
            // substr(start, length) it extarcts the string that comes in the part
           result += s.substr(i+1 , j-i);
            
        
       }
       return result;
    }
int main() {
    string s;
    getline(cin, s);
    cout << reverseWords(s) << '\n';
    return 0;
}// j points to the last character of the current word.
// i points to the space before the current word.
// The word starts at i + 1 and its length is (j - i).
// substr(start, length) extracts 'length' characters starting from 'start'.
*/

/*// vector approach brute
string reversewords(string s){
    vector<string> words;
    int i = 0;
    int n = s.length();
    while(i < n){

        // skip spaces 
        while(i < n && s[i] == ' ')
            i++;
            if(i >= n) break;
            string word = "";
            while(i < n && s[i] != ' ') {
            word += s[i];
            i++;}
            words.push_back(word);
    }
    string ans = "";
    for(int i = words.size() - 1 ; i >= 0;i--){
        ans += words[i];
        if(i != 0){
            ans += " ";
        }
      
    }
      return ans;
}
int main(){
    string s;
    getline(cin, s);
    cout << reversewords(s) << '\n';
    return 0;
}*/

/*// optimal but reverse entire string method
string reverseWords(string s){
    int n = s.length();
    string ans = "";
    reverse(s.begin() , s.end());
    for(int i = 0 ; i < n ; i++){
        string word = "";
        while(i < n && s[i] != ' '){
            word += s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if(!word.empty()){
            if(!ans.empty()){
                ans += ' ';
            }
            ans += word;
        }
    }
    return ans;
}
int main(){
    string s;
    getline(cin, s);
    cout << reverseWords(s) << '\n';
    return 0;
}
*/

// reverse string without extra space
string reverseWords(string s){
    int n = s.length();
    int i = 0;
    int idx = 0;
    reverse(s.begin(),s.end());
    while(i < n){
        //remove extra space
        while(i < n && s[i] == ' ') 
        i++;
        if(i >= n) break;
        if(idx != 0){
            s[idx++] = ' ';
        }
        int start = idx;
        while(i < n && s[i] != ' '){
            s[idx++] = s[i++];
        }
        reverse(s.begin()+start , s.begin() + idx);

    }
    return s;
}
int main(){
    string s;
    getline(cin, s);
    cout << reverseWords(s) << '\n';
    return 0;
}
