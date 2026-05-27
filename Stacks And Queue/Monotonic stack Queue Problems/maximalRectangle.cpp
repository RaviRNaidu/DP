#include<bits/stdc++.h>
using namespace std;


//DONE BY ME
//TC -> 0(n*m) + o(n * 2m)          sc -> o(n * m) + o(n)
int findingMaxRec(vector<vector<int>> &arr, int n, int m){
    vector<vector<int>> preSum(n,vector<int>(m));   //SC -> O(N*M)
    for(int i=0;i<m;i++){                           //TC -> O(N*M)
        int sum = 0;
        for(int j=0;j<n;j++){
            if(arr[j][i] == 0){
                preSum[j][i] = 0;
                sum = 0;
            }
            else{
                sum += 1;
                preSum[j][i] = sum;
            }
        }
    }

    int MaxRectangle = INT_MIN;
    for(int i=0;i<n;i++){                                //TC -> O(N*2M)
        stack<int> st;
        for(int j=0;j<m;j++){
            while(!st.empty() && preSum[i][st.top()] > preSum[i][j]){
                int element = st.top();
                st.pop();
                int nse = j;
                int pse = st.empty() ? -1 : st.top();
                MaxRectangle = max(MaxRectangle, preSum[i][element] * (nse - pse - 1));
            }
            st.push(j);
        }
        while(!st.empty()){
            int element = st.top();
            st.pop();
            int nse = m;
            int pse = st.empty() ? -1 : st.top();
            MaxRectangle = max(MaxRectangle, preSum[i][element] * (nse - pse - 1));
        }
    }

    return MaxRectangle;
}



int largestRectangleArea(vector<int> &arr, int n){
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



int striverrr(vector<vector<int>> &arr, int n, int m){
    vector<vector<int>> preSum(n,vector<int>(m));   //SC -> O(N*M)
    for(int i=0;i<m;i++){                           //TC -> O(N*M)
        int sum = 0;
        for(int j=0;j<n;j++){
            sum += arr[j][i];
            if(arr[j][i] == 0){
                preSum[j][i] = 0;
                sum = 0;
            }
            preSum[j][i] = sum;
        }
    }

    int MaxRectangle = 0;

    for(int i=0;i<n;i++){
        int area = largestRectangleArea(preSum[i],m);
        MaxRectangle = max(MaxRectangle,area);
    }

    return MaxRectangle;
}

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans = striverrr(arr, n, m);
    cout<<ans<<endl;
    return 0;
}