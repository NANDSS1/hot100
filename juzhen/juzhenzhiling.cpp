class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix[0].size()-1;
        int t = 0;
        int b = matrix.size()-1;
        int all = matrix.size() * matrix[0].size();//给元素总数计数
        int k = 0;

        vector<int> ans;

        while(k < all){
            for(int i = l;i <= r&&k < all;i++,k++) ans.push_back(matrix[t][i]);
            t++;
            for(int i = t;i <= b&&k < all;i++,k++) ans.push_back(matrix[i][r]);
            r--;
            for(int i = r;i >= l&&k < all;i--,k++) ans.push_back(matrix[b][i]);
            b--;
            for(int i = b;i >= t&&k < all;i--,k++) ans.push_back(matrix[i][l]);
            l++;
        }
        
        return ans;

    }
};