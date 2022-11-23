// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:


// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]
// Example 2:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]
// Example 3:

// Input: l1 = [0], l2 = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.



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
		stack<int> stackL1,stackL2;
		while(l1){
			stackL1.push(l1->val);
			l1=l1->next;
		}
		while(l2){
			stackL2.push(l2->val);
			l2=l2->next;
		}

		ListNode *dummy=new ListNode(0);
		dummy->next=NULL;
		int carry = 0,num1,num2;

		while (!stackL1.empty() || !stackL2.empty() || carry) {
			if(!stackL1.empty()){
				num1=stackL1.top();
				stackL1.pop();
			}else num1=0;

			if(!stackL2.empty()){
				num2=stackL2.top();
				stackL2.pop();
			}else num2=0;

			int sum = num1 + num2 + carry;
			int value = sum % 10;
			carry = sum / 10; //进位

			ListNode *newNode=new ListNode(value);
			newNode->next=dummy->next;
			dummy->next = newNode;
		}

		ListNode *retNode=dummy->next;
		delete dummy;
		return retNode;
	}
};







