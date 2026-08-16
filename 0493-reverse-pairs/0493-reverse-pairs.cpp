class Solution {
public:

    long long merge(vector<int>& nums, int low, int mid, int high)
    {
        long long count = 0;

        int j = mid + 1;

        // Count reverse pairs
        for(int i = low; i <= mid; i++)
        {
            while(j <= high && (long long)nums[i] > 2LL * nums[j])
            {
                j++;
            }

            count += (j - (mid + 1));
        }

        // Merge two sorted halves
        vector<int> temp;

        int i = low;
        j = mid + 1;

        while(i <= mid && j <= high)
        {
            if(nums[i] <= nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid)
        {
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= high)
        {
            temp.push_back(nums[j]);
            j++;
        }

        for(int k = low; k <= high; k++)
        {
            nums[k] = temp[k - low];
        }

        return count;
    }

    long long mergeSort(vector<int>& nums, int low, int high)
    {
        if(low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        long long count = 0;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);

        count += merge(nums, low, mid, high);

        return count;
    }

    int reversePairs(vector<int>& nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};