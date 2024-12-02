class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char>st;
        for(int i=0;i<sentence.length();i++){
            st.insert(sentence[i]);
        }
        if(st.size()==26) return true;
        else return false;
    }
};