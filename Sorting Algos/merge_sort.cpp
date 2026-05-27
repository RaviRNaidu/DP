#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int first,int mid, int last){
    vector<int> temp;
    int left=first;
    int right=mid+1;
    while(left<=mid && right<=last){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left ++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left ++;
    }

    while(right<=last){
        temp.push_back(arr[right]);
        right ++;
    }


    for (int i = first; i <= last; i++) {
        arr[i] = temp[i - first];
    }
    // for(int i=0;i<temp.size();i++){
    //     arr[first+i]= temp[i];
    // }
}

void merge_sort(vector<int>& arr,int first, int last){
    if(first>=last) return;
    int mid= (first+last)/2;
    merge_sort(arr, first, mid);
    merge_sort(arr,mid+1,last);
    merge(arr,first,mid,last);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    merge_sort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}