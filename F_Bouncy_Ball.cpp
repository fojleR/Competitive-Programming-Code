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
    int n, m, i1, j1, i2, j2; 
    string d;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;
    int dx = 1, dy = 1;
    if(d[0] == 'U') dy = -1;
    if(d[1] == 'L') dx = -1;
    int cnt = 0, ans = 0;
    while(cnt < n * m * 4){
        // cout << i1 << " " << j1 << endl;
        if(i1 == i2 and j1 == j2){
            cout << ans << endl;
            return;
        }
        cnt++;
        bool bounce = false;
        if(i1 + dy < 1 || i1 + dy > n){
            dy *= -1;
            bounce = true;
        }
        if(j1 + dx < 1 || j1 + dx > m){
            bounce = true;
            dx *= -1;
        }
        if(bounce)ans++;
        i1 += dy;
        j1 += dx;
    }
    cout << -1 << endl;
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