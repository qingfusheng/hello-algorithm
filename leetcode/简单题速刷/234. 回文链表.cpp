#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr)return true;
        int count = 0;
        ListNode *cur = head;
        while(cur!= nullptr){
            count+=1;
            cur = cur->next;
        }
        cout<<"count:"<<count<<endl;
        int index = -1;
        stack<int> ss;
        while(head != nullptr){
            index++;
            if(count % 2 == 1 && index == (count - 1) / 2){
                head = head->next;
                continue;
            }
            if(index < count / 2){
                ss.push(head->val);
            }else{
                if(head->val == ss.top()){
                    ss.pop();
                }else{
                    return false;
                }
            }
            head = head->next;
        }
        return true;
    }
};

// 很慢，因为需要遍历两次，第一次获取长度，第二次判断是否回文，感觉不如直接存储成vector然后双指针（不过也需要两次
// 官方题解是存储成列表然后使用双指针