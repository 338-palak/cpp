#include<bits/stdc++.h>
using namespace std;
/*int sqrt(int x){
    int ans = 1;
    for(int i = 0 ; i <= x ; i++){
        if(i*i <= x){
            ans = i;
        }
    }
    return ans;
}
int main(){
    int x = 8;
    cout << sqrt(x) << endl;
}
// brute force approach 
// The time complexity of this approach is O(sqrt(n)) and the space complexity is O(1)
*/
/*// binary search approach
int squareroot(int x){
    int low = 1, high = x;
    int ans = 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(mid * mid <= x){
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;}
int main(){
    int x = 8;
    cout << squareroot(x) << endl;
}*/

//nth root of a number
/*#include <bits/stdc++.h>
using namespace std;

long long power(int base, int n) {
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= base;
    }
    return ans;
}

int NthRoot(int n, int m) {

    for (int i = 1; i <= m; i++) {

        long long val = power(i, n);

        if (val == m)
            return i;
// tc o(nlogm) sc o(1)
        else if (val > m)
            break;
    }

    return -1;
}

int main() {

    int n = 3, m = 27;

    cout << NthRoot(n, m);

    return 0;
}*/
// binary search approach
int func(int mid, int n, int m){
    long long ans = 1;

    for(int i = 1; i <= n; i++){
        ans *= mid;

        if(ans > m)
            return 2;
    }

    if(ans == m)
        return 1;

    return 0;
}

int NTHROOT(int n, int m){
    int low = 1, high = m;

    while(low <= high){
        int mid = low + (high - low) / 2;

        int midN = func(mid, n, m);

        if(midN == 1)
            return mid;
        else if(midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(){
    int n = 3, m = 27;
    cout << NTHROOT(n, m) << endl;
}