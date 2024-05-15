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
    int ax, ay;
    cin >> ax >> ay;
    char A[ax + 1][ay + 1];
    for(int i = 1; i <= ax; i++){
        for(int j = 1; j <= ay; j++){
            cin >> A[i][j];
        }
    }
    int bx, by;
    cin >> bx >> by;
    char B[bx + 1][by + 1];
    for(int i = 1; i <= bx; i++){
        for(int j = 1; j <= by; j++){
            cin >> B[i][j];
        }
    }
    int xx, xy;
    cin >> xx >> xy;
    //cout << xx << " " << xy << endl;
    char X[xx + 1][xy + 1];
    for(int i = 1; i <= xx; i++){
        for(int j = 1; j <= xy; j++){
            cin >> X[i][j];
        }
    }
    // for(int i = 1; i <= ax; i++){
    //     for(int j = 1; j <= ay; j++){
    //         cout << A[i][j];
    //     }
    //     cout << endl;
    // }
    // for(int i = 1; i <= xx; i++){
    //     for(int j = 1; j <= xy; j++){
    //         cout << X[i][j];
    //     }
    //     cout <<endl;
    // }
    char ans[xx + 1][xy + 1];
    for(int i = 0; i <= xx; i++){
        for(int j = 0; j <= xy; j++){
            ans[i][j] = '.';
        }
    }
    for(int i = 1; i <= xx; i++){
        for(int j = 1; j <= xy; j++){
            char nw[xx + 1][xy + 1];
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