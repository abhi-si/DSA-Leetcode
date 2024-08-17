class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: if the list has only one node, return nullptr
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        fast=fast->next->next; 
        
        while (fast != nullptr && fast->next != nullptr) {
          
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* middle = slow->next;
        slow->next = slow->next->next;
        delete middle; 

        return head;
    }
};
