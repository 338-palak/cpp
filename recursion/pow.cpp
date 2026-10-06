#include <iostream>
#include <cstdio>
using namespace std;
/*
double myPow(double x, int n) {
    // Base cases
    if (n == 0 || x == 1.0) return 1.0;

    // Use long long to safely store INT_MIN without overflow
    long long exp = n;
    
    // Handle negative powers
    if (exp < 0) {
        x = 1.0 / x;
        exp = -exp;
    }

    double ans = 1.0;

    // Brute force: multiply x linearly exp times
    for (long long i = 0; i < exp; i++) {
        ans *= x;
    }

    return ans;
}

int main() {
    // Output: 1024.0000
    printf("%.4f\n", myPow(2.0000, 10));

    // Output: 0.2500
    printf("%.4f\n", myPow(2.0000, -2));

    return 0;
}*/

/*// optimal solution
class Solution {
public:
   double solve(double x , long long n ){
    if(n == 0) return 1.0; // it is a base condition
    double half = solve(x , n/2);
    if(n % 2 == 0){
        return half*half;
    }else{
        return x*half*half;
    }

}
    double myPow(double x, int n) {
        long long exp = n;
        if(exp < 0){
            x = 1.0/x;
            exp = -exp;
        }
        return solve(x,exp);
        
        
    }
};*/
// binary approach
#include <iostream>
#include <cstdio>
using namespace std;

double myPow(double x, int n) {
    long long exp = n; // Handles INT_MIN safely without overflow

    // Handle negative exponents: x^(-n) = (1/x)^n
    if (exp < 0) {
        x = 1.0 / x;
        exp = -exp;
    }

    double ans = 1.0;

    while (exp > 0) {
        // If exponent is odd, multiply the current base into ans
        if (exp % 2 == 1) {
            ans *= x;
            exp -= 1; // Optional, as integer division below handles it
        }

        // Square the base and halve the exponent
        x *= x;
        exp /= 2;
    }

    return ans;
}

int main() {
    printf("%.4f\n", myPow(2.0000, 10));  // Output: 1024.0000
    printf("%.4f\n", myPow(2.0000, -2));  // Output: 0.2500
    return 0;
}
