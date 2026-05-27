#include<bits/stdc++.h>
using namespace std;

int better(vector<int> &arr,int n){
    set<int> st;
    int maxxnt = 1;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    for(auto it:st){
        if(st.find(it - 1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x + 1) != st.end()){
                cnt ++;
                x = x + 1;
            }
            maxxnt = max(maxxnt, cnt);
        }
    }
    return maxxnt;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = better(arr, n);
    cout<<ans;
    return 0;
}