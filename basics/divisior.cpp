#include<bits/stdc++.h>
using namespace std;

int divisior(int n){
    vector<int> ls;
    //O(sqrt(n))
    for(int i=1;i*i<=n;i++){
        if(n%i==0)
        {
            ls.push_back(i);
            if((n/i) != i){
                ls.push_back(n/i);
            }
        }
    }
    //O(no of factors*log(no of factors))
    sort(ls.begin(),ls.end());
    //O(no of factors)
    for(auto it:ls)cout<<it<<" ";
}

int main(){
    int n;
    cin>>n;
    divisior(n);
    return 0;
}