#include<bits/stdc++.h>
using namespace std;

//DONE BY ME!
vector<int> brute(vector<int> &arr, int n){
    stack<int> st;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            st.push(arr[i]);
        }
        else{
            if(st.empty()){
                ans.push_back(arr[i]);
            }
            else if(!st.empty()){
                int left = st.top();
                int right = abs(arr[i]);
                if(left < right){
                    st.pop();
                    i--;
                }
                else if(left == right){
                    st.pop();
                }
                else{
                    continue;
                }
            }
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

vector<int> Striverr(vector<int> &arr, int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            ans.push_back(arr[i]);
        }
        else{
            while(!ans.empty() && ans.back() > 0 && ans.back() < abs(arr[i])){
                ans.pop_back();
            }
            if(!ans.empty() && ans.back() == abs(arr[i])){
                ans.pop_back();
            }
            else if(ans.empty() || ans.back() < 0){
                ans.push_back(arr[i]);
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
    vector <int> ans = Striverr(arr, n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}