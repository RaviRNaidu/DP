#include<bits/stdc++.h>
using namespace std;

//brute
string brute(int arr[], int n, int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == target){
                return "Yes";
            }
        }
    }
    return "NO";
}

//better
string better(int arr[], int n, int target){
    map<int, int> mpp;
    for(int i=0;i<n;i++){
        int rem = target - arr[i];

        if(mpp.find(rem) != mpp.end()){
            return "Yes";
        }

        mpp[arr[i]] = i;
    }
    return "No";
}

vector<int> read(int arr[], int n, int target){
    map<int, int> mpp;
    for(int i=0;i<n;i++){
        int a = arr[i];

        int needMore = target - a;

        if(mpp.find(needMore) != mpp.end()){
            return {mpp[needMore], i};
        }

        mpp[a] = i;
    }
    return {-1, -1};
}

//greedy approach using two pointers itseems...only works if u want to return yes or no
string bolo(vector<int> &arr, int n, int target){
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = n-1;
    while(i < j){
        int sum = arr[i] + arr[j];
        if(sum == target){
            return "Yes";
        }

        else if(sum < target){
            i++;
        }

        else{
            j--;
        }
    }
    return "No";
}
 

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    vector<int> ans = read(arr, n, target);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}



//GREEDYYYYYY OR FOR THE SORTINGGGGGGG
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int target;
//     cin>>target;
//     string ans = bolo(arr, n, target);
//     cout<<ans;
//     return 0;
// }