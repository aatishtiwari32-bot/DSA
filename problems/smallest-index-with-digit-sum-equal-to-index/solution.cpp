class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int digitsum = 0;
            while(n > 0) {
                digitsum += n % 10;
                n /= 10;
            }
            if(digitsum == i) {
                return i;
            }
        }
        return -1;
    }
};