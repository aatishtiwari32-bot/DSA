class Solution {
private:
    // Union of two sets
    set<string> unite(const set<string>& a, const set<string>& b) {
        set<string> result = a;
        for (const string& word : b) {
            result.insert(word);
        }
        return result;
    }
    // Concatenation / Cartesian product
    set<string> multiply(const set<string>& a, const set<string>& b) {
        set<string> result;
        for (const string& x : a) {
            for (const string& y : b) {
                result.insert(x + y);
            }
        }
        return result;
    }
    // Parses an expression until '}' or end
    set<string> parseExpression(string& expression, int& i) {
        set<string> result = parseTerm(expression, i);
        while (i < expression.length() && expression[i] == ',') {
            i++; // skip ','
            set<string> next = parseTerm(expression, i);
            result = unite(result, next);
        }
        return result;
    }
    // Parses concatenated terms
    set<string> parseTerm(string& expression, int& i) {
        set<string> result = {""};
        while (i < expression.length() &&
               expression[i] != '}' &&
               expression[i] != ',') {
            set<string> current;
            if (expression[i] == '{') {
                i++; // skip '{
                current = parseExpression(expression, i);
                i++; // skip '}'
            }
            else {
                current.insert(string(1, expression[i]));
                i++;
            }
            result = multiply(result, current);
        }
        return result;
    }
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> result = parseExpression(expression, i);
        return vector<string>(result.begin(), result.end());
    }
};