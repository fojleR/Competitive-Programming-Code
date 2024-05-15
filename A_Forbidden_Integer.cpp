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
    int n, k, x;
    cin >> n >> k >> x;
    vector< int > ans;
    if(x == 1 and k == 1){
        cout << "NO" << endl;
        return;
    }
    else if(x == 1 and k <= 2 and n % 2){
        cout << "NO" << endl;
        return;
    }
    else if(x == 1 and n % 2){
        ans.push_back(3);
        n -= 3;
        while(n){
            ans.push_back(2);
            n -= 2;
        }
    }
    else if(x == 1){
        while(n){
            ans.push_back(2);
            n -= 2;
        }
    }
    else{
        while(n){
            ans.push_back(1);
            n--;
        }
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(auto x: ans){
        cout << x << " ";
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