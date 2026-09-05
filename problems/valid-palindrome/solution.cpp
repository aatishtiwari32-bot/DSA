class Solution {
private:
    bool check_valid(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return 1;
        }
        return 0;
    }
public:
    char tolower(char ch){
        if((ch >= 'a' && ch <= 'z')|| (ch >= '0' && ch <= '9')){
            return ch;
        }
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
        }
    char check_palindrome(string arr){
        int s = 0;
        int e = arr.length()-1;
        while(s<=e){
            if(arr[s] != arr[e]){
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
    bool isPalindrome(string s) {
        string temp = "";
        int j;
        for(j= 0; j< s.length(); j++){
            if(check_valid(s[j])){
                temp.push_back(s[j]);
            }
        }
        for(j= 0; j< temp.length(); j++){
            temp[j] = tolower(temp[j]);
        }
        return check_palindrome(temp);
        
    }
};