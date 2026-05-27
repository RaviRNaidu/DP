#include<bits/stdc++.h>
using namespace std;

//tc --> o(n log n)  sc --> o(n)  and we are ending up by altering the data.
int merge(vector<int> &arr, int first, int mid, int last){
    vector<int> temp;
    int cnt = 0;
    int left = first;
    int right = mid+1;
    while(left <= mid && right <= last){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);  // mid is the total elements present in the right side. since it is zero base indexing we are adding +1 but what is it not the first element which is greater so in that case we are using mid - left + 1.
            right++;                  // where the left is my current element.
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= last){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=first;i<=last;i++){
        arr[i] = temp[i - first];
    }
    return cnt;
}

int optimal(vector<int> &arr, int first, int last){
    int cnt = 0;
    if(first >= last) return cnt;
    int mid = (first + last) / 2;
    cnt += optimal(arr, first, mid);
    cnt += optimal(arr, mid + 1, last);
    cnt += merge(arr, first, mid, last);
    return cnt;
}

//tc --> o(n^2) sc --> o(1)
int brute(vector<int> &arr, int n){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
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