class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //删除链表倒数第N个节点就用快慢指针
        ListNode* fast = head;
        ListNode* slow = head;
        //让fast指针先走n步
        while(n--){
            fast = fast->next;
        }
        //fast为空的时候，slow就到达了倒数第N个节点
        //fast到了最后一个节点的时候(也就是空结点的前一个节点的时候)，slow就到了倒数第N个节点的前一个节点，就可以做删除
        while()

    }
};