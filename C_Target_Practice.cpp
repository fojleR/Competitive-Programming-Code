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
    char a[11][11];
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            cin >> a[i][j];
            //cout << a[i][j];
        }
    }

    int ans = 0;

    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            if(a[i][j] == 'X'){
                int x = i, y = j;
                if(x > 5){
                    //x = x % 10;
                    x = 10 - x + 1;
                }
                if(y > 5){
                    //y = y % 10;
                    y = 10 - y + 1;
                }
                //cout << min(x, y) << endl;
                ans += min(x, y);
            }
        }
    }
    cout << ans << endl;
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