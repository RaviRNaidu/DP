#include<bits/stdc++.h>
using namespace std;

//brute
vector<int> intersectionn(vector<int> &arr1,vector<int> &arr2,int n, int m){
    vector<int> temp;
    int check[m] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr1[i] == arr2[j] && check[j] == 0){
                temp.push_back(arr1[i]);
                check[j] ++;
                break;
            }
            if(arr2[j]>arr1[i]) break;
        }
    }

    return temp;
}

//optimal
vector<int> intersectionOptimal(vector<int> &arr1,vector<int> &arr2,int n, int m){
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return ans;
}



int main(){
    int n, m;
    cin>>n;
    vector<int> arr1(n);
    for(int i=0;i<n;i++) cin>>arr1[i];
    cin>>m;
    vector<int> arr2(m);
    for(int i=0;i<m;i++) cin>>arr2[i];
    vector<int> intersectnnnn = intersectionOptimal(arr1, arr2, n, m);
    for(int i=0;i<intersectnnnn.size();i++){
        cout<<intersectnnnn[i]<<" ";
    }
    return 0;
}