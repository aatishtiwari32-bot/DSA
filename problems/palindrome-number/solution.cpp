class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int reverse_num = 0;
        while(x > reverse_num) {
            int num = x % 10;
            x = x / 10;
            reverse_num = reverse_num * 10 + num;
        }
        return x == reverse_num || x == reverse_num / 10;
    }
};