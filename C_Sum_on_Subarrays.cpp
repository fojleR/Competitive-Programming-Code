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
    int ans[n + 1];
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
        if(sum <= k){
            ans[i] = 2;
        }
        else if(sum > k and sum - i < k){
            int need = k - sum + i;
            //cout << need << endl;
            need = i - 1 - need;
            ans[i] = (need * 2 + 1) * -1;
        }
        else{
            ans[i] = -1000;
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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