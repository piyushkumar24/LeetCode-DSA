class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.length();
        int ans = 0, cntb = 0, cnta = 0, cntl = 0, cnto = 0, cntn = 0;

        for(int i = 0; i<n; i++){
            if(text[i] == 'b') cntb++;
            else if(text[i] == 'a') cnta++;
            else if(text[i] == 'l') cntl++;
            else if(text[i] == 'o') cnto++;
            else if(text[i] == 'n') cntn++;

            if(cntb>=1 && cnta>=1 && cntl>=2 && cnto>=2 && cntn>=1){
                ans++;
                cntb--; 
                cnta--;
                cntl -= 2;
                cnto -= 2;
                cntn--;
            }
        }
        return ans;
    }
};