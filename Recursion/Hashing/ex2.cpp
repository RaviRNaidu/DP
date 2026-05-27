#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    int maxFrequency=0, minimumFrequency=n;
    int maxelement=0, minimumelement=0;

    for(auto it:mpp){
        int count=it.second;
        int element=it.first;

        if(count>maxFrequency){
            maxFrequency = count;
            maxelement = element;
        }

        if(count<minimumFrequency){
            minimumFrequency=count;
            minimumelement=element;
        }
    }

    cout<<"the highest frequency of the element is : "<<maxelement<<endl;
    cout<<"the minimum frequency of the element is : "<<minimumelement<<endl;
    return 0;
}