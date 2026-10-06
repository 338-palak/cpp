#include<bits/stdc++.h>
using namespace std;
// to print all subsequence equal to target
/*void printsubsequence(int index , vector<int>& ds , int currentsum , int target , int arr[] , int n){
    //base case
    if(index == n){
        if(currentsum == target){
            for(int value:ds){
                cout << value << " ";
            }
            cout << endl;
        }
        return;
    }
    // to pick
    ds.push_back(arr[index]);
    currentsum+=arr[index];

    printsubsequence(index+1,ds,currentsum,target,arr,n);

    //undo pick
    currentsum-=arr[index];
    ds.pop_back();

    // do not pick
    printsubsequence(index+1,ds,currentsum,target,arr,n);
}
int main(){
    int arr[]={1,2,1};
    int n=3;
    int target=2;

    vector<int> ds;

    printsubsequence(0,ds,0,target,arr,n);

    return 0;
}
*/
/*
bool printsubsequence(int index , vector<int>& ds , int currentsum , int target , int arr[] , int n){
    //base case
    if(index == n){
        if(currentsum == target){
            for(int value:ds){
                cout << value << " ";
            }
            cout << endl;
            return true;
        }
       else  return false;
    }
    // to pick
    ds.push_back(arr[index]);
    currentsum+=arr[index];

   if(printsubsequence(index+1,ds,currentsum,target,arr,n) == true){
    return true;
   }

    //undo pick
    currentsum-=arr[index];
    ds.pop_back();

    // do not pick
    if(printsubsequence(index+1,ds,currentsum,target,arr,n) == true) return true;
    return false;
}
int main(){
    int arr[]={1,2,1};
    int n=3;
    int target=2;

    vector<int> ds;

    printsubsequence(0,ds,0,target,arr,n);

    return 0;
}*/

/*
// count the subsequences with sum = target;
int countSubsequences(int index,int sum,int target,int arr[],int n){
    if(index == n){
        if(sum == target){
            return 1;
        }
        return 0;
    }
    sum += arr[index];
    int left = countSubsequences(index+1,sum,target,arr,n);

    sum-=arr[index];

    int right = countSubsequences(index+1,sum,target,arr,n);
    return left+right;
}
int main(){
    int arr[]={1,2,1};
    int n=3;
    int target=2;

    cout<<countSubsequences(0,0,target,arr,n);

    return 0;
}*/

//Check if there exists a subsequence with sum k
bool subsequenceExists(int index,int sum,int target,int arr[],int n){
    if(index==n){
        return sum==target;
    }

    // Pick
    sum+=arr[index];

    if(subsequenceExists(index+1,sum,target,arr,n)){
        return true;
    }

    // Backtrack
    sum-=arr[index];

    // Not pick
    if(subsequenceExists(index+1,sum,target,arr,n)){
        return true;
    }

    return false;
}

int main(){
    int arr[]={1,2,1};
    int n=3;
    int target=2;

    cout<<boolalpha;
    cout<<subsequenceExists(0,0,target,arr,n);

    return 0;
}

