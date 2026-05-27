#include<bits/stdc++.h>
using namespace std;

int removeset(int arr[], int n){
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]); //adding the elements which are in the arr including the duplicate to the set
    }                      //set will automatically remove the duplicate elements
    int k = st.size();//we are taking the size of our set to use it for iteration
    int j = 0; //from here we are adding the elements back to the array starting from index 0
    //this is used to iterate over the set and auto will decide the type of the elements which are present in the set
    for(auto it:st){
        arr[j] = it;
        j++;
    }
    return k;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k = removeset(arr, n);
    for(int y=0;y<k;y++){
        cout<<arr[y]<<" ";
    }
}