class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        
        int cnt[3] = {0, 0, 0};

        // Count remainders
        for(int x : stones)
        {
            cnt[x % 3]++;
        }

        int zero = cnt[0];
        int one = cnt[1];
        int two = cnt[2];

        // If there are no 1 or 2 remainder stones,
        // Alice cannot make a safe first move.
        if(one == 0 && two == 0)
            return false;

        // If number of 0-remainder stones is even
        if(zero % 2 == 0)
        {
            return one > 0 && two > 0;
        }

        // If number of 0-remainder stones is odd
        return abs(one - two) > 2;
    }
};