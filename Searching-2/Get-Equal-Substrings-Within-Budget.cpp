#include<bits/stdc++.h>
using namespace std;

int equalSubstring(string s, string t, int maxCost) {
    int n = s.length();

    //Couldn't come up with binary search approach as sliding window was more intuitive for me

    int low = 0;

    int maxi = -1e9;

    int cost = 0;

    for(int high=0; high<n; high++){
        cost += abs(s[high]-t[high]);

        while(low<=high && cost > maxCost){
            cost -= abs(s[low]-t[low]);
            low++;
        }

        maxi = max(maxi, high-low+1);
    }
    return maxi;
}

int main(){
    string s = "abcd";
    string t = "bcdf";

    int maxCost = 3;

    cout << equalSubstring(s, t, maxCost) << endl;

    return 0;
}