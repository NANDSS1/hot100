class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //对每行进行二分查找
        for(const auto& vec:matrix){
            int left = 0;
            int right = vec.size()-1;
            //左闭右闭的二分查找
            while(left <= right){//这里是和右开不一样的，这里是闭区间
                int mid = left + (right-left)/2;
                if(vec[mid] == target) return true;
                else if(vec[mid] < target) left = mid + 1;
                else if(vec[mid] > target) right = mid -1;//这里是和右开不一样的，是取mid-1
            }
        }

        return false;
        
    }
};