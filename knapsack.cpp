# QUESTION NUMBER 9: write a program to solve the following 0/1 knapsack using dynamic programming approach profits p=(15,25,13,23). 
# weight W=(2,6,12,9) , knapsack C=20, and the number of items = 4.
#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack using Dynamic Programming
int knapsack(int capacity, vector<int>& weight, vector<int>& profit, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weight[i - 1] <= w)  // If item fits in knapsack
                dp[i][w] = max(profit[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];  // Exclude the item
        }
    }

    return dp[n][capacity];  // Max profit at dp[n][capacity]
}

int main() {
    vector<int> profit = {15, 25, 13, 23};
    vector<int> weight = {2, 6, 12, 9};
    int capacity = 20, n = 4;

    cout << "Maximum Profit: " << knapsack(capacity, weight, profit, n) << endl;
    return 0;
}
