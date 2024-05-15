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
    string s;
    cin >> s;
    char track[3];
    track[0] = s[0];
    int pre[n + 1] = {0};
    if(n >= 2){
        track[1] = s[1];
    }
    for(int i = 2; i < n; i++){
        track[2] = s[i];
            pre[i - 1] = pre[i - 2]; 
        //cout << track[0] << track[1] << track[2] << endl;
        if(track[0] == track[1] || track[1] == track[2] || track[2] == track[0]){
            pre[i - 1]++;
        }
        track[0] = track[1];
        track[1] = track[2];
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        int dif = r - l + 1;
        if(dif < 3 || n < 3){
            cout << "NO" << endl;
        }
        else{
            r -= 2;
            //cout << l << " " << r << endl;
            int d = pre[r] - pre[l - 1];
            if(d > 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
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