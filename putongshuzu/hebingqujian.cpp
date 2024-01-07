/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

 

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[0] < b[0];//从小到大排序
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //取并集
        //先排序
        sort(intervals.begin(),intervals.end(),cmp);
        //有可能最后的结果有分段的区间
        vector<vector<int>> ans;
        for(int i = 1;i < intervals.size();i++){
            //第i个interval的左端点一定比第i-1个大
            //需要判断第i个interval的左端点和第i-1个元素的右端点
            if(intervals[i][0] > intervals[i-1][1]){
                //中断了
                ans.emplace_back(intervals[i-1]);
            }else{
                //合并第i个端点
                intervals[i][0] = min(intervals[i-1][0],intervals[i][0]);
                intervals[i][1] = max(intervals[i-1][1],intervals[i][1]);
            }
        }

        ans.emplace_back(intervals.back());
        return ans;
    }
};