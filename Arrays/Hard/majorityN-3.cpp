#include <bits/stdc++.h>
using namespace std;

//tc is o(2n) NOT o(n*n)
vector<int> optimall(vector<int> &arr,int n){
    vector<int> ans;
    int floor = n/3;
    int cnt1 = 0;
    int cnt2 = 0;
    int el1, el2;
    for(int i=0;i<n;i++){
        if(cnt1 == 0 && arr[i] != el2){
            cnt1 += 1;
            el1 = arr[i];
        }
        else if(cnt2 == 0 && arr[i] != el1){
            cnt2 += 1;
            el2 = arr[i];
        }
        else if(arr[i] == el1){
            cnt1 ++;
        }
        else if(arr[i] == el2){
            cnt2 ++;
        }
        else {
            cnt1 --;
            cnt2 --;
        }
    }

    int counterr = 0;
    int counter2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == el1){
            counterr += 1;
        }
        else if(arr[i] == el2){
            counter2 += 1;
        }
    }
    if(counterr > floor){
        ans.push_back(el1);
    }
    if(counter2 > floor){
        ans.push_back(el2);
    }
    return ans;
}

//tc o(n) sc(n)
vector<int> better2(vector<int> &arr,int n){
    map <int,int> mpp;
    vector<int> ans;
    int mini = (n/3)+1;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]] == mini){
            ans.push_back(arr[i]);
        }
        if(ans.size() == 2){  //if required add it, if not don't
            break;
        }
    }
    return ans;
}

//tc o(n * log n ) sc(n)
vector<int> better(vector<int> &arr,int n){
    map <int,int> mpp;
    vector<int> ans;
    int floor = n/3;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto it:mpp){
        if(it.second > floor){
            ans.push_back(it.first);
        }
    }
    return ans;
}

//tc o(n*n) sc o(1/2)
vector<int> brute(vector<int> &arr,int n){
    vector<int> ans;
    int floor = n/3;
    for(int i=0;i<n;i++){
        if(ans.size() == 0 || ans[0] != arr[i]){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(arr[j] == arr[i]){
                    cnt += 1;
                }
            }
            if(cnt > floor){
                ans.push_back(arr[i]);
            }
        }
        if(ans.size() == 2){
            break;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans = optimall(arr, n);
    for(int j=0;j<ans.size();j++){
        cout<<ans[j]<<" ";
    }
    return 0;
}