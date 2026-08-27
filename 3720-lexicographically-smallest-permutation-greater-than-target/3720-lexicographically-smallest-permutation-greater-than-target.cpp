class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Store frequency after matching each prefix
        vector<vector<int>> pref(n + 1, vector<int>(26));
        pref[0] = freq;

        int matched = 0;

        // Try matching target prefix
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (freq[x] == 0)
                break;

            freq[x]--;
            matched++;

            pref[matched] = freq;
        }

        // Try to make the answer greater from right to left
        for (int i = matched; i >= 0; i--) {

            if (i == n)
                continue;

            vector<int> cnt = pref[i];
            int x = target[i] - 'a';

            // Find the smallest character greater than target[i]
            for (int j = x + 1; j < 26; j++) {
                if (cnt[j] > 0) {

                    string ans = target.substr(0, i);

                    ans += char('a' + j);
                    cnt[j]--;

                    // Add remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        ans += string(cnt[k], char('a' + k));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};