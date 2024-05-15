#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

int question(int x, int y){
    cout << "? " << x << " " << y << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    int ans;
    ans = question(1, 1);
    ans++;
    if(ans <= n and ans <= m){
        int ans2 = question(1, ans);
        int ans3 = question(ans, 1);

        if(ans3 == ans2){
            cout << "! " << ans << " " << ans << endl;
        }
        else if(ans2 < ans3){
            cout << "! " << ans2 + 1 << " " << ans << endl;
        }
        else{
            cout << "! " << ans << " " << ans3 + 1 << endl;
        }
    }
    else if(ans <= n){
        int ans2 = question(ans, 1);
        cout << "! " << ans << " " << ans2 + 1 << endl;
    }
    else{
        int ans2 = question(1, ans);
        cout << "! " << ans2 + 1 << " " << ans << endl;
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