class Solution {
public:
    int reverse(int x) {
        int digit_count = 0;
        int digit, ans = 0;
        while(x != 0) {
            digit = x % 10;
            x = x / 10;
            digit_count++;
            if(digit_count > 10) {
                return 0;
            }
            if(digit_count == 10) {
                if(ans > 214748364) {
                    return 0;
                }
                if(ans == 214748364 && digit > 7) {
                    return 0;
                }
                if(ans < -214748364) {
                    return 0;
                }
                if(ans == -214748364 && digit < -8) {
                    return 0;
                }
            }
            ans = ans * 10 + digit;
        }
        return ans;
    }
};