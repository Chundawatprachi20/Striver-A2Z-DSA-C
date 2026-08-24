class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Calculate prefix sums
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // Start from the last prefix sum
        int ans = stones[n - 1];

        // Calculate answer backwards
        for (int i = n - 2; i >= 1; i--) {
            ans = max(ans, stones[i] - ans);
        }

        return ans;
    }
};