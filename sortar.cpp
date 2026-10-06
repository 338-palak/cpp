#include<bits/stdc++.h>
using namespace std;
int sortarray(vector<int> &arr){
    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] < arr[i+1]){
            return true;
        
        }
    }
    return false;
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    if(sortarray(arr)){
        cout << "the array is sorted" << endl;

    }
    else{
        cout << "the array is not sorted" << endl;
    }
        return 0;   

}