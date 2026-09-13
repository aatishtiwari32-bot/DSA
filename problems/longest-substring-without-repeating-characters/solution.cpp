class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int freq[256] = {0};
        while(right < s.size())
        {
            int val = s[right];
            freq[val]++;
            while(freq[val] > 1)
            {
                freq[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);

            right++;
        }
        return maxLen;
    }
};