#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i] = temp[i - low];
    }
} 

int counting(vector<int> &arr, int low, int mid, int high){
    int cnt = 0;
    int right = mid + 1;
    for(int i=low;i<=mid;i++){
        while(right <= high && arr[i] > 2*arr[right]) right ++;
        cnt +=  (right - (mid+1));
    }
    return cnt;
}

int optimal(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += optimal(arr, low, mid);
    cnt += optimal(arr, mid+1,high);
    cnt += counting(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

//tc --> o(n^2) sc --> o(1)
int brute(vector<int> &arr, int n){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > 2*arr[j]){
                cnt += 1;
            }
        }
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = optimal(arr, 0, n-1);
    cout<<ans;
    return 0;
}