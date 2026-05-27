#include <bits/stdc++.h>
using namespace std;

//tc --> o(k*n) + o(n)   sc -->o(1)
long double brute(vector<int> &arr, int n, int k){
    vector<int> HowMany(n-1,0);
    for(int gasStation = 1; gasStation <= k; gasStation++){
        long double maxi = -1;
        int index = -1;
        for(int i=0;i<n-1;i++){
            long double diff = arr[i+1] - arr[i];
            long double Maxsection = diff / (long double) (HowMany[i] + 1);
            if(Maxsection > maxi){
                maxi = Maxsection;
                index = i;
            }
        }
        HowMany[index]++;
    }

    long double finalAns = -1;
    for(int i=0;i<n-1;i++){
        long double diff = arr[i+1] - arr[i];
        long double Maxsection = diff / (long double) (HowMany[i] + 1);
        finalAns = max(finalAns, Maxsection);
    } 
    return finalAns;
}

//pq takes log n to push the elements
//tc --> o(n log n)+ o(gasStation  * log n)   sc -->o(n-1)
long double better(vector<int> &arr, int n, int k){
    vector<int> HowMany(n-1,0);
    priority_queue<pair<long double, int>> pq;
    for(int i=0;i<n-1;i++){
        long double diff = arr[i+1] - arr[i];
        pq.push({diff,i});
    }

    for(int gasStation=1;gasStation<=k;gasStation++){
        auto tp = pq.top(); pq.pop();
        int sectionIndex = tp.second;
        HowMany[sectionIndex]++;
        long double initialDiff = arr[sectionIndex+1] - arr[sectionIndex];
        long double updDiff = initialDiff /(long double)(HowMany[sectionIndex] + 1);
        pq.push({updDiff,sectionIndex});
    }

    return pq.top().first;
}

int count(vector<int> &arr, int dist){
    int cnt = 0;
    for(int i=0;i<arr.size()-1;i++){
        int sectiondif = ((arr[i+1] - arr[i]) / dist);
        if((arr[i+1] - arr[i]) == sectiondif * dist){
            sectiondif--;
        }
        cnt += sectiondif;
    }
    return cnt;
}

//tc --> o(n + log base2 range * n)  sc --> o(1)
long double optimal(vector<int> &arr, int n, int k){
    long double maxi = INT_MIN;
    for(int i=0;i<n-1;i++){
        long double diff = arr[i+1] - arr[i];
        maxi = max(maxi, diff);
    }

    long double low = 0;
    long double high = maxi;
    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = (low + high) / (2.0);
        int cnt = count(arr, mid);
        if(cnt > k){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return high;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k; 
    cin>>k;
    cout<<optimal(arr, n, k);
    return 0;
}