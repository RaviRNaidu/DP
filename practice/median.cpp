#include <bits/stdc++.h>
using namespace std;

double brute(vector<int> &arr1, int n, vector<int> &arr2, int m){
    if(n < m){
        brute(arr2, m, arr1, n);
    }
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i < n && j < m ){
        if(arr1[i] <= arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i < n){
        ans.push_back(arr1[i]);
        i++;
    }
    while(j < m){
        ans.push_back(arr2[j]);
        j++;
    }

    int x = ans.size();
    int index = (x/2);
    if(x % 2 == 1){
        return ans[index];
    }
    else{
        double result = ((double) ans[index] + (double)ans[(index) - 1]) / 2.0;
        return result;
    }
    return -1;
}


double better(vector<int> &arr1, int n, vector<int> &arr2, int m){
    int index = (n + m) / 2;
    int index1 = index - 1;
    int index2 = index;
    int el1 = 0;
    int el2 = 0;
    int i = 0;
    int j = 0;
    int cnt = 0;
    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            if(cnt == index1){
                el1 = arr1[i];
            }
            if(cnt == index2){
                el2 = arr1[i];
            }
            cnt ++;
            i++;
        }
        else{
            if(cnt == index1){
                el1 = arr2[j];
            }
            if(cnt == index2){
                el2 = arr2[j];
            }
            cnt ++;
            j++;
        }
    }

    while(i < n){
        cnt ++;
        if(cnt == index1){
            el1 = arr1[i];
        }
        if(cnt == index2){
            el2 = arr1[i];
        }
        i++;
    }

    while(j < m){
        cnt ++;
        if(cnt == index1){
            el1 = arr2[j];
        }
        if(cnt == index2){
            el2 = arr2[j];
        }
        j++;
    }

    if(index % 2 == 1){
        return el2;
    }
    else {
        double ans = ((double)el1 + (double)el2) / 2.0;
        return ans;
    }
}


int main(){
    int n;
    cin>>n;
    vector<int> arr1(n);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int m;
    cin>>m;
    vector<int> arr2(m);
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    cout<<brute(arr1, n, arr2, m);
    return 0;
}