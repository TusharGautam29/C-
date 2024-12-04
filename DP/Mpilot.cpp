#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> ac, as;
vector<vector<int>> dp;

int f(int i, int x) {
    if (i == n) return 0; 
    if (dp[i][x] != -1) return dp[i][x]; 
    if (x == 0) return dp[i][x] = f(i + 1, x + 1) + as[i];
    if (x == n - i) return dp[i][x] = f(i + 1, x - 1) + ac[i];
    return dp[i][x] = min(f(i + 1, x + 1) + as[i], f(i + 1, x - 1) + ac[i]);
}
int main() {
    cin >> n;
    ac.resize(n);
    as.resize(n);
    dp.assign(n, vector<int>(n / 2 + 1, -1));
    for (int i = 0; i < n; ++i) cin >> ac[i] >> as[i];
    int result = f(0, 0);
    cout << result << endl;
    return 0;
}
