#include<bits/stdc++.h>
using namespace std;

//TC -> O(N * M)
//SC -> O(2 * M)
int spaceOptimization(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m+1, 0);

    for(int i=0;i<=m;i++){
        prev[i] = 0; 
    }

    for(int i=1;i<=n;i++){
        vector<int> curr(m+1, 0);
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                curr[j] = 1 + prev[j-1];
            }
            else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }

    return prev[m];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    int LCS = spaceOptimization(s1, s2);
    //me
    int del = n - LCS;
    int insert = m - LCS;
    cout<<del+insert<<endl;
    //striver
    int ans = (n + m) - (2 * LCS);
    cout<<ans<<endl;
    return 0;
}