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
    string s;
    cin >> s;
    int a[n];
    for(int i = 0; i < n; i++){
        if(s[i] == 'R') a[i] = 1;
        else if(s[i] == 'L') a[i] = -1;
        else if(s[i] == 'U') a[i] = 2 * n + 1;
        else a[i] = -(2 * n + 1);
    }
    map< ll, int > mp;
    ll sum = 0;
    mp[0] = 0;

    vector< int > ans;
    int l = -1, r = -1;
    int dis = n + 2;
    for(int i = 0; i < n; i++){
        sum += a[i];
        //cout << sum << " ";
        if(mp[sum] || sum == 0){
            int ddis = (i + 1) - mp[sum];
            // cout << sum << " " << mp[sum] << " " << i + 1 << endl;
            // cout << ddis << endl;
            if(ddis < dis){
                l = mp[sum] + 1, r = i + 1;
                dis = ddis;
            }
        }
        mp[sum] = i + 1;
    }
    //cout << endl;
    if(l == -1){
        cout << -1 << endl;
    }
    else{
        cout << l << " " << r << endl;
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