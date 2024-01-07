class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //删除链表倒数第N个节点就用快慢指针
        //创建一个dummy头，防止只有一个元素的情况
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        //让fast指针先走n步
        while(n--){
            fast = fast->next;
        }
        //fast为空的时候，slow就到达了倒数第N个节点
        //fast到了最后一个节点的时候(也就是空结点的前一个节点的时候)，slow就到了倒数第N个节点的前一个节点，就可以做删除
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummyHead->next;

    }
};