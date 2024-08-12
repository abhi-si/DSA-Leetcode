/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);  // Dummy node to start the result list
        ListNode* curr = dummyHead;  // Pointer to track the current position in the result list
        ListNode* temp1 = l1;  // Pointer to traverse the first list
        ListNode* temp2 = l2;  // Pointer to traverse the second list
        int carry = 0;  // Initialize carry to 0
        
        // Traverse both lists until the end of both
        while (temp1 != nullptr || temp2 != nullptr) {
            int sum = carry;
            if (temp1) {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if (temp2) {
                sum += temp2->val;
                temp2 = temp2->next;
            }
            
            // Create a new node for the current digit of the sum
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;  
            curr->next = newNode;
            curr = curr->next;
        }

        if (carry) {
            curr->next = new ListNode(carry);
        }
        

        return dummyHead->next;
    }
};
