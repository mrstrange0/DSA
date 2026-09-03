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

    // Find middle of linked list
    ListNode* FindMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }


    // Merge two sorted linked lists
    ListNode* Merge2Lists(ListNode* list1, ListNode* list2) {

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if (list1 != NULL)
            temp->next = list1;

        if (list2 != NULL)
            temp->next = list2;

        return dummyNode->next;
    }


    // Merge Sort
    ListNode* sortList(ListNode* head) {

        // 0 or 1 node
        if (head == NULL || head->next == NULL)
            return head;

        // Find middle
        ListNode* middle = FindMiddle(head);

        // Split into two lists
        ListNode* righthead = middle->next;
        middle->next = NULL;

        ListNode* lefthead = head;

        // Sort both halves
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);

        // Merge
        return Merge2Lists(lefthead, righthead);
    }
};