#include<bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m)
{
    int low = 1;
    int high = m/n;
    
    if(m==1) return 1;
    
    while(low<=high){
        int mid = low+(high-low)/2;
        
        if(pow(mid, n) == m){
            return mid;
        }else if(pow(mid, n) < m){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}  

int main(){
    int n = 2;
    int m = 9;
    cout << NthRoot(n, m) << endl;
    return 0;
}