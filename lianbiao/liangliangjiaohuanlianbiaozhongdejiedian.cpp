class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* prev = dummyHead;
        ListNode* cur = prev->next;
        //停止循环的条件
        while(prev->next != nullptr && prev->next->next !=nullptr){
            ListNode* curnext = cur->next;//交换节点组的第二个结点
            cur->next = cur->next->next;//交换节点组的第一个结点和第二个结点断开，指向下一个交换节点组的第一个结点
            curnext->next = cur;//交换节点组的第二个结点指向第一个结点
            prev->next = curnext;//更新前驱结点的指向
            prev = cur;//更新前驱结点
            cur = cur->next;//更新交换节点组的第一个结点
        }
        prev->next = cur;
        return dummyHead->next;

    }
};