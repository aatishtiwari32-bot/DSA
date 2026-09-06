class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() != 0 && s.find(part) < s.length()) {
            int found_index;
            found_index = s.find(part);
            s.erase(found_index, part.length());
        }
        return s;
    }
};