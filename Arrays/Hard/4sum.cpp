#include <bits/stdc++.h>
using namespace std;
//tc o(n^4)
//sc o(no of quards) * 2
vector<vector<int>> brute(vector<int> &arr, int n){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int h=k+1;h<n;h++){
                    if(arr[i] + arr[j] + arr[k] + arr[h] == 0){
                        vector<int> temp = {arr[i],arr[j],arr[k],arr[h]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//tc o(n^3)* log(m) inside the set
// sc o(n) for storing the elements in the set        o(no of quards) * 2
vector<vector<int>> betterHASH(vector<int> &arr, int n, int target){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hashset;
            for(int k=j+1;k<n;k++){
                int rem = target - (arr[i]+arr[j]+arr[k]);
                if(hashset.find(rem) != hashset.end()){
                    vector<int> temp = {arr[i],arr[j],arr[k],rem};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin() , st.end());
    return ans;
}

//tc o(n*n* n this one is for the while loop)
//sc o(no of quards) only for returning the answer
vector<vector<int>> optimall(vector<int> &arr, int n, int target){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j > i+1 && arr[j] == arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k < l){
                long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                if(sum < target){
                    k++;
                }
                else if(sum > target){
                    l--;
                }
                else{
                    vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while( k < l && arr[k] == arr[k-1]) k++;
                    while( k < l && arr[l] == arr[l+1]) l--;
                }
            }
        }
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
    int target;
    cin>>target;
    vector<vector<int>> ans = optimall(arr, n, target);
    for(auto it: ans){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}