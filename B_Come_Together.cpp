#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

void solve(){
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    int ans = 0;
    if((ax < bx and ax < cx) || (ax > bx and ax > cx)){
        ans += min(abs(ax - bx), abs(ax - cx));
    }
    if((ay < by and ay < cy) || (ay > by and ay > cy)){
        ans += min(abs(ay - by), abs(ay - cy));
    }
    cout << ans + 1 << endl;
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