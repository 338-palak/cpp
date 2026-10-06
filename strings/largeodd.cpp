#include<bits/stdc++.h>
using namespace std;
/*// brute
 string largestOddNumber(string num) {
        int n = num.length();
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                string temp = num.substr(i , j-i+1);
            
            if((temp.back() - '0') % 2 == 1){
                if(temp.length() > ans.length() || 
                    (temp.length() == ans.length() && temp > ans)){
                        ans = temp;
              }
           }
        }
     }
        return ans;
    }
int main(){
    string s = "1234";
    string c = largestOddNumber(s);
    cout << c << endl;

}*/
/*optimal*/

  string largestOddNumber(string num) {
        int n = num.size();
        for(int i = n - 1; i >= 0 ; i--){
            if((num[i] - '0') % 2 == 1){
                return num.substr(0 , i+1);
            }

        }
        return "";
        
    }
int main(){
    string s = "1234";
    string c = largestOddNumber(s);
    cout << c << endl;
}