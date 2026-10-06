#include<bits/stdc++.h>
using namespace std;


/*// decimal to binary
string convert2Binary(int n){
    string ans = "";
    while(n != 0){
        if(n%2 == 1){
            ans+='1';
         } else{
            ans+='0';
         }
         n = n/2;
        }
      reverse(ans.begin(), ans.end());
      return ans;
    }
    int main(){
        int n;
        cin>>n;
        cout<<convert2Binary(n);
    }*/


/*
// binary to decimal
int convert2Decimal(string s){
   int len = s.length() , p2 = 1 , ans = 0;
   for(int i = len-1; i >=0 ; i--){
        if(s[i] == '1'){
            ans+=p2;
        }
        p2 = p2*2;
   }
   return ans;
}
 int main(){
        string s;
        cin>>s;
        cout<<convert2Decimal(s);
        return 0;
    }*/





