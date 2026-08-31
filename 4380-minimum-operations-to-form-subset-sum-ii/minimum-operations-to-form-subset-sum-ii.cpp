class Solution {
public:

    int solve(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {

        if (sum == 0) {
            return 0;
        }

        if (i >= nums.size() || sum < 0) {
            return 1e9;
        }

        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

        // CASE 1: Don't choose nums[i]
        int case1 = solve(i + 1, sum, nums, dp);

        // CASE 2: Multiply nums[i] by 2^k
        int case2 = 1e9;

        long long curr = nums[i];

        for (int k = 0; curr <= sum; k++) {

            int temp = solve(i + 1, sum - curr, nums, dp) + k;

            case2 = min(case2, temp);

            curr *= 2;
        }

        // CASE 3: Divide nums[i] by 2^k
        // and if the resulting value is even, multiply it again.
        int case3 = 1e9;

        long long prev = nums[i];
        long long currDiv = nums[i] / 2;

        for (int k = 1; currDiv >= 1; k++) {

            // Equivalent to:
            // nums[i] / 2^(k-1) % 2
            if (prev % 2 == 1) {

                // Equivalent to your inner loop
                long long curr2 = currDiv;

                for (int l = 0; curr2 <= sum; l++) {

                    int temp =
                        solve(i + 1, sum - curr2, nums, dp)
                        + k + l;

                    case3 = min(case3, temp);

                    curr2 *= 2;
                }

            }
            else {

                int temp =
                    solve(i + 1, sum - currDiv, nums, dp)
                    + k;

                case3 = min(case3, temp);
            }

            // Move to next division
            prev = currDiv;
            currDiv /= 2;
        }

        return dp[i][sum] = min({case1, case2, case3});
    }

    int minOperations(vector<int>& nums, int sum) {

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(sum + 1, -1)
        );

        int ans = solve(0, sum, nums, dp);

        if (ans >= 1e9) {
            return -1;
        }

        return ans;
    }
};