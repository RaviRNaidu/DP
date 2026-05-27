#include<bits/stdc++.h>
using namespace std;

vector<int> findPSEE(vector<int> &arr, int n){
    vector<int> PSEE(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(st.empty()){
            PSEE[i] = 0;
        }
        else{
            PSEE[i] = st.top();
        }
        st.push(i);
    }
    return PSEE;
}

vector<int> findNSE(vector<int> &arr, int n){
    vector<int> NSE(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            NSE[i] = n;
        }
        else{
            NSE[i] = st.top();
        }
        st.push(i);
    }
    return NSE;
}

//TC -> O(5N)   SC -> O(4N)
int areaa(vector<int> &arr, int n){
    vector<int> PSEE = findPSEE(arr,n);
    vector<int> NSE = findNSE(arr,n);
    int MaxArea = INT_MIN;
    for(int i=0;i<n;i++){
        int area = arr[i] * (NSE[i] - PSEE[i] - 1);
        MaxArea = max(MaxArea, area);
    }
    return MaxArea;
}

//TC -> O(2N)   SC -> O(N)
int optimal(vector<int> &arr, int n){
    int MaxArea = INT_MIN;
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            int element = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            int area = (arr[element] * (nse - pse - 1));
            MaxArea = max(MaxArea, area);
        }
        st.push(i);
    }
    while(!st.empty()){
        int index = st.top();
        st.pop();
        int nse = n;
        int pse = st.empty() ? -1 : st.top();
        int area = (arr[index] * (nse - pse - 1));
        MaxArea = max(MaxArea, area);
    }
    return MaxArea;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = optimal(arr, n);
    cout<<ans<<endl;
    return 0;
}