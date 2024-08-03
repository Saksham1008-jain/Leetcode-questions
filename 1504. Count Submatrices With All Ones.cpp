class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        
        int rows=mat.size();
        int cols=mat[0].size();
        
        vector<vector<int>> prefix(rows,vector<int>(cols));
        for(int i=0;i < rows; i++)
        {
            int c=0;
            for(int j=cols-1;j>=0;j--)
            {
                if(mat[i][j]==1)
                    c++;
                else
                    c=0;
                prefix[i][j]=c;
            }
        }
        
        int res=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                int mini=INT_MAX;
                for(int k=i;k<rows;k++)
                {
                    mini=min(mini,prefix[k][j]);
                    res+=mini;
                }
            }
        }
        return res;
    }
};
