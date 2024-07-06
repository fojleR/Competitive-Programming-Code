#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int logN = 20;
const int mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

vector< vector< int > > v(mx, vector< int >(logN, 0));



void solve(){
    int n;
    cin >> n;
    vector< int > v(n);
    vector< int > track;
    for(auto &x: v){
        cin >> x;
    }
    for(int i = 0; i < n; i++){
        if(v[i] == -1)continue;
        track.push_back(i);
        if(i + 1 < n && v[i + 1] != -1){
            if((v[i] / 2 == v[i + 1]) || (v[i + 1] / 2 == v[i]))continue;
            else{
                cout << -1 << endl;
                return;
            }
        }
    }
    for(int i = 1; i < track.size(); i++){
        int left = track[i - 1];
        int right = track[i];
        int leftVal = v[left];
        int rightVal = v[right];
        left++; right--;
        while(left <= right){
            if(rightVal == 1 and leftVal == 1)break;
            if(leftVal > rightVal){
                leftVal /= 2;
                v[left] = leftVal;
                left++;
            }
            else{
                rightVal /= 2;
                v[right] = rightVal;
                right--;
            }
        }
        if((right > left) and (right - left + 1) % 2 == 0){
            cout << -1 << endl;
            return;
        }
        else{
            bool flag = false;
            while(left <= right){
                if(!flag){
                    v[left] = 3;
                    flag = 1;
                }
                else{
                    v[left] = 1; 
                    flag = 0;
                }
                left++;
            }
        }
        
    }
    if(track.size() != 0){
        int left = track[0];
        int flag = 0;
        for(int i = left; i > 0; i--){
            if(!flag){
                v[i - 1] = v[i] * 2;
                flag = 1;
            } 
            else{
                v[i - 1] = v[i] / 2;
                flag = 0;
            }
        }
        int right = track[track.size() - 1];
        flag = 0;
        for(int i = right; i < n - 1; i++){
            if(!flag){
                v[i + 1] = v[i] * 2;
                flag = 1;
            }
            else{
                v[i + 1] = v[i] / 2;
                flag = 0;
            }
        }
    }
    else{
        for(int i = 0; i < n; i++){
            if(i % 2){
                v[i] = 1;
            }
            else{
                v[i] = 2;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(i + 1 < n){
            if((v[i] / 2 == v[i + 1]) || (v[i + 1] / 2 == v[i]))continue;
            else{
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << v << endl;
    
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while(t--){
        // cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}