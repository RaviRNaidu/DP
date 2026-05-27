#include<bits/stdc++.h>
using namespace std;


//TC -> O(n * 2^n)
//SC -> O(2^n * n) near about this 
vector<vector<int>> powerset(vector<int> &arr, int n){
    int subsets = 1<<n;
    vector<vector<int>> ans;
    for(int i=0;i<subsets;i++){
        vector<int> res;
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                res.push_back(arr[j]);
            }
        }
        ans.push_back(res);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<int>> ans = powerset(arr,n);
    // for(auto it : ans){
    //     for(auto i : it){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }
    cout << "Initial Input Array: ";
    for (auto it: arr){
        cout<<it<<" ";
    }
    cout << endl;
    cout << "Subsets: " << endl;
    for (auto subset : ans) {
        cout << "[ ";
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}