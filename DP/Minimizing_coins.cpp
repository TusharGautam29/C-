#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
public:
    vector<int> dp;

    int f(vector<int>& coins, int amount) {
        if (amount == 0) return 0;  // Base case: no coins are needed to make sum 0
        if (amount < 0) return INT_MAX;  // Impossible case
        if (dp[amount] != -1) return dp[amount];  // Memoization: return cached result

        int x = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int res = f(coins, amount - coins[i]);  // Recursive call for amount - coins[i]
            if (res != INT_MAX) {  // Only consider valid results
                x = min(x, res + 1);  // Add 1 to the number of coins
            }
        }
        return dp[amount] = x;  // Memoize the result and return
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.clear();
        dp.resize(amount + 1, -1);  // Resize dp array based on the amount
        int result = f(coins, amount);
        return (result == INT_MAX) ? -1 : result;  // Return -1 if no valid solution
    }
};

int main() {
    int n, x;
    cin >> n >> x;  // Input the number of coins and the target amount
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];  // Input each coin's value
    }

    Solution sol;
    cout << sol.coinChange(coins, x) << endl;  // Output the minimum number of coins, or -1 if impossible
    return 0;
}
