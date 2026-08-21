class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b, long long limit) {
        long long g = gcd(a, b);

        // Avoid overflow
        if (a / g > limit / b)
            return limit + 1;

        return (a / g) * b;
    }

    long long count(long long mid, vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

        // Inclusion-Exclusion
        for (int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    L = lcm(L, coins[i], mid);

                    if (L > mid)
                        break;
                }
            }

            if (L > mid)
                continue;

            if (bits % 2 == 1)
                total += mid / L;
            else
                total -= mid / L;
        }

        return total;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (count(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};