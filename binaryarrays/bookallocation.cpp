#include<bits/stdc++.h>
using namespace std;
/*int func(vector<int> arr , int pages){
    int student = 1 , totalpages = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        if(totalpages + arr[i] <= pages){
            totalpages += arr[i];
        }
        else{
            student++;
            totalpages = arr[i];
        }
    }
    return student;
}
int bookallocation(vector<int> arr, int n, int m) {
    //m = no of students
    if(m > n){
        return -1;
    }
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(),0);
    for(int pages = low ; pages <= high ; pages++){
      int  cntstudent = func(arr, pages);
        if(cntstudent == m){
            return pages;

        }
    }
}
int main(){
    vector<int> arr = {25,46,28,49,24};
    int n = arr.size();
    int m = 4; // number of students
    cout << bookallocation(arr, n, m) << endl;
    return 0;
}*/

int func(vector<int> &arr , int pages){
    int student = 1 , totalpages = 0;
    for(int i = 0 ; i < arr.size(); i++){
        if(totalpages + arr[i] <= pages){
            totalpages+=arr[i];
        }else{
            student++;
            totalpages = arr[i];
        }
    }
    return student;

}
int book(vector<int> &arr , int m){
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low <= high){
    int mid = low + (high - low)/2;
   int cntstudent = func(arr,mid);
    if(cntstudent <= m){
        high = mid - 1;
    }else{
        low = mid + 1;
    }
   

}
 return low;

}
int main(){
    vector<int> arr = {25,46,28,49,24};
    int n = arr.size();
    int m = 4; // number of students
    cout << book(arr, m) << endl;
    return 0;
}


// same solution for split array & Painters partition problem