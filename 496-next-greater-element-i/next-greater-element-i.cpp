class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        vector<int> v;
        for (int i = 0; i < a.size(); i++) {
            int k = -1;
            int ans = 0;
            for (int j = 0; j < b.size(); j++) {
                if (ans == 0) {
                    if (a[i] == b[j]) ans++;
                    continue;
                }
                if (b[j] > a[i]) {
                    k = b[j];
                    break;
                }
            }
            v.push_back(k);
        }
        return v;
    }
};