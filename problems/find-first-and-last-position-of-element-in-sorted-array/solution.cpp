class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int start = 0;
        int end = size - 1;
        int f_index = -1;
        int l_index = -1;
        // First occurrence
        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(nums[mid] == target)
            {
                f_index = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        // Reset for last occurrence
        start = 0;
        end = size - 1;

        // Last occurrence
        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(nums[mid] == target)
            {
                l_index = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return {f_index, l_index};
    }
};