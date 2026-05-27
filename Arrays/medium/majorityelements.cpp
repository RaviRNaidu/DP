#include<bits/stdc++.h>
using namespace std;

//brute
int brute(int arr[], int n){
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[j] == arr[i]){
                cnt++;
            }
        }
        if(cnt > (n/2)) return arr[i];
    }
}

//better using hashmap
int better(int arr[], int n){
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]] ++;  //this is how u store counter along with the number
    }

    for(auto it:mpp){
        if(it.second > (n/2)){
            return it.first;
        }
    }
    return -1;
}

//optimall uses MOORE'S VOTING ALGORITHMMM IMPORTANTT
int moore(int arr[], int n){
    int cnt = 0;
    int el;
    for(int i=0;i<n;i++){
        if(cnt == 0){
            cnt++;
            el = arr[i];
        }
        else if(arr[i] == el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int counter = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == el){
            counter++;
        }
        if(counter > (n/2)){
            return el;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = moore(arr, n);
    cout<<ans;
    return 0;
}