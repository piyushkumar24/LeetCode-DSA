class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp; // For counting the frequency
        multimap<int,char>r; // For mapping frequency to characters
        string ss="";
        for(auto a:s){
            mp[a]++;
        }
        for(auto a:mp){
            r.insert({a.second,a.first});
        }
        for(auto it=r.rbegin();it!=r.rend();it++){ 
            // For sorting by frequency - Traversing the multimap in reverse order (using reverse iterators)
            ss+=string(it->first,it->second); 
        }
        return ss; 
    }
};