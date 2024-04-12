// APPROACH-1

// class Solution {
// public:
//     int beautySum(string s) {
//         int ans=0;
//         for(int i=0;i<s.size();i++){
//             unordered_map<char,int>mp;
//             for(int j=i;j<s.size();j++){
//                 mp[s[j]]++;
//                 int mini=INT_MAX;
//                 int maxi=INT_MIN;
//                 for(auto it:mp){
//                     maxi=max(maxi,it.second);
//                     mini=min(mini,it.second);
//                 }
//                 ans=ans+maxi-mini;
//             }
//         }
//         return ans;
//     }
// };


// APPROACH-2

class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int>mp;
            multiset<int>st;
            for(int j=i;j<s.size();j++){
                if(mp.find(s[j])!=mp.end()){
                    st.erase(st.find(mp[s[j]]));
                }
                mp[s[j]]++;
                st.insert(mp[s[j]]);
                ans+=(*st.rbegin()-*st.begin());
            }
        }
        return ans;
    }
};