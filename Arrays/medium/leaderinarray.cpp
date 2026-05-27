#include<bits/stdc++.h>
using namespace std;

//ME
vector<int> leaderBrute(int arr[], int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]) {
                cnt++;
            }
        }
        if(cnt == n-i-1){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

//striver
vector<int> leaderBruteS(int arr[], int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        int leader = true;
        for(int j=i+1;j<n;j++){
            if(arr[j] > arr[i]) {
                leader = false;
                break;
            }
        }
        if(leader == true){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> leaderOptimal(int arr[], int n){
    vector<int> ans;
    int max = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i] > max){
            ans.push_back(arr[i]);
            max = arr[i];
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans = leaderOptimal(arr, n);
    for(int j=0;j<ans.size();j++){
        cout<<ans[j]<<" ";
    }
    return 0;
}