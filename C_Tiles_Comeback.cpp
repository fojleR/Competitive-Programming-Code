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
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n - 1;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == a[0])cnt++;
        if(cnt == k){
            l = i;
            break;
        }
    }
    if(cnt < k){
        cout << "NO" << endl;
        return;
    }

    cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == a[n - 1]) cnt++;
        if(cnt == k){
            r = i;
            break;
        }
    }

    if(a[0] == a[n - 1]){
        cout << "YES" << endl;
        return;
    }
    if(l < r and cnt == k){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;

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