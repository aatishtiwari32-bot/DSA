class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int max_water = 0;
        while (start < end) {
            int waterLevel = min(height[start], height[end]) * (end - start);
            if (waterLevel > max_water) {
                max_water = waterLevel;
            }
            if (height[start] > height[end]) {
                end--;
            }
            else if (height[start] < height[end]) {
                start++;
            }
            else {
                start++;
            }
        }
        return max_water;
    }
};