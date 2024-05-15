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
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            //cout << a[i][j];
        }
        //cout << endl;
    }
    string name = "vika";

    int cnt = 0;
    int pos = 0;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(a[i][j] == name[pos]){
                cnt++;
                pos++;
                break;
            }
            //cout << a[i][j] << " ";
        }
        //cout << endl;
    }

    //cout << cnt << endl;
    if(cnt == 4){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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