#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,vector<ListNode*>> mp;
        for(const auto& node:lists){
            //把链表的节点索引到了
            ListNode* cur = node;
            while(cur != nullptr){
                mp[cur->val].push_back(cur);
                cur = cur->next;
            }
        }

        //建立一个新的链表
        ListNode* dummyHead = new ListNode();
        ListNode* cur = dummyHead;
        for(auto& vec:mp){//这里不能用const了，要做修改
            //索引到一个存储链表地址的pair<int,vector>
            for(auto& node:vec.second){//这里不能用const了
                cur->next = node;
                cur = cur->next;
            }
        }

        cur->next = nullptr;
        return dummyHead->next;
        


    }
};