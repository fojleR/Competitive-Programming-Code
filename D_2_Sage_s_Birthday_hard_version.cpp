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
    int a[n];
    deque< int > v, ans(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int tm = n / 2;
    int j = tm;
    int pos = 0;
    for(int i = 0; i < tm; i++){
        ans[pos++] = v[j++];
        ans[pos++] = v[i];
    }
    if(pos < n){
        ans[pos] = v[n - 1];
    }
    int res = 0;
    for(int i = 1; i < n - 1; i++){
        if(ans[i] < ans[i - 1] and ans[i] < ans[i + 1]){
            res++;
        }
    }
    cout << res << endl;
    for(int x: ans){
        cout << x << " ";
    }

    
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