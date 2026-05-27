#include <bits/stdc++.h>
using namespace std;

//tc -->o(n)  sc-->o(1)
vector<int> brute(vector<int> &arr, int n, int target){
    vector<int> ans;
    int first = -1;
    int last = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            if(first == -1 ) first = i;
            last = i;
        }
    }
    ans.push_back(first);
    ans.push_back(last);
    return ans;
}

//using lower bound and upper bound
int loopLOWEBOUND(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high) / 2;
        //maybe an answer
        if(arr[mid] >= target){
            ans = mid;
            //look for smaller index 
            high = mid - 1;
        }
        else {
            low = mid + 1;//look for right side
        }
    }
    return ans;
}
int loopUPPERBOUND(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high ){
        int mid  = ( low + high ) / 2;
        //maybe an answer
        if(arr[mid] > target){
            ans = mid;
            //look for smaller index 
            high = mid - 1;
        }
        else{
            low = mid + 1;//look for right side
        }
    }
    return ans;
}
vector<int> better(vector<int> &arr, int n, int target){
    int first = loopLOWEBOUND(arr, n, target);
    if(first == n || arr[first] != target){
        return {-1,-1};
    }
    else{
        return {first, loopUPPERBOUND(arr, n, target) - 1};
    }
}

//using seperate binary search
pair<int, int> binaryy(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n-1;
    int first = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    int low1 = 0;
    int high1 = n-1;
    int last = -1;
    while(low1 <= high1){
        int mid = (low1 + high1) / 2;
        if(arr[mid] == target){
            last = mid;
            low1 = mid + 1;;
        }
        else if(arr[mid] > target){
            high1 = mid - 1;
        }
        else{
            low1 = mid + 1;
        }
    }
    if(first == -1){
        return {-1,-1};
    }
    else{
        return {first,last};
    }
}

// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int target;
//     cin>>target;
//     vector<int> ans = binaryy(arr, n, target);
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }
//     return 0;
// }

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    pair<int,int> ans = binaryy(arr, n, target);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}


