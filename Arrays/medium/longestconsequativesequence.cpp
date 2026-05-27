#include<bits/stdc++.h>
using namespace std;

//brutee tc --> O(n^2)
bool ls(vector<int> &arr,int n, int x){
    for(int i=0;i<n;i++){
        if(arr[i] == x){
            return true;
        }
    }
    return false;
}
int brute(vector<int> &arr, int n){
    int longest = 1;
    for(int i=0;i<n;i++){
        int x = arr[i];
        int cnt = 1;
        while(ls(arr, n, x+1) == true){
            x += 1;
            cnt += 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

//tc --> o(n log n + n)
int better(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    int Premini = INT_MIN;
    int longest = 1;
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i] - 1 == Premini){
            count += 1;
            Premini = arr[i];
        }
        else if(arr[i]  != Premini){
            Premini = arr[i];
            count = 1;
        }
        longest = max(longest, count);
    }
    return longest;
}

//tc o(3n) if set takes o(1)
int optimall(vector<int> &arr,int n){
    unordered_set<int> st;
    int longest = 1;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    for(auto it:st){
        if(st.find(it - 1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                cnt += 1;
                x = x + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
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