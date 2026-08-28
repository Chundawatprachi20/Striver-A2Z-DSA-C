class Solution {
public:

    string makePalindrome(string half, char mid, int n) {
        string ans = half;

        if (n % 2 == 1)
            ans += mid;

        string rev = half;
        reverse(rev.begin(), rev.end());

        ans += rev;

        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        int m = n / 2;

        // Count characters
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check whether a palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Characters available in the first half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        string answer = "";

        /*
            Try to make the first half greater than
            target's first half.

            We try every possible position where the
            first difference can occur.
        */

        for (int pos = m - 1; pos >= 0; pos--) {

            vector<int> rem = halfCnt;

            bool possible = true;

            // Match target[0 ... pos-1]
            for (int i = 0; i < pos; i++) {

                int x = target[i] - 'a';

                if (rem[x] == 0) {
                    possible = false;
                    break;
                }

                rem[x]--;
            }

            if (!possible)
                continue;

            /*
                At position pos, choose a character
                greater than target[pos].
            */

            for (int x = target[pos] - 'a' + 1; x < 26; x++) {

                if (rem[x] == 0)
                    continue;

                vector<int> temp = rem;

                temp[x]--;

                // Construct the smallest possible suffix
                string half = target.substr(0, pos);

                half += char('a' + x);

                for (int c = 0; c < 26; c++) {
                    half += string(temp[c], char('a' + c));
                }

                string cur = makePalindrome(half, mid, n);

                if (cur > target) {

                    if (answer.empty() || cur < answer) {
                        answer = cur;
                    }
                }
            }
        }

        /*
            IMPORTANT CASE:

            The first half can be exactly equal to
            target's first half.

            Example:

                s      = "aabb"
                target = "abaa"

                half = "ab"

                palindrome = "abba"

                abba > abaa

            So we must check this separately.
        */

        vector<int> rem = halfCnt;

        bool possible = true;

        for (int i = 0; i < m; i++) {

            int x = target[i] - 'a';

            if (rem[x] == 0) {
                possible = false;
                break;
            }

            rem[x]--;
        }

        if (possible) {

            string half = target.substr(0, m);

            string cur = makePalindrome(half, mid, n);

            if (cur > target) {

                if (answer.empty() || cur < answer) {
                    answer = cur;
                }
            }
        }

        return answer;
    }
};