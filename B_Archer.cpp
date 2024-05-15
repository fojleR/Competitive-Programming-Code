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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int cnt1 = 1, cnt2 = 1;
    while(a < b){
        a += a;
        cnt1++;
    }
    while(c < d){
        c += c;
        cnt2++;
    }
    if(cnt1 <= cnt2){
        cnt2 = cnt1 - 1;
        cout << (float(cnt1)/ (cnt1 + cnt2)) << endl;
    }
    cout << cnt1 << " " << cnt2 << endl;
    
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