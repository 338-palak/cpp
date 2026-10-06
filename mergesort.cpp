#include<bits/stdc++.h>
using namespace std;
/* brute force
void merge(long long arr1[],long long arr2[],int n , int m){
   vector<long long> arr3(n+m) ;
    int left = 0 ;
    int right = 0 ;
    int index = 0 ;
    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            arr3[index] = arr1[left];
            index++ , left++;
        }
        else{
            arr3[index] = arr2[right];
            index++ , right++;
        }
    }
    while(left < n){arr3[index] = arr1[left];index++,left++;}
    while(right < m){arr3[index] = arr2[right];index++,right++;}
   
    for(int i = 0 ; i < n+m ; i++){
        if(i < n ) arr1[i] = arr3[i];
        else arr2[i-n] = arr3[i];

    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<long long> a(n), b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int j = 0; j < m; ++j) cin >> b[j];

    // use C-style arrays for existing merge signature
    vector<long long> a_copy = a, b_copy = b;
    merge(a_copy.data(), b_copy.data(), n, m);

    for(int i = 0; i < n; ++i){
        if(i) cout << ' ';
        cout << a_copy[i];
    }
    cout << '\n';
    for(int j = 0; j < m; ++j){
        if(j) cout << ' ';
        cout << b_copy[j];
    }
    cout << '\n';
    return 0;
}
    */
/*//optimal solution
void merge(long long arr1[],long long arr2[],int n,int m){
    
    int left = n-1;
    int right = 0 ;
    while(left >= 0 && right < m){
        if(arr1[left] > arr2[right])
        swap(arr1[left] , arr2[right]);
        left--,right++;
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
 


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<long long> a(n), b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int j = 0; j < m; ++j) cin >> b[j];

    // use C-style arrays for existing merge signature
    vector<long long> a_copy = a, b_copy = b;
    merge(a_copy.data(), b_copy.data(), n, m);

    for(int i = 0; i < n; ++i){
        if(i) cout << ' ';
        cout << a_copy[i];
    }
    cout << '\n';
    for(int j = 0; j < m; ++j){
        if(j) cout << ' ';
        cout << b_copy[j];
    }
    cout << '\n';
    return 0;
}
*/

// optimal solution using gap
void swap(long long arr1[],long long arr2[],int ind1 , int ind2){
    if(arr1[ind1] > arr2[ind2]){
        swap(arr1[ind1],arr2[ind2]);
    }

}

void merge(long long arr1[],long long arr2[],int n,int m){
    int len = (n+m);
    int gap = (len / 2) + (len % 2 );
    while(gap > 0){
        int left = 0 ;
         int right = left + gap;
         while(right < len){
            if(left < n && right >= n){
                swap(arr1 , arr2 ,left , right- n);
                
            }
            else if(left >= n ){
                swap(arr2 , arr2 , left-n , right - n);

            }
            else{
                swap(arr1 , arr1 , left , right);
            }
         
         left++,right++;
    }
    if(gap == 1){
        break;
    }
    gap = (gap / 2) + (gap % 2);
    }

}
int main(){
      ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<long long> a(n), b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int j = 0; j < m; ++j) cin >> b[j];

    // use C-style arrays for existing merge signature
    vector<long long> a_copy = a, b_copy = b;
    merge(a_copy.data(), b_copy.data(), n, m);

    for(int i = 0; i < n; ++i){
        if(i) cout << ' ';
        cout << a_copy[i];
    }
    cout << '\n';
    for(int j = 0; j < m; ++j){
        if(j) cout << ' ';
        cout << b_copy[j];
    }
    cout << '\n';
    return 0;
}
