class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int n = nums.size();
        int x = 0;
        bool hasNonZero = false;

        for(int i = 0; i < n; i++)
        {
            x = x ^ nums[i];

            if(nums[i] != 0)
            {
                hasNonZero = true;
            }
        }

        // XOR of entire array is non-zero
        if(x != 0)
        {
            return n;
        }

        // XOR is zero, but there is a non-zero element
        if(hasNonZero)
        {
            return n - 1;
        }

        // All elements are zero
        return 0;
    }
};