#include <bits/stdc++.h>
using namespace std;

//tc o(n log n) for sorting + o(n * n) for loop n while loop
//sc 0(no of unique elements) 
vector<vector<int>> optimall(vector<int> &arr, int n){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        if( i > 0 && arr[i] == arr[i-1]){
            continue;;
        }
        int j = i+1;
        int k = n-1;
        while( j < k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && arr[j] == arr[j-1] ) j++;
                while(j < k && arr[k] == arr[k+1] ) k--;
            }
        }
    }
    return ans;
}

//tc O(n*n*n*log(no of unique elements)) sc 2*O(no of triplets)
vector<vector<int>> brute(vector<int> &arr, int n){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> betterHASHSET(vector<int> &arr, int n){
    set<vector<int>> ans;
    for(int i=0;i<n-1;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int k = -(arr[i] + arr[j]);
            if(hashset.find(k) != hashset.end()){
               vector<int> temp = {arr[i], arr[j], k};
               sort(temp.begin() , temp.end());
               ans.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> finalans(ans.begin(), ans.end());
    return finalans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> ans = optimall(arr, n);
    // for(int i=0;i<=ans.size();i++){
    //     for(int j=0;j<=ans.size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(auto it: ans){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}