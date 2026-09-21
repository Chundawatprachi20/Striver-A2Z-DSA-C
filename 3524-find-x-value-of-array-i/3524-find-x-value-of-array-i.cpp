class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> ndp(k, 0);

            int r = num % k;

            ndp[r]++;

            for (int j = 0; j < k; j++) {
                int newR = (j * r) % k;
                ndp[newR] += dp[j];
            }

            dp = ndp;

            for (int j = 0; j < k; j++) {
                ans[j] += dp[j];
            }
        }

        return ans;
    }
};