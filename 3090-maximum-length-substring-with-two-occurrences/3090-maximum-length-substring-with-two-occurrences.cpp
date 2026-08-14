class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int freq[256] = {0};

        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < s.length(); right++)
        {
            freq[s[right]]++;

            while(freq[s[right]] > 2)
            {
                freq[s[left]]--;
                left++;
            }

            int len = right - left + 1;

            if(len > maxLen)
            {
                maxLen = len;
            }
        }

        return maxLen;
    }
};