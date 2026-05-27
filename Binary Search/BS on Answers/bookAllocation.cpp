#include <bits/stdc++.h>
using namespace std;

//tc --> o(n) + o((sum - maxi + 1) * n)  sc --> o(1)
bool check(vector<int> &arr, int max, int stu){
    int stucnt = 1;
    int book = arr[0];
    for(int i=1;i<arr.size();i++){
        if(book + arr[i] <= max){
            book += arr[i];
        }
        else{
            stucnt += 1;
            book = arr[i];
        }
    }
    if(stucnt == stu){
        return true;
    }
    else return false;
}
int brute(vector<int> &arr, int n, int stu){
    if(stu > n) return -1;
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
        sum += arr[i];
    }

    for(int i=maxi;i<=sum;i++){
        if(check(arr, i, stu) == true){
            return i;
        }
    }
    return -1;
}

int checkForOptimal(vector<int> &arr, int max){
    int stucnt = 1;
    int book = arr[0];
    for(int i=1;i<arr.size();i++){
        if(book + arr[i] <= max){
            book += arr[i];
        }
        else{
            stucnt += 1;
            book = arr[i];
        }
    }
    return stucnt;
}

//tc --> o(n) + o(log base2 sum-max+1 * n)
int optimal(vector<int> &arr, int n, int stu){
    if(stu > n) return -1;
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
        sum += arr[i];
    }

    int low = maxi;
    int high = sum;
    while(low <= high){
        int mid = (low + high) / 2;
        if(checkForOptimal(arr, mid) > stu){
            low = mid + 1;            
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int stu; 
    cin>>stu;
    cout<<optimal(arr, n, stu);
    return 0;
}
