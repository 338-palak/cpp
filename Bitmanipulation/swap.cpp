#include<bits/stdc++.h>
using namespace std;
/*//swap
//using third variable
int main(){
    int a = 5;
    int b = 8;
    int temp = a;
    a = b;
    b = temp;

    cout << a << " " << b;
}

// using XOR;
 int main(){
    int a = 5;
    int b = 6;
    a = a^b;
    b = a^b;
    a = a^b;

    cout << a << " " << b;
 }
*/

/*// check if the ith bit is a set or not
//left shift
int main(){
    int n= 13;
    int i = 2;
    if(n & (1 << i)){
        cout << "set bit";
    }
    else{
        cout << "not set bit";
    }
}
//right shift
int main(){
    int n = 13;
    int i = 2;
    if(1 & (n >> i)){
        cout << "set bit";
    }
    else{
        cout << "not set bit";
    }
}
*/

/*// set the ith bit
int main(){
    int n = 13;
    int i = 1;
    n = n | (1 << i); 
    cout << n;}
*/

/*//   clear the ith bit;
int main(){
    int n = 13;
    int i = 2  ;
    n = n & (~(1 << i));
    cout << n;

}*/

/*//toggle the ith bit
int main(){
    int n = 13 ; 
     int i = 2; 
     n = n ^ (1 << i);
     cout << n;
}*/

/*// remove the last set bit
int main(){
    int n = 13;
    int i = 2;
    n = n & (n-1);
    cout << n;
}*/

/*// check if the number is a power of 2
int main(){
    int n = 16;
    if(n & (n-1) == 0){
        cout << "power of 2";
    }
    else{
        cout << "not power of 2";
    }
}
*/
// count the number of set bits
/*int countsetbits(int n){ // __builtin_popcount(n) in c++14
    int cnt = 0;
    while(n > 0){
        cnt += (n & 1); // for odd
        n = n >> 1; // n/2;
    }
  
    return cnt;
}
int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    cout << "Number of set bits: " << countsetbits(n) << '\n';

    return 0;
}*/
/*
int countsetbits(int n){ // __builtin_popcount(n) in c++14
    int cnt = 0;
  while(n != 0){
   n =  n & (n-1);
    cnt++;

  }
    return cnt;
}
int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    cout << "Number of set bits: " << countsetbits(n) << '\n';

    return 0;}
//
*/
 /* 
 check the number of bits to be flipped to convert A to B 
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int cnt = 0;
        for(int i = 0 ; i <= 31 ; i++){
            if(ans & (1 << i)){ // check if the ith bit is set or not
                cnt++;
            }
        }
       return cnt; 
    }
    int main(){
        
        int start, goal;
        cin >> start >> goal;
        cout << minBitFlips(start, goal);
    }*/

//Divide two integers without using multiplication, division and mod operator
/*
int divide(int dividend , int divisor){
    int sum = 0 , cnt = 0;
    while(sum + divisor <= dividend){
        cnt++;
        sum += divisor;
    }
    return cnt;
}
int main(){
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor);
}
TC : o(dividend/divisor)
sc: o(1)

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (dividend == divisor) return 1;

    bool sign = true;
    if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor >= 0)) {
        sign = false;
    }

    long long n = abs((long long)dividend);
    long long d = abs((long long)divisor);
    long long ans = 0; // Fix 1: initialized to 0

    while (n >= d) {
        int cnt = 0;
        
        // Inner loop: finds the highest power of 2
        while (n >= (d << (cnt + 1))) {
            cnt++;
        }

        ans += (1LL << cnt); // Fix 3: 1LL prevents 32-bit overflow
        n -= (d << cnt);
    }

    return sign ? ans : -ans;
}
int main() {
    int dividend = 22, divisor = 3;
    std::cout << divide(dividend, divisor) << std::endl; // Output: 7
    return 0;
}
// tc : o(logN)^2 here N is the dividend
// sc : o(1)
*/

/*// power set
 vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int totalsubsets = 1 << n;
        vector<vector<int>> ans;
        for(int bit = 0 ; bit < totalsubsets ; bit++){
             vector<int> list;
             for(int i = 0 ; i < n ; i++){
                if(bit & (1 << i)){
                    list.push_back(nums[i]);
                }
             }
               ans.push_back(list);
        }
        return ans;
    }
*/

// Xor of numbers in a given range

/*//brute force approach
    int findRangeXOR(int l, int r){			
		int ans = 0;
		for(int i=l; i <= r; i++) {
		    ans ^= i;
		}
		return ans;
	}
int main() {
    int l = 3, r = 5;
    int ans = findRangeXOR(l, r);
    cout << "The XOR of numbers from " << l << " to " << r << " is: " << ans;
    return 0;
}


//optimized approach
  int XORtillN(int n) {
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n+1;
        if(n % 4 == 3) return 0;
        return n;
    }
    
    int findRangeXOR(int l, int r){			
		return XORtillN(l-1) ^ XORtillN(r);
	}
int main() {
    int l = 3, r = 5;
    int ans = findRangeXOR(l, r);
    cout << "The XOR of numbers from " << l << " to " << r << " is: " << ans;
    return 0;
}
*/
//print all prime factors of a number
bool isPrime(int x) {
    if (x < 2) return false;

    for (int d = 2; d <= x / d; d++) {
        if (x % d == 0) return false;
    }

    return true;
}

vector<int> primeFactorsBrute(int n) {
    vector<int> factors;

    for (long long i = 2; i <= n; i++) {
        if (n % i == 0 && isPrime(i)) {
            factors.push_back(i);
        }
    }

    return factors;
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> factors = primeFactorsBrute(n);
    cout << "Prime factors of " << n << " are: ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}
