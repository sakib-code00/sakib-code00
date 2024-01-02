#include <bits/stdc++.h>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to solve the 0-1 Knapsack Problem
int knapsack(vector<Item>& items, int capacity) {
    int n = items.size();

    // Initialize a 2D array to store the results of subproblems
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the dp array using bottom-up dynamic programming
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            // If the current item's weight is less than or equal to the current capacity
            if (items[i - 1].weight <= w) {
                // Consider including the current item in the knapsack
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            } else {
                // If including the current item exceeds the capacity, just skip it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result is stored in the bottom-right cell of the matrix
    return dp[n][capacity];
}

int main() {
    // Example items: weight, value
    vector<Item> items = {{2, 12}, {1, 10}, {3, 20}, {2, 15}};

    int capacity = 5;

    // Find the maximum value in the knapsack
    int maxValue = knapsack(items, capacity);

    // Print the result
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}

