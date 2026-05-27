#include<bits/stdc++.h>
using namespace std;

struct Data{
    int start;
    int end;
    int pos;
};

bool comp(Data a, Data b){
    return (a.end < b.end);
}

//TC -> O(2N + N LOG N) SC -> O(3*N) + O(N)if u want to return the order
int solution(vector<int> &start, vector<int> &end, int n){
    Data arr[n];
    for(int i=0;i<n;i++){
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i+1;
    }

    sort(arr, arr+n, comp);

    int cnt = 0;
    int endTime = 0;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(arr[i].start > endTime){
            cnt++;
            ans.push_back(arr[i].pos);
            endTime = arr[i].end;
        }
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    vector<int> greed(n);
    for(int i=0;i<n;i++){
        cin>>greed[i];
    }
    int m;
    cin>>m;
    vector<int> size(m);
    for(int i=0;i<m;i++){
        cin>>size[i];
    }
    int ans = solution(greed,size,m);
    cout<<ans<<endl;
    return 0;
}