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
    int a[n], b[n];
    vector< int > v;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
        v.push_back(a[i]);
    }

    ll ans = 0;
    sort(a, a + n);
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        ans += a[i] - a[0] + 1;
    }

    map<int, ll > mp;
    mp[a[0]] = ans;
    for(int i = 1; i < n; i++){
        ll dif = a[i] - a[i - 1];
        ans += dif * i;
        ans -= dif * (n - i);
        mp[a[i]] = ans;
    }

    for(int i = 0; i < n; i++){
        cout << mp[b[i]] << " ";
    }
    cout << endl;
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