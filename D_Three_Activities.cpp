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
    vector< pair< int, int > > v1, v2, v3;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v1.push_back({x, i});
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v2.push_back({x, i});
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v3.push_back({x, i});
    }
    sort(v1.begin(), v1.end());
    reverse(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    reverse(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    reverse(v3.begin(), v3.end());

    ll ans = 0;
    for(int i = 0; i < min(15, n); i++){
        int vi = v1[i].first, ii = v1[i].second;
        for(int j = 0; j < min(15, n); j++){
            int vj = v2[j].first, jj = v2[j].second;
            if(jj == ii)continue;
            for(int k = 0; k < min(15, n); k++){
                int vk = v3[k].first, kk = v3[k].second;
                if(kk == ii || kk == jj)continue;
                ll sm = vi + vj + vk;
                ans = max(ans, sm);
            }
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