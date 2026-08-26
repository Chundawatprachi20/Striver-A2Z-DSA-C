class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int minLen = INT_MAX;

        vector<int> pos;

        // Store positions of all '1's
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                pos.push_back(i);
            }
        }

        // If fewer than k ones exist
        if (pos.size() < k) {
            return "";
        }

        // Check every group of k consecutive 1's
        for (int i = 0; i + k - 1 < pos.size(); i++) {
            int start = pos[i];
            int end = pos[i + k - 1];

            int len = end - start + 1;
            string curr = s.substr(start, len);

            if (len < minLen || (len == minLen && curr < ans)) {
                minLen = len;
                ans = curr;
            }
        }

        return ans;
    }
};