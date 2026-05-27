#include<bits/stdc++.h>
using namespace std;

bool prime(int n){
    int counter=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0)
        {
            counter=counter+1;
            if((n/i)!=i){
                counter=counter+1;
            }
        }
    }
    if(counter==2)
    {
        return true;
    }
    else return false;
}

void brute(vector<int,int> &queries, int q){
    for(int i=0;i<q;i++){
        int cnt = 0;
        int l = queries[i][0];
        int r = queries[i][1];
        for(int j=l;j<=r;j++){
            if(prime(j)){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}

int main(){
    int q;
    cin>>q;
    vector<int,int> queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i][0];
        cin>>queries[i][1];
    }
    brute(queries, q);
    // cout<<ans;
    return 0;
}