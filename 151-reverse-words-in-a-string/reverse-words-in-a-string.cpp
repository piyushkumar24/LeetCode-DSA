class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n=s.length();
        int left=0, right=0, i=0;
        while(i<n){
            while(i<n && s[i]==' '){ // Skipping the leading spaces
                i++; 
            }
            if(i==n) break; // To stop index going out of bonds
            while(i<n && s[i]!=' '){ // Copy characters of a word to the correct position
                s[right++]=s[i++];
            }
            reverse(s.begin()+left, s.begin()+right); // Reverse indiviual words
            s[right++]=' '; // Add space betewen words
            left=right;
            i++;
        }
        s.resize(right-1); // To resize the string to remove any extra spaces
        return s;
    }
};