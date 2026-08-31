class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* prev = head;
        ListNode* curr = head->next;

        int position = 1;
        int first = -1;
        int last = -1;
        int minDistance = INT_MAX;

        while (curr != NULL && curr->next != NULL) {

            bool isMaxima = curr->val > prev->val &&
                            curr->val > curr->next->val;

            bool isMinima = curr->val < prev->val &&
                            curr->val < curr->next->val;

            if (isMaxima || isMinima) {

                if (first == -1) {
                    first = position;
                } else {
                    minDistance = min(minDistance, position - last);
                }

                last = position;
            }

            prev = curr;
            curr = curr->next;
            position++;
        }

        if (first == -1 || first == last) {
            return {-1, -1};
        }

        return {minDistance, last - first};
    }
};