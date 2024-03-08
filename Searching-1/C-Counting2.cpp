#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin >> n;
    cin >> q;

    vector<long long> h(n);
    for(int i = 0; i<n; i++){
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    while(q--){
        long long in;
        cin >> in;

        int low = 0;
        int high = n-1;

        int ans = -1;

        while(low<=high){
            int mid = low+(high-low)/2;

            if(h[mid]>=in){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        if(ans==-1){
            cout << 0 << endl;
        }else{
            cout << n-ans << endl;
        }
    }
    return 0;
}