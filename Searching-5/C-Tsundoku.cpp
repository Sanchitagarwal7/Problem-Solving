#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &prefixA, vector<int> &prefixB, int &book, int &n, int &m, int &maxTime){
    //for every book(s) in A, calculate rem time and search for that time if it exists in B
    //case1. it exists then add in tot Time
    //case2. it dosent so addd previous elmenet as it will be smaller
}

int main(){
    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;

    vector<int> a(n), b(m);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int j = 0; j<m; j++){
        cin >> b[j];
    }

    //starting of both prefixSum is 0 as there might be case where we only read from one stack only
    vector<int> prefixA(n+1, 0), prefixB(m+1, 0);
    prefixA[1] = a[0];
    for(int i = 2; i<n+1; i++){
        prefixA[i]+=prefixA[i-1]+a[i-1];
    }
    // cout << "Prefix A" << endl;
    // for(int i = 0; i<n+1; i++){
    //     cout << prefixA[i] << endl;
    // }

    prefixB[1] = b[0];
    for(int i = 2; i<m+1; i++){
        prefixB[i]+=prefixB[i-1]+b[i-1];
    }

    // cout << "Prefix B" << endl;
    // for(int i = 0; i<m+1; i++){
    //     cout << prefixB[i] << endl;
    // }

    int low = 0;
    int high = n+m;

    int res=0;

    while(low<=high)
    {
        int mid = low+(high-low)/2;

        if(isPossible(prefixA, prefixB, mid, n, m, k)){
            res = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }

    cout << res << endl;

    return 0;
}