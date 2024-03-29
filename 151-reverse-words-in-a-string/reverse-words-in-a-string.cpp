class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.length();
        int left=0;
        int right=0;
        int i=0;
        while(i<n){
            while(i<n && s[i]==' ') { // Skipping the Leading Spaces
                i++;
            }
            if(i==n){
                break; // To stop index going out of bounds
            }
            while(i<n && s[i]!=' '){ // Copy characters of a word to the correct position
                s[right++]=s[i++];
            }
            reverse(s.begin()+left,s.begin()+right); // Reverse individual words
            s[right++]=' '; // Add space between words
            left=right;
            i++;
        }
        s.resize(right-1); // To resize the string to remove any extra spaces
        return s;
    }
};