#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;          cin >> s1 >> s2;

    int a = abs(s1[0] - s1[1]);
    int b = abs(s2[0] - s2[1]);

    if( a == b ) cout << "Yes" << endl;
    else cout << "No" << endl;
}