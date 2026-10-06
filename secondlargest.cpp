#include<bits/stdc++.h>
using namespace std;
//better
int secondlargest(vector<int> arr , int n){
    int largest = arr[0];
    for(int i = 0 ; i < n ; i++){
        if(largest < arr[i]){
            largest = arr[i];
        }
    }
    int slargest = -1;
    for(int i = 0 ; i < n ; i++){
        if(slargest < arr[i] && largest != arr[i]){
            slargest = arr[i];
        }
       
    }
 return slargest;
}
int main(){
    vector<int> arr = {1,3,4,6,2};
    int n = arr.size();
    cout << "the secondlargest number is : " << secondlargest(arr , n) ;
    return 0;
}
//optimal
int secondlarge(vector<int> &arr , int n){
    int largest = INT_MIN;
    int slargest = INT_MIN;
    for(int i = 0 ; i < n ; i++){
      if(arr[i] > largest){
        slargest = largest;
        largest = arr[i];
      }
        
        else if(slargest < arr[i] && arr[i] != largest){
            slargest = arr[i];
        }
    }
    return slargest;
}
int main(){
    int  n;
    cout << "enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "enter the elements:";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    int result = secondlarge(arr,n );
    if(result == INT_MIN){
        cout << "no secondlarge number is there";
    }else{
        cout << "second largest element is: " << result;
    }
    return 0;
}
// to find ssmallest and slargest;
int slarge(vector<int> &arr , int n){
    int largest = INT_MIN;
    int slargest = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i]   ;
         }
         else if(slargest < arr[i] && arr[i] != largest){
            slargest = arr[i];
         }
    }
    return slargest;
}
int sSmall(vector<int> &arr , int n){
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] < smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] != smallest && arr[i] < ssmallest){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

int main(){
    vector<int> arr = {1,2,3,4,6};
    int n = arr.size();
    int slargee = slarge(arr,n);
    int ssmall = sSmall(arr,n);
    cout << "second largest number is:" << slargee << endl;
    cout << "second smallest number is:" << ssmall;
    return  0;

}