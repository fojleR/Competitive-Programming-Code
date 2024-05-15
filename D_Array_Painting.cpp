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
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt[n] = {0};
    for(int i = 0; i < n; i++){
        if(i > 0 and a[i - 1] != 0){
            a[i - 1]--;
        }
        else if(i + 1 < n and a[i + 1] != 0 and a[i] == 0){
            a[i + 1]--;
        }
        else{
            ans++;
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