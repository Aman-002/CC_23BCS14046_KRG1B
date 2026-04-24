#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        
        // dp[i][j] will store the length of LCS of str1[0..i-1] and str2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // Backtrack to find the shortest common supersequence
        string res = "";
        int i = m, j = n;
        
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                // If characters match, it's part of the LCS
                res += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                // If str1 has a longer sequence, include str1's character
                res += str1[i - 1];
                i--;
            } else {
                // If str2 has a longer sequence, include str2's character
                res += str2[j - 1];
                j--;
            }
        }
        
        // If there are remaining characters in str1
        while (i > 0) {
            res += str1[i - 1];
            i--;
        }
        
        // If there are remaining characters in str2
        while (j > 0) {
            res += str2[j - 1];
            j--;
        }
        
        // We built the string backwards, so reverse it
        reverse(res.begin(), res.end());
        
        return res;
    }
};

// Example usage
int main() {
    Solution sol;
    
    string str1_1 = "abac", str2_1 = "cab";
    cout << "Example 1 Output: " << sol.shortestCommonSupersequence(str1_1, str2_1) << endl;
    // Expected: "cabac"
    
    string str1_2 = "aaaaaaaa", str2_2 = "aaaaaaaa";
    cout << "Example 2 Output: " << sol.shortestCommonSupersequence(str1_2, str2_2) << endl;
    // Expected: "aaaaaaaa"
    
    return 0;
}
