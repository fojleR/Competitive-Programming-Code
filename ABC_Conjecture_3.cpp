#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

void reverse(vector< int > &v, int pos1, int pos2){
    if(pos1 > pos2)return;
    swap(v[pos1], v[pos2]);
    reverse(v, pos1 + 1, pos2 - 1);
}
vector< int > v = {3, 2, 4, 5, 1, 6};
void all_subsequence(vector< vector< int > > &allSubsequence, int pos, vector< int > &tmp, int &n){
    if(pos == n){
        allSubsequence.pb(tmp);
        return;
    }
    tmp.push_back(v[pos]);
    all_subsequence(allSubsequence, pos + 1, tmp, n);
    tmp.pop_back();
    all_subsequence(allSubsequence, pos + 1, tmp, n);
}

int k;
void all_subsequenceSum(vector< vector< int > > &allSubsequence, int pos, vector< int > &tmp, int &n, int &sum){
    if(pos == n){
        if(sum == k)allSubsequence.pb(tmp);
        return;
    }
    tmp.push_back(v[pos]);
    sum += v[pos];
    all_subsequenceSum(allSubsequence, pos + 1, tmp, n, sum);
    tmp.pop_back();
    sum -= v[pos];
    all_subsequenceSum(allSubsequence, pos + 1, tmp, n, sum);
}
bool subsequenceSum(vector< vector< int > > &allSubsequence, int pos, vector< int > &tmp, int &n, int &sum){
    if(pos == n){
        if(sum == k){
            allSubsequence.pb(tmp);
            return true;
        }
        return false;
    }
    tmp.push_back(v[pos]);
    sum += v[pos];
    if(subsequenceSum(allSubsequence, pos + 1, tmp, n, sum)){
        return true;
    }
    tmp.pop_back();
    sum -= v[pos];
    if(subsequenceSum(allSubsequence, pos + 1, tmp, n, sum)){
        return true;
    }
    return false;
}

int countSubsequenceSum(int pos,int &n, int &sum){
    if(pos == n){
        if(sum == k){
            return 1;
        }
        return 0;
    }
    sum += v[pos];
    int l = countSubsequenceSum(pos + 1, n, sum);
    sum -= v[pos];
    int r = countSubsequenceSum(pos + 1, n, sum);
    return l + r;
}

void merge(vector< int > &v, int l, int mid, int r){
    int i = l, j = mid + 1;
    int pos = l;
    vector< int > tm;
    while(i <= mid && j <= r){
        if(v[i] < v[j]){
            tm.push_back(v[i]);
            i++;
        }
        else{
            tm.push_back(v[j]);
            j++;
        }
    }
    while(i <= mid){
        tm.push_back(v[i]);
        i++;
    }
    while(j <= r){
        tm.push_back(v[j]);
        j++;
    }
    for(int i = 0; i < tm.size(); i++){
        v[l + i] = tm[i];
    }
}

void merge_sort(vector< int > &v, int l, int r){
    if(l >= r)return;
    int mid = (l + r) / 2;
    // cout << l << " " << mid << " " << r << endl;
    merge_sort(v, l, mid);
    merge_sort(v, mid + 1, r);
    merge(v, l, mid, r);
}

void quick_sort(vector< int > &v, int l, int r){
    if(l >= r)return;
    int pivot = v[l];
    int st = l + 1, en = r;
    while(1){
        while(st <= r && v[st] <= pivot)st++;
        while(en >= l && v[en] > pivot)en--;
        if(st > en){
            swap(v[l], v[en]);
            break;
        }
        else{
            swap(v[st], v[en]);
            st++; en--;
        }
    }
    quick_sort(v, l, en - 1);
    quick_sort(v, en + 1, r);
}

void solve(){
    int n = 6;
    k = 6;
    cin >> n;
    v.clear();
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector< vector< int > > allSubsequence;
    vector< int > tmp;
    int sum = 0;
    quick_sort(v, 0, n - 1);
    cout << v << endl;
    
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