#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

int n, m;
int a[201], b[201];

//int dp[201];

// int Boboniu(int pos){
//     if(pos > n)return 0;
//     int mn = INT_MAX;
//     for(int i = 1; i <= m; i++){
//         mn = min(mn, (b[i] & a[pos]) | Boboniu(pos + 1));
//     }
//     return dp[pos] =  
// }

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    int lst = 1024;
    for(int i = 0; i <= lst; i++){
        bool ok = true;
        for(int j = 1; j <= n; j++){
            bool okk = false;
            for(int k = 1; k <= m; k++){
                if(((a[j] & b[k]) | i) == i){
                    //cout << a[j] << " " << b[k] << endl;
                    okk = true;
                    break;
                }
            }
            if(okk == false){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << i << endl;
            return;
        }
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