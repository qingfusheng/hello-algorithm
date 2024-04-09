#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        unordered_set<ListNode *> MySet;
        MySet.insert(head);
        while (head != nullptr)
        {
            head = head->next;
            if (MySet.count(head) > 0)
                return true;
            MySet.insert(head);
        }
        return false;
    }
};

int main()
{
}