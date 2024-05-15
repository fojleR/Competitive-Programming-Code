#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;
vector< int > v;
int n;
bool check(int x){
    int dis = 2 * x;
    int st = v[0];
    for(int i = 0; i < 3; i++){
        int ind = upper_bound(v.begin(), v.end(), st + dis) - v.begin();
        if(ind >= n)return true;
        st = v[ind];
    }
    return false;
}
void solve(){
    v.clear();
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x); 
    }
    sort(v.begin(), v.end());
    int lo = 0, hi = v[n - 1] - v[0];
    int ans = hi;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << ans << endl;
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}