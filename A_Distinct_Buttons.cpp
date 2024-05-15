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
    int n;
    cin >> n;
    int up = 0, dw = 0, rt = 0, lf = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(x > 0) rt = 1;
        if(x < 0) lf = 1;
        if(y > 0) up = 1;
        if(y < 0) dw = 1;
    }
    if(!up || !dw || !rt || !lf){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
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