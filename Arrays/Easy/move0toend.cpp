#include<bits/stdc++.h>
using namespace std;

vector<int> move(vector<int> &arr, int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }

    int size = temp.size();
    for(int i=0;i<size;i++){
        arr[i] = temp[i];
    }

    for(int i=size;i<n;i++){
        arr[i] = 0;
    }

    return arr;
}

//optimal
vector<int> moveOptimal(vector<int> &arr, int n){
    int j = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }

    if(j == -1) return arr; // return the same array if 0 is not found

    for(int i=j+1;i<n;i++){
        if(arr[i] != 0){
            swap(arr[j],arr[i]);
            j++;
        }
    }

    return arr;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    moveOptimal(arr, n);
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}