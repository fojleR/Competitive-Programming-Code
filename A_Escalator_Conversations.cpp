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
    int n, m, k, H;
    cin >> n >> m >> k >> H;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    set< int > st;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){ //vlad
            for(int l = 1; l <= m; l++){
                if(j == l)continue;
                ll dif1 = (j - l) * k;
                ll dif2 = H - a[i];
                if(dif1 == dif2){
                    st.insert(i);
                }
            }
        }
    }

    cout << st.size() << endl;
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