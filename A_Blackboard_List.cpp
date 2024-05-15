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
    int a[n];
    //map< int, int > mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    //cout << n << endl;
    sort(a, a + n);

    if(a[0] < 0){
        cout << a[0] << endl;
    }
    else{
        cout << a[n - 1] << endl;
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