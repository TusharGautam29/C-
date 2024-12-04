#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long int
using namespace std;

ll n, m;
char mat[105][105];
ll dp[105][105][105];

ll f(ll i, ll j, ll x, ll y) {
    if (i >n || j > m || x > n || y > m || mat[i][j] == '#' || mat[x][y] == '#') return 0;
    if (i == n  && j == m ) return mat[i][j] == '*';
    if (dp[i][j][x] != -1) return dp[i][j][x];
    
    ll result = LLONG_MIN;
    result = max(result, f(i + 1, j, x + 1, y));
    result = max(result, f(i, j + 1, x + 1, y));
    result = max(result, f(i, j + 1, x, y + 1));
    result = max(result, f(i + 1, j, x, y + 1));
    
    result += (mat[i][j] == '*');
    result += (mat[x][y] == '*');
    if (i == x && j == y&&mat[i][j] == '*') result--;
    
    return dp[i][j][x] = result;
}

int main() {
    cin >> m>> n;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            cin >> mat[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    ll result = f(1,1,1,1);
    cout << result << endl;
    return 0;
}
