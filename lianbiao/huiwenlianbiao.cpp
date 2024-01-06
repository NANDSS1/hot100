#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        ListNode* cur = head;
        while(cur != nullptr){
            nums.push_back(cur->val);
            cur = cur->next;
        }
        //双指针判断是否回文
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            if(nums[l++] != nums[r--]) return false;
        }

        return true;
    }
};