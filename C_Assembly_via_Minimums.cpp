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
    int tot = (n * (n - 1))/2;
    int a[tot];
    for(int i = 0; i < tot; i++){
        cin >> a[i];
    }

    sort(a, a + tot);
    int cur = n - 1;
    for(int i = 0; i < tot; ){
        cout << a[i] << " ";
        i += cur;
        cur--;
        if(cur == 0)break;
    }
    cout << int(1e9) << endl;
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