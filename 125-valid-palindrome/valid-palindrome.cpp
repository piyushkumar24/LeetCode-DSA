class Solution {
public:
    bool isPalindrome(string s) {
        string p1, p2;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                p1.push_back(tolower(s[i]));
            }
        }
        p2=p1;
        reverse(p1.begin(), p1.end());
        return p1==p2;
    }
};