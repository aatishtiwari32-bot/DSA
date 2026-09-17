class Solution {
public:
    void backtrack(string& digits,
                   int index,
                   string& current,
                   vector<string>& ans)
    {
        // saare digits process ho gaye
        if(index == digits.size())
        {
            ans.push_back(current);
            return;
        }
        string keypad[10] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        string letters = keypad[digits[index] - '0'];
        for(int i = 0; i < letters.size(); i++)
        {
            // choose
            current.push_back(letters[i]);
            // next digit
            backtrack(digits, index + 1, current, ans);
            // undo
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if(digits.empty())
            return ans;
        string current = "";
        backtrack(digits, 0, current, ans);
        return ans;
    }
};