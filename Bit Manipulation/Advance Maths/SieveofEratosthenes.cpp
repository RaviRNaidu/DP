#include<bits/stdc++.h>
using namespace std;

bool prime(int n){
    int counter=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0)
        {
            counter=counter+1;
            if((n/i)!=i){
                counter=counter+1;
            }
        }
    }
    if(counter==2)
    {
        return true;
    }
    else return false;
}

// TC -> O(N * sqrt(n))
vector<int> brute(int n){
    vector<int> ans;
    for(int i=2;i<n;i++){
        if(prime(i)){
            ans.push_back(i);
        }
    }
    return ans;
}


//OPTIMAL BUT NOT THE MOST OPTIMAL ONE
vector<int> optimal(int n){
    vector<int> ans;
    vector<int> box(n+1);
    box = {1};
    for(int i=2;i<n;i++){
        if(box[i] == 1){
            for(int j=2*i;j<=n;j+=i){   //2*i is used as the starting because we start to mark from the next multiple of that number!! 
                box[j] = 0;             // and we keep on adding the number i to the j value 
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(box[i] == 1){
            ans.push_back(i);
        }
    }
    return ans;
}


//TC -> N log(log N) + O(N) + O(N)      SC -> O(N) FOR BLACK BOX
vector<int> MostOptimall(int n){
    vector<int> ans;
    vector<int> box(n+1, 1);

    for(int i=2;i*i<=n;i++){                //THIS TC WILL BE N log(log N) cuz its called PRIME HARMNIC SERIES
        if(box[i] == 1){
            for(int j=i*i;j<=n;j+=i){
                box[j] = 0;
            }
        }
    }

    for(int i=2;i<=n;i++){              //tc -> o(n)
        if(box[i] == 1){
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> ans = MostOptimall(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}