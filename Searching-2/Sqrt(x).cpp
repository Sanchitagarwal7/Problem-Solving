#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    int low = 1;
    int high = x/2;

    if(x==1) return 1;

    int res=0;
    while(low<=high){
        int mid = low+(high-low)/2;

        if((long long)mid*mid <= x){
            res = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return res;
}

int main(){
    int x = 8;
    cout << mySqrt(x) << endl;
    return 0;
}