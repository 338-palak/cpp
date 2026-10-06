#include<bits/stdc++.h>
using namespace std;
void leftrot(vector<int> &arr , int n){
    if (arr.empty()) return ;
      int temp = arr[0];
      for(int i = 1 ; i < n; i++){
        arr[i-1] = arr[i];

      }
      arr[n-1] = temp;
      for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
      }

}
int main(){
  
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    cout << "The largest element in the array is: " ; leftrot(arr, n) ;  
    return 0;
}
