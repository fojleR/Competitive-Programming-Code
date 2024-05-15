#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

int mex(int x, int y, int z) {
    for (int i = 0; i < 3; i++) {
        if (x != i and y != i and z != i) return i;
    }
    return 3;
}


void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    vector< vector< int > > cnt_l(n + 1, vector< int > (3, 0));
    vector< vector< int > > cnt_r(n + 1, vector< int > (3, 0));
    for(int i = 0; i < n; i++){
        cnt_l[i + 1] = cnt_l[i];
        if(s[i] == 'M'){
            cnt_l[i + 1][a[i]]++;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        cnt_r[i] = cnt_r[i + 1];
        if(s[i] == 'X'){
            cnt_r[i][a[i]]++;
        }
    }
    ll ans = 0;
    for(int i = 1; i < n - 1; i++){
        if(s[i] != 'E')continue;
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                ans += (ll)cnt_l[i][j] * cnt_r[i + 1][k] * mex(j, a[i], k);
            }
        }
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