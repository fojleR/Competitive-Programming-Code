#include <bits/stdc++.h>
using namespace std;

bool go(int r, int a, int b, int c)
{
    int A = a;
    int B = b;
    int C = -c - a * r * r;

    cout << A << ' ' << B << ' ' << C << "\n";

    cout << B * B - 4 * A * C << "\n";

    if (B * B - 4 * A * C >= 0)
    {
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int r = 1;
        while (!go(r, a, b, c))
        {
            ++r;
        }
        cout << r << endl;
    }
}