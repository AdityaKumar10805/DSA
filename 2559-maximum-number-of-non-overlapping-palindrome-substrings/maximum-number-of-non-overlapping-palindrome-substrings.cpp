class Solution {
public:
    int solve(int st, int &k, string &s, vector<int>& dp, vector<vector<bool>>& isPal) {
        if (st >= s.size()) {
            return 0;
        }
        int ans = 0;
        if (dp[st] != -1) {
            return dp[st];
        }
        for (int i = st; i < s.size(); i++) {
            // Replaced checkPalindrome() function call with O(1) table lookup
            if (isPal[st][i]) { 
                int add = 0;
                if (i - st + 1 >= k) {
                    add++;
                }
                ans = max(ans, solve(i + 1, k, s, dp, isPal) + add);
            }
        }
        return dp[st] = ans;
    }
    
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n, -1);
        
        // MINIMAL ADDITION: Precompute palindromes in O(N^2) total time
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int st = 0; st <= n - len; st++) {
                int end = st + len - 1;
                if (s[st] == s[end]) {
                    if (len <= 2 || isPal[st + 1][end - 1]) {
                        isPal[st][end] = true;
                    }
                }
            }
        }
        
        return solve(0, k, s, dp, isPal);
    }
};
