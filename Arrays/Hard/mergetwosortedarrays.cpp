#include<bits/stdc++.h>
using namespace std;

//tc o(n+m)+o(n+m)    sc  o(n+m)
void brute(vector<int> &arr1, int n, vector<int> &arr2, int m){
    vector<int> ans(n+m);
    int left = 0;
    int right = 0;
    int index = 0;
    while(left<n && right<m){
        if(arr1[left] <= arr2[right]){
            ans[index] = arr1[left];
            left++, index++;
        }
        else{
            ans[index] = arr2[right];
            right++;
            index++;
        }
    }
    while(right < m){
        ans[index] = arr2[right];
        right++;
        index++;
    }

    while(left < n){
        ans[index] = arr1[left];
        left++;
        index++;
    }
    

    for(int i=0;i<ans.size();i++){
        if(i < n){
           arr1[i] = ans[i];
        }
        else {
            arr2[i - n] = ans[i];
        }
    }
}


//striverr
//tc --> o(min(arr1,arr2)) + o(n log n) + o(m log m)     sc --> o(1) or nill
void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare 2 pointers:
    int left = n - 1;
    int right = 0;

    //Swap the elements until arr1[left] is
    // smaller than arr2[right]:
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

//me
void optimal1(vector<int> &arr1, int n, vector<int> &arr2, int m){
    int left = n-1;
    int right = 0;
    while(arr1[left] > arr2[right]){
        swap(arr1[left],arr2[right]);
        left --;
        right ++;
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}



//tc --> o log base 2(n+m) * o (n+m)     sc --> o(1)
void swaping(vector<int> &arr1, vector<int> &arr2, int left, int right){
    if(arr1[left] > arr2[right]){
        swap(arr1[left],arr2[right]);
    }
}
void optimall2(vector<int> &arr1, int n, vector<int> &arr2, int m){
    int len = n + m;
    int gap = (len / 2) + (len % 2);
    while(gap > 0){
        int left = 0;
        int right = left + gap;
        while(right < len){
            if(left < n && right >= n){
                swaping(arr1,arr2,left, right - n);
            }
            else if(left >= n){
                swaping(arr2,arr2,left - n,right - n);
            }
            else{
                swaping(arr1,arr1,left,right);
            }
            left++, right++;
        }
        if(gap == 1) break;
        gap = (gap/2) + (gap%2);
    } 
}

int main(){
    int n,m;
    cin>>n;
    vector<int> arr1(n);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cin>>m;
    vector<int> arr2(m);
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    optimall2(arr1, n, arr2, m);
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }
    return 0;
}