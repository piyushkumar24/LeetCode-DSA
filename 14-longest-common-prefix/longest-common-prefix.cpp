class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count=INT_MAX;
        for(int i=1;i<strs.size();i++){
            int sum=0;
            bool temp=false;
            for(int j=0;j<strs[i].size();j++){
                if(strs[0][j]==strs[i][j]&&temp!=1){
                    sum++;
                }
                else
                {
                   
                   temp=1;
                }
            }
             count=min(count,sum);
        }
        string s=strs[0].substr(0,count);
        cout<<count<<endl;
        return s;
    }
};