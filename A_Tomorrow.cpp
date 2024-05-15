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
    int M, D;
    cin >> M >> D;
    int y, m, d;
    cin >> y >> m >> d;
    d++;
    if(d > D){
        d %= D;
        m++;
        if(D == 1){
            d = 1;
        }
    }
    if(m > M){
        y++;
        m %= M;
        if(M == 1){
            m = 1;
        }
    }
    cout << y << " " << m << " " << d << endl;
}


int main(){
    fast
    int t = 1;
    //cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}