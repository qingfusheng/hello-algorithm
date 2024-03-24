// 题目名称：2. 两数相加
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/add-two-numbers/description/
// 题目思路：链表
// 备注：链表的常规操作，单链表，注意进位
// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *cur = nullptr;  // 同时也算是尾指针
        int carry = 0;
        while(l1!=nullptr || l2 != nullptr){
            int n1, n2, sum;
            n1 = (l1!=nullptr)?l1->val:0;
            n2 = (l2!=nullptr)?l2->val:0;
            sum = n1+n2+carry;
            if(head == nullptr){
                head = cur = new ListNode(sum%10);
            }else{
                cur->next = new ListNode(sum%10);
                cur = cur->next;
            }
            carry = sum/10;
            if(l1!=nullptr)
                l1 = l1->next;
            if(l2!=nullptr)
                l2 = l2->next;
        }
        if(carry>0)
            cur->next = new ListNode(carry);
        return head;
    }
};
int main(){

}