#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define fo(s,n) for(int i = s; i<=n; ++i)
#define forev(s,n) for(int i = s; i>=n; --i)
#define heap priority_queue 
#define F first
#define S second
#define pub push_back
#define pob pop_back 
#define puf push_front 
#define pof pop_front
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define sortrev(x) sort(all(x), greater<int>)
#define revall(x) reverse(all(x))
#define PI 3.1415926535897932384626
#define mod 1e9+7

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vi nums(n);

        fo(0, n-1){
            cin >> nums[i];
        }

        heap<int> mx;

        forev(n-1, 0){
            mx.push(nums[i]);
        }

        while(!mx.empty()){
            cout << mx.pop() << endl;
        }
    }
    return 0;
}