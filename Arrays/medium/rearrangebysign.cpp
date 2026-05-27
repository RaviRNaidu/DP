#include<bits/stdc++.h>
using namespace std;

//tc = o(n+n/2)     sc = o(n)
void brute(int arr[], int n){
    vector<int> pos,neg;
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }

    for(int i=0;i<pos.size();i++){
        arr[i*2] = pos[i];
    }

    for(int i=0;i<neg.size();i++){
        arr[i*2+1] = neg[i];
    }
}

//optimal  TC = O(N)     SC = O(N)
vector<int> optimal(int arr[],int n){
    vector<int> ans(n,0);
    int pos = 0;
    int neg = 1;
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            ans[pos] = arr[i];
            pos += 2;
        }

        else{
            ans[neg] = arr[i];
            neg += 2;
        }
    }
    return ans;
}

//optimal for another question which dosent contain equal number of positives n negatives
//TC = o(2n)for the worst case and o(n+(n/2))for best casee    sc=O(n)
void variante(int arr[], int n){
    vector<int> pos,neg;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    if(pos.size() > neg.size()){
        for(int i=0;i<neg.size();i++){
            arr[i*2] = pos[i];
            arr[i*2+1] = neg[i];
        }

        int index = neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            arr[index] = pos[i];
            index ++;
        }
    }
    else{
        for(int i=0;i<pos.size();i++){
            arr[i*2] = pos[i];
            arr[i*2+1] = neg[i];
        }

        int index = pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            arr[index] = neg[i];
            index ++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    variante(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     vector<int> sortedd=optimal(arr, n);
//     for(int i=0;i<sortedd.size();i++){
//         cout<<sortedd[i]<<" ";
//     }
//     return 0;
// }