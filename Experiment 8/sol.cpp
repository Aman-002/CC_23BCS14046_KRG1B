#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // dp[i] will store the maximum sum for the subarray arr[0...i-1]
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            int current_max = 0;
            // Look back up to k elements to form the last partition
            for (int j = 1; j <= k && i - j >= 0; ++j) {
                // arr[i - j] is the current element being added to the partition
                current_max = max(current_max, arr[i - j]);
                
                // Calculate the max sum if the last partition has length j
                dp[i] = max(dp[i], dp[i - j] + current_max * j);
            }
        }
        
        // The answer for the entire array is stored at dp[n]
        return dp[n];
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> arr1 = {1, 15, 7, 9, 2, 5, 10};
    int k1 = 3;
    cout << "Example 1 Output: " << sol.maxSumAfterPartitioning(arr1, k1) << endl; 
    // Expected: 84

    vector<int> arr2 = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    int k2 = 4;
    cout << "Example 2 Output: " << sol.maxSumAfterPartitioning(arr2, k2) << endl; 
    // Expected: 83

    vector<int> arr3 = {1};
    int k3 = 1;
    cout << "Example 3 Output: " << sol.maxSumAfterPartitioning(arr3, k3) << endl; 
    // Expected: 1

    return 0;
}#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // dp[i] will store the maximum sum for the subarray arr[0...i-1]
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            int current_max = 0;
            // Look back up to k elements to form the last partition
            for (int j = 1; j <= k && i - j >= 0; ++j) {
                // arr[i - j] is the current element being added to the partition
                current_max = max(current_max, arr[i - j]);
                
                // Calculate the max sum if the last partition has length j
                dp[i] = max(dp[i], dp[i - j] + current_max * j);
            }
        }
        
        // The answer for the entire array is stored at dp[n]
        return dp[n];
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> arr1 = {1, 15, 7, 9, 2, 5, 10};
    int k1 = 3;
    cout << "Example 1 Output: " << sol.maxSumAfterPartitioning(arr1, k1) << endl; 
    // Expected: 84

    vector<int> arr2 = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    int k2 = 4;
    cout << "Example 2 Output: " << sol.maxSumAfterPartitioning(arr2, k2) << endl; 
    // Expected: 83

    vector<int> arr3 = {1};
    int k3 = 1;
    cout << "Example 3 Output: " << sol.maxSumAfterPartitioning(arr3, k3) << endl; 
    // Expected: 1

    return 0;
}