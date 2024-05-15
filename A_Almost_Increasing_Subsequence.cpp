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
    int n, q;
    cin >> n >> q;
    int a[n + 1], pre[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 3; i <= n; i++){
        if(a[i] <= a[i - 1] and a[i - 1] <= a[i - 2]){
            pre[i] = pre[i - 1] + 1;
        }
        else{
            pre[i] = pre[i - 1];
        }
    }

    for(int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if(len < 3){
            cout << len << endl;
            continue;
        }
        int ans = pre[r] - pre[l - 1];
        int x = l + 1;
        for(int i = l; i <= l + 1; i++){
            if(i - 2 > 0 and a[i - 2] >= a[i - 1] and a[i - 1] >= a[i]){
                ans--;
            }
        }
        ans = len - ans;
        cout << ans << endl;
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