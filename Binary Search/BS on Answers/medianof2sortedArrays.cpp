#include <bits/stdc++.h>
using namespace std;

//tc --> o(n+m)  sc --> 0(1)
double better(vector<int> &arr1, int n, vector<int> &arr2, int m){
    int left = 0;
    int right = 0;
    int cnt = -1;
    int index = (n+m) / 2;
    int el1Ind = index;
    int el2Ind = index - 1;
    double el1;
    double el2;
    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            cnt += 1;
            if(cnt == el1Ind){
                el1 = arr1[left];
            }
            else if(cnt == el2Ind){
                el2 = arr1[left];
            }
            left++;
        }
        else {
            cnt += 1;
            if(cnt == el1Ind){
                el1 = arr2[right];
            }
            else if(cnt == el2Ind){
                el2 = arr2[right];
            }
            right++;
        }
    }
    while(left < n){
        cnt += 1;
        if(cnt == el1Ind){
            el1 = arr1[left];
        }
        else if(cnt == el2Ind){
            el2 = arr1[left];
        }
        left++;
    }
    while(right < m){
       cnt += 1;
        if(cnt == el1Ind){
            el1 = arr2[right];
        }
        else if(cnt == el2Ind){
            el2 = arr2[right];
        }
        right++;
    }

    if((n+m)%2 == 1){
        return (double)el1;
    }
    else{
        return (double)((el1 + el2) / 2);
    } 
}

//tc --> o(n+m)  sc --> 0(n+m)
double brute(vector<int> &arr1, int n, vector<int> &arr2, int m){
    vector<int> ans;
    int left = 0;
    int right = 0;
    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            ans.push_back(arr1[left]);
            left++;
        }
        else {
            ans.push_back(arr2[right]);
            right++;
        }
    }
    while(left < n){
        ans.push_back(arr1[left]);
        left++;
    }
    while(right < m){
        ans.push_back(arr2[right]);
        right++;
    }

    int index = (n+m) / 2;
    if((n+m)%2 != 0){
        return ans[index];
    }
    else{
        return (double) (((double)ans[index - 1] + (double)ans[index]) / 2.0);
    }
}

//tc --> o(min(logn,logm)) sc --> o(1)
double optimal(vector<int> &arr1, int n, vector<int> &arr2, int m){
    if(m < n) return optimal(arr2, m, arr1, n);
    int low = 0;
    int high = n;
    int onleft = (n + m + 1) / 2;
    int k = n + m;
    while(low <= high){
        int mid1 = (low + high) / 2;
        int mid2 = onleft - mid1;
        int l1 = INT_MIN; int l2 = INT_MIN;
        int r1 = INT_MAX; int r2 = INT_MAX;
        if(mid1 > 0) l1 = arr1[mid1 - 1];
        if(mid2 > 0) l2 = arr2[mid2 - 1];
        if(mid1 < n) r1 = arr1[mid1];
        if(mid2 < m) r2 = arr2[mid2];
        if(l1 <= r2 && l2 <= r1){
            if(k%2 == 1){
                return max(l1, l2);
            }
            else{
                return ((double)(max(l1, l2) + min(r1,r2)) / 2.0);
            }
        }
        else if(l1 > r2){
            high = mid1 - 1;
        }
        else{
            low = mid1 + 1;
        }
    }
    return 0;
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
    cout<<optimal(arr1, n, arr2, m);
    return 0;
}