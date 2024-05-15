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
    int a[3][n + 1];
    a[1][1] = 2 * n;
    a[2][n] = 2 * n - 1;
    int small = 1, big =2 *n - 2;
    for(int i = 1; i < n; i++){
        if(i % 2){
            a[2][i] = small++;  
            a[1][i + 1] = small++;
        }
        else{
            a[1][i + 1] = big--;
            a[2][i] = big--;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << a[1][i] << " ";
    }
    cout <<endl;
    for(int i = 1; i <= n; i++){
        cout << a[2][i] << " ";
    }
    cout <<endl;
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