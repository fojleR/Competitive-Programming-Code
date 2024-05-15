#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

int n, k , e;
int dp[1001][1001];


void solve(){
    cin >> n >> k >> e;
    int left = e, right = (n - k - e);
    int check[n + 1] = {0};
    check[k] = 1;
    for(int i = 0; i < left; i++){
        int xx = left - i;
        if(check[xx] == 0 and check[i] == 0 and xx != i){
            //cout << i << endl;
            left = 0;
            check[xx] = 1, check[i] = 1;
            break;
        }
    }
    //cout << left << " " << right << endl;
    for(int i = 0; i < right; i++){
        int xx = right - i;
        if(check[xx] == 0 and check[i] == 0 and xx != i){
            right = 0;
            check[xx] = 1, check[i] = 1;
            break;
        }
    }
    for(int i = 1; i <= n; i++){
        if(check[i] == 0){
            if(left >= right){
                if(i <= left){
                    check[i] = 1;
                    left -= i;
                }
            }
            else if(i <= right){
                check[i] = 1;
                right -= i;
            }
        }
    }
    cout << left + right << endl;
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