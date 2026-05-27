#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> &greed, int n, vector<int> &size, int m){
    sort(greed.begin(), greed.end());
    sort(size.begin(), size.end());
    int l = 0;
    int r = 0;
    int ans = 0;
    while(l < n && r < m){
        if(size[r] >= greed[l]){
            ans++;
            r++;
            l++;
        }
        else if(size[r] < greed[l]){
            r++;
        }
    }
    return ans;
}

//TC -> O(N LOG N + N LOG N + N)    SC -> O(1)
int striver(vector<int> &greed, int n, vector<int> &size, int m){
    sort(greed.begin(), greed.end());
    sort(size.begin(), size.end());
    int l = 0;
    int r = 0;
    while(l < n && r < m){
        if(size[r] >= greed[l]){
            l++;
        }
        r++;
    }
    return l;
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
    int ans = striver(greed,n,size,m);
    cout<<ans<<endl;
    return 0;
}