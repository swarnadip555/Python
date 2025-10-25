#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack problem using Dynamic Programming
int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    // Create a DP table of size (n+1) x (W+1)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                // Option 1: Include the item
                // Option 2: Exclude the item
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                // Cannot include the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // dp[n][W] contains the maximum value that can be put in knapsack
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> wt(n), val(n);

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;

    int maxVal = knapsack(W, wt, val, n);
    cout << "\nMaximum value in Knapsack = " << maxVal << endl;

    return 0;
}
