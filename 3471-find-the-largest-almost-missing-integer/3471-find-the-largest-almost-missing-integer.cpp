class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;

        // Check every subarray of size k
        for (int i = 0; i <= n - k; i++) {
            
            // To avoid counting the same number twice
            // in the same subarray
            unordered_set<int> st;

            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Increase count for every unique number
            for (int x : st) {
                count[x]++;
            }
        }

        int ans = -1;

        for (auto it : count) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};