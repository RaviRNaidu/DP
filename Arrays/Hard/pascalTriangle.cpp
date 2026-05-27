#include <bits/stdc++.h>
using namespace std;

//tc 
vector<int> functionforquestion3(int row){
    vector<int> Tanswer;
    long long ans = 1;
    Tanswer.push_back(ans);
    for(int col=1;col<row;col++){
        ans = ans * (row - col);
        ans = ans / col;
        Tanswer.push_back(ans);
    }
    return Tanswer;
}
vector<vector<int>> quest3(int n){
    vector<vector<int>> finallANS;
    for(int i=1;i<=n;i++){
        finallANS.push_back(functionforquestion3(i));
    }
    return finallANS;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> ans = quest3(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<ans[i].size();j++){  //make sure u give ans[i].size() instead of n
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



//tc o(n) o(n)
void quest2(int n){
    long long ans = 1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++){
        ans = ans * (n - i);
        ans = ans / i;
        cout<<ans<<" ";
    }
}



// tc o(r) sc o(1)
void quest1(int n, int m){
    long long res = 1;
    for(int i=0;i<m;i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    cout<<res<<endl;
}

// int main(){
//     int n ;
//     cin>>n;
//     quest2(n);
// }

// int main(){
//     int n , m;
//     cin>>n;
//     cin>>m;
//     quest1(n-1, m-1);
// }