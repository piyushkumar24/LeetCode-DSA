class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>alphabets;
        int left=0, right=0;
        int maxf=0, maxLen=0;
        while(right<s.size()){
            alphabets[s[right]]++;
            maxf=max(maxf, alphabets[s[right]]);
            if((right-left+1)-maxf > k){
                alphabets[s[left]]--;
                left++;
            }
            maxLen=max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};