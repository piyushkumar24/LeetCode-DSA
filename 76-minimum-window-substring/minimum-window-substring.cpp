class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        int left=0, right=0;
        int cnt=0, sIndex=-1;
        int m=t.size(), minLen=INT_MAX;
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        while(right<s.size()){
            if(mpp[s[right]]>=1) cnt++;
            mpp[s[right]]--;
            while(cnt==m){
                if(right-left+1 < minLen){
                    sIndex=left;
                    minLen=min(minLen, right-left+1);
                }
                mpp[s[left]]++;
                if(mpp[s[left]]>=1) cnt--;
                left++;
            }
            right++;
        }
        if(minLen==INT_MAX) return "";
        else return s.substr(sIndex, minLen);
    }
};