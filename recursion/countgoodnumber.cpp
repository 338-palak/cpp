#include<bits/stdc++.h>
using namespace std;
/*// brute-force recrsion method
int solve(int index , long long n){
    if(index == n) return 1;
    const int mod = 1e9+7;// The intermediate sum never exceeds the storage limits of the data type (preventing integer overflow and negative/garbage numbers).
    long long count = 0;
    if(index % 2 == 0){
        for(int digit : {0, 2, 4, 6, 8}){
            count = count + (solve(index+1,n))%mod ;
        }
    }else{
        for(int digit : {2,3,5,7}){
             count = count + (solve(index+1,n))%mod ;
        }
    }
    return count;
}
int countGoodNumbers(int index ,long long n){
    return solve(0,n);
}
    int main() {
    int n = 3;
    cout << countGoodNumbers(0, n) << endl;
    return 0;
}*/

/*//optimal method/recursive binary exponenetial
const int mod = 1e9 + 7;
int power(long long base , long long exp ){
    if(exp == 0) return 1;
    long long half = power(base , exp/2) % mod ;
    long long result = (half*half) % mod ;
    if(exp % 2 != 0){
        result = (base * result) % mod;
    }
    return result;
}
int countgoodnumbers(long long n){
    int evennumber = (n+1)/2;
    int oddnumber = n/2;
    int evenway = power(5,evennumber);
    int oddway = power(4,oddnumber);
    int result = (evenway * oddway ) % mod;
    return result;

}
  int main() {
    int n = 5;
    cout << countgoodnumbers(n) << endl;
    return 0;
  }
*/

// Iterative binary exponential
const int mod = 1e9 + 7;
long long power(long long base , long long exp){
    base = base % mod ;
    long long ans = 1;
    while(exp > 0){
        if(exp % 2 != 0){
            ans = (ans * base) % mod;
        }
    
    base = (base*base ) % mod;
    exp = exp/2;
}
    return ans;
     
}
 int countGoodNumbers(long long n) {
    long long evenPositions = (n + 1) / 2; // Slots with 5 choices (0, 2, 4, 6, 8)
    long long oddPositions = n / 2;        // Slots with 4 choices (2, 3, 5, 7)
    long long waysEven = power(5, evenPositions);
    long long waysOdd = power(4, oddPositions);
    return (waysEven * waysOdd) % mod;
}

int main() {
  
    long long n1 = 1;
    cout << "Input: n = " << n1 << " -> Output: " << countGoodNumbers(n1) << endl;
    long long n2 = 4;
    cout << "Input: n = " << n2 << " -> Output: " << countGoodNumbers(n2) << endl;
    long long n3 = 5;
    cout << "Input: n = " << n3 << " -> Output: " << countGoodNumbers(n3) << endl;
    long long n4 = 50;
    cout << "Input: n = " << n4 << " -> Output: " << countGoodNumbers(n4) << endl;

    return 0;
}