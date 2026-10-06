#include<bits/stdc++.h>
using namespace std;
/*// brute force solution
 bool isomorphic(string s , string t){
    int n = s.size();
    if(n != t.size()){
        return false;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(s[i] == s[j] && t[i] != t[j]){
                return false;
            }
            if(t[i] == t[j] && s[i]!=s[j]){
                return false;
            }
        }
    }
    return true;
 }
 int main(){
    string s = "egg";
    string t = "add";
    cout << isomorphic(s, t) << endl;
    return 0;
 }*/
/*// better soln using hash map and hash set
bool isomorphic(string s , string t){
    if(s.size() != t.size()) return false ;
    unordered_map<char,char> mp;
    unordered_set<char> user;
    for(int i = 0 ; i < s.size() ; i++){
    if(mp.count(s[i])){
        if(mp[s[i]] != t[i]) return false;
    }else{
       if( user.count(t[i]) ) return false;
       mp[s[i]] = t[i];
       user.insert(t[i]);
    }
}
return true;
}
int main(){
    string s = "egg";
    string t = "addd";
    cout << isomorphic(s, t) << endl;
    return 0;}
*/
/*// optimal using 2 hashmaps
bool isIsomorphic(string s, string t) {

    if (s.size() != t.size())
        return false;

    unordered_map<char, char> sToT;
    unordered_map<char, char> tToS;

    for (int i = 0; i < s.size(); i++) {

        char c1 = s[i];
        char c2 = t[i];

        if (sToT.count(c1)) {
            if (sToT[c1] != c2)
                return false;
        } else {
            sToT[c1] = c2;
        }

        if (tToS.count(c2)) {
            if (tToS[c2] != c1)
                return false;
        } else {
            tToS[c2] = c1;
        }
    }

    return true;
}*/
// optimal with 2 arrays
bool isIsomorphic(string s, string t) {

    if (s.size() != t.size())
        return false;

    vector<int> mapS(256, -1);
    vector<int> mapT(256, -1);

    for (int i = 0; i < s.size(); i++) {

        if (mapS[s[i]] != mapT[t[i]])
            return false;

        mapS[s[i]] = i;
        mapT[t[i]] = i;
    }

    return true;
}
int main(){
    string s = "egg";
    string t = "addd";
    cout << isIsomorphic(s, t) << endl;
    return 0;}
