class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return 0;
        }
        map<char,char>m1,m2;
        for(int i=0;i<s.length();i++){
            if(m1[s[i]]==0 && m2[t[i]]==0){
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
            if(m1[s[i]]!=t[i] && m2[t[i]]!=s[i]){
                return 0;
            }
        }
        return 1;
    }
};