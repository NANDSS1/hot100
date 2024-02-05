#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int i,int j,int k,string& word,vector<vector<bool>>& visited,vector<vector<char>>& board){
        if(board[i][j] != word[k]) return false;
        else if (k == word.length() - 1) return true;
        visited[i][j] = true;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& dir : directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {//没有访问过
                    bool flag = check(newi,newj,k+1,word,visited,board);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false; // 回溯，还原访问状态
        return result;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size();
        int w = board[0].size();
        vector<vector<bool>> visited(h,vector<bool>(w,false));
        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                bool flag = check(i,j,0,word,visited,board);
                if(flag==true) return flag;
            }
        } 

        return false;
    }
};