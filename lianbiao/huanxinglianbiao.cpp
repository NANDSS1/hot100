
/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //哈希表判断是否有环
        unordered_set<ListNode*> hashset;
        ListNode* cur = head;
        while(cur != nullptr){
            if(!hashset.count(cur)) hashset.insert(cur);
            else return true;//有环
            cur = cur->next;
        }

        return false;//能出来，无环
        
    }
};
*/

//不用哈希set，用快慢指针解决
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //只要快慢指针相遇了那么就有环
        //如果快指针到了nullptr就无环
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }

        return false;
        
    }
};