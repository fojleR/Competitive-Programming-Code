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
    ll a[n];
    bool ok = false;
    vector< int > pos, neg, zero, ans;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > 0){
            pos.push_back(a[i]);
            ok = true;
        }
        else if(a[i] < 0){
            neg.push_back(a[i]);
            ok = true;
        }
        else{
            zero.push_back(0);
            ans.push_back(0);
        }
    }

    if(!ok){
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    ll sum = 0;

    while(!pos.empty() and !neg.empty()){
        if(sum > 0){
            sum += neg.back();
            ans.push_back(neg.back());
            neg.pop_back();
        }
        else{
            sum += pos.back();
            ans.push_back(pos.back());
            pos.pop_back();
        }
    }

    while(!pos.empty()){
        ans.push_back(pos.back());
        pos.pop_back();
    }

    while(!neg.empty()){
        ans.push_back(neg.back());
        neg.pop_back();
    }

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