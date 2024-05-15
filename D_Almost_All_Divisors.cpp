#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

int lcm(int a, int b){
    return (a * b)/__gcd(a, b);
}

void solve(){
    int a, b;
    a = 6, b = 4;
    int l, r;
    l = 6, r = 12;
    int ans = 0;
    for(int i = l; i <= r; i++){
        if(((i % a) % b) != ((i % b) % a))ans++;
    }
    cout << ans << endl;
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