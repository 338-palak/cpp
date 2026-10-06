#include<bits/stdc++.h>
using namespace std;
/*
int main(){
    string str ;
    cout << "enter : " ;
    getline(cin , str);
    cout << "output is : " << str;
    return 0;
}*/

/*
int main(){
    string str = "kxnasdas";
    for(int i = 0 ; i < str.length();i++){
        cout << str[i] << " ";
    }
    cout << endl;
    return 0;
}
*/
/*// Using for each loop
int main(){
    string str = "better than the movies";
    for(char ch : str){
        cout << ch << " ";
    }
        return 0;
}
*/
// Reverse a string  
/*// it is for a character array
int reverse(vector<int>& lalu){
    int n = lalu.size();
    int start = 0;
    int end = n - 1;
  while(start < end){
        swap(lalu[start] , lalu[end]);
         start++;
    end--;
    }
   
}
int main() {
    vector<int> lalu = {1, 2, 3, 4};

    reverse(lalu);

    // Print the reversed vector
    for (int num : lalu) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}*/
// in case of string 
int main(){
    string str = "hello bhsys";
    reverse(str.begin() , str.end());
    cout << str << endl;
    return 0;
}

