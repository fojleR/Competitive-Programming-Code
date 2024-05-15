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
    double px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    double Bo, Bp, Ao, Ap;
    double tm1 = sqrt((0 - ax) * (0 - ax) + (0 - ay) * (0 - ay));
    double tm2 = sqrt((px - ax) * (px - ax) + (py - ay) * (py - ay));
    Ao = tm1; Ap = tm2;
    tm1 = max(tm1, tm2);
    double ans = tm1;
    //cout << ans << endl;
    tm1 = sqrt((0 - bx) * (0 - bx) + (0 - by) * (0 - by));
    tm2 = sqrt((px - bx) * (px - bx) + (py - by) * (py - by));
    tm1 = max(tm1, tm2);
    Bo = tm1; Bp = tm2;
    ans = min(ans, tm1);
    //cout << ans << endl;

    double mx = (ax + bx) / 2;
    double my = (ay + by) / 2;
    if((Ao < ans and Bp < ans) || (Bo < ans and Ap < ans)){
        double tm = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
        tm = tm / 2;
        ans = min(ans, tm);
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