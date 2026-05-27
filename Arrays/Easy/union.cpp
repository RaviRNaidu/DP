#include<bits/stdc++.h>
using namespace std;

//brute
vector<int> unionn(vector<int> &arr1, vector<int> &arr2, int n, int m){
    set<int> st;
    vector<int> unionarr;
    for(int i=0;i<n;i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<m;i++){
        st.insert(arr2[i]);
    }

    for(auto it:st){
        unionarr.push_back(it);
    }

    return unionarr;
}


//optimal
vector<int> optimalunion(vector<int> &arr1,vector<int> &arr2,int n, int m){
    vector<int> unionArr;
    int i = 0;
    int j = 0;
    while(i<n && j<m){
        if(arr1[i] <= arr2[j]){
            if(unionArr.size() == 0 || unionArr.back() != arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(unionArr.size() == 0 || unionArr.back() != arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(j<m){
        if(unionArr.size() == 0 || unionArr.back() != arr2[j]){
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    while(i<n){
        if(unionArr.size() == 0 || unionArr.back() != arr1[i]){
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    return unionArr;
}


int main(){
    int n, m;
    cin>>n;
    vector<int> arr1(n);
    for(int i=0;i<n;i++) cin>>arr1[i];
    cin>>m;
    vector<int> arr2(m);
    for(int i=0;i<m;i++) cin>>arr2[i];
    vector<int> unionarr = optimalunion(arr1, arr2, n, m);
    for(int i=0;i<unionarr.size();i++){
        cout<<unionarr[i]<<" ";
    }
    return 0;
}