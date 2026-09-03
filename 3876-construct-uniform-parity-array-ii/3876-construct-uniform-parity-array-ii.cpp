class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        // If the minimum element is odd,
        // we can make every element odd.
        if (mn % 2 == 1) {
            return true;
        }

        // If the minimum is even,
        // every element must already be even.
        for (int x : nums1) {
            if (x % 2 == 1) {
                return false;
            }
        }

        return true;
    }
};