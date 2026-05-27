#include<bits/stdc++.h>
using namespace std;

string findOrder(vector<string> &dict, int n, int k){
    vector<int> adj[k];
    vector<int> inDegree(k,0);
    for(int i=0;i<n-1;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.length(), s2.length());
        for(int j=0;j<len;j++){
            if(s1[j] != s2[j]){
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                inDegree[s2[j] - 'a']++;
                break;
            }
        }
    }

    queue<int> q;
    for(int i=0;i<k;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    string ans = "";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans += char(node + 'a');
        for(auto it : adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0) q.push(it);
        }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<string> dict(n);
    for(int i=0;i<n;i++){
        cin>>dict[i];
    }
    string ans = findOrder(dict, n, k);
    cout<<ans<<endl;
    return 0;
}