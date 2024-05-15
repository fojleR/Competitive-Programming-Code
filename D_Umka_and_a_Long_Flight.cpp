#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

ll fib[50];

void cal(){
    fib[0] = fib[1] = 1;
    for(int i = 2; i <= 46; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    ll a = fib[n];
    ll b = fib[n + 1];
    ll need = fib[n];

    while(1){
        need = fib[n];
        n--;
        if(x + need <= a){
            a -= need;
        }
        else if(y + need <= b){
            b -= need;
        }
        else if(x > need){
            a -= need;
            x -= need;
        }
        else if(y > need){
            b -= need;
            y -= need;
        }
        else if(a == 1 and b == 1){
            break;
        }
        else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}


int main(){
    fast
    int t = 1;
    cal();
    cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}