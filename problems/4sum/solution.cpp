class Solution {
public:

    void four_sum(vector<int>& nums,
                  int i,
                  int left,
                  int mid,
                  int right,
                  long long target,
                  vector<vector<int>>& ans)
    {
        if(mid >= right)
            return;

        long long sum = (long long)nums[i]
                      + nums[left]
                      + nums[mid]
                      + nums[right];

        // Found
        if(sum == target)
        {
            ans.push_back({
                nums[i],
                nums[left],
                nums[mid],
                nums[right]
            });

            // Skip duplicate mid values
            while(mid < right && nums[mid] == nums[mid + 1])
                mid++;

            // Skip duplicate right values
            while(mid < right && nums[right] == nums[right - 1])
                right--;

            four_sum(nums,
                     i,
                     left,
                     mid + 1,
                     right - 1,
                     target,
                     ans);
        }

        // Sum too small
        else if(sum < target)
        {
            int nextMid = mid + 1;
            // Skip duplicate mid values
            while(nextMid < right && nums[nextMid] == nums[mid])
                nextMid++;
            four_sum(nums,
                     i,
                     left,
                     nextMid,
                     right,
                     target,
                     ans);
        }
        // Sum too large
        else
        {
            int nextRight = right - 1;
            // Skip duplicate right values
            while(nextRight > mid && nums[nextRight] == nums[right])
                nextRight--;
            four_sum(nums,
                     i,
                     left,
                     mid,
                     nextRight,
                     target,
                     ans);
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 3; i++)
        {
            // duplicate i
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int left = i + 1; left < n - 2; left++)
            {
                // duplicate left
                if(left > i + 1 && nums[left] == nums[left - 1])
                    continue;
                int mid = left + 1;
                int right = n - 1;
                four_sum(nums,
                         i,
                         left,
                         mid,
                         right,
                         target,
                         ans);
            }
        }
        return ans;
    }
};