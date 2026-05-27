#include<bits/stdc++.h>
using namespace std;

//TC -> O(N^2)      SC -> O(N)
vector<int> brute(vector<int> &arr, int n){
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int cnt = 1;
        for(int j=i-1;j>=0;j--){
            if(arr[j] < arr[i]){
                cnt++;
            }   
            else{
                break;
            }
        }
        ans[i] = cnt;
    }
    return ans;
}


//TC -> O(3N)   SC -> O(3N)
vector<int> better(vector<int> &arr, int n){
    vector<int> ans(n);
    vector<int> PGL(n);
    stack<int> st;
    for(int i=0;i<n;i++){       //TC -> O(N)
        while(!st.empty() && arr[st.top()] <= arr[i]){      //TC -> O(N)
            st.pop();
        }
        if(st.empty()){
            PGL[i] = -1;
        }
        else{
            PGL[i] = st.top();
        }
        st.push(i);
    }

    for(int i=0;i<n;i++){           //TC -> O(N)
        ans[i] = i - PGL[i];
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
    vector<int> ans = better(arr, n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}