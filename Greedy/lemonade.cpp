#include<bits/stdc++.h>
using namespace std;

//TC -> O(N)    SC -> O(1)
bool brute(vector<int> &arr, int n){
    int five = 0;
    int ten = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 5){
            five++;
        }
        else if(arr[i] == 10){
            if(five > 0){
                ten++;
                five--;
            }
            else{
                return false;
            }
        }
        else{
            if(five > 0 && ten > 0){
                five--;
                ten--;
            }
            else if(five >= 3){
                five = five - 3;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = brute(arr,n);
    cout<<ans<<endl;
    return 0;
}