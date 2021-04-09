class Solution {
public:

ListNode* reverseKGroup(ListNode* head, int k) {
	bool end = false; 
	ListNode* ktail = nullptr;
	ListNode* ans = nullptr;
	while (end != true) {
		ListNode* old_head = head;
		int  m = k;
		while (m != 0 && old_head) {
			if (m == 1) {
				ans = !ans ?old_head:ans;
			}
			old_head = old_head->next;
			m--;
		}
		if (m != 0) {
			ktail->next = head;
			end = true;
			break;
		}
		old_head = head;
		ListNode* prev = nullptr;
		m = k;
		while (old_head && m) {
			ListNode* nxt = old_head->next;
			old_head->next = prev;
			prev = old_head;
			old_head = nxt;
			m--;
		}
		ktail?ktail->next = prev:nullptr;
		ktail = head;
		head = old_head;
		if (!head)
			end = true;
	}
	return ans ? ans : head;
}
};
