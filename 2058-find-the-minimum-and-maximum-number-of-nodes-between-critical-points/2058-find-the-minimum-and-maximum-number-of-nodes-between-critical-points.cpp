class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* head_og = head;
        ListNode* temp = nullptr;
        ListNode* prev = head;
        head = head->next;

        // 1. Find first critical point
        while (head->next != nullptr) {
            if ((head->val > prev->val && head->val > head->next->val) ||
                (head->val < prev->val && head->val < head->next->val)) {
                
                temp = head;
                break;
            }

            prev = head;
            head = head->next;
        }

        if (temp == nullptr)
            return {-1, -1};

        // 2. Find maximum distance
        int c = 0;
        int maxx = 0;

        prev = temp;
        head = temp->next;

        while (head->next != nullptr) {
            c++;

            if ((head->val > prev->val && head->val > head->next->val) ||
                (head->val < prev->val && head->val < head->next->val)) {
                
                maxx = c;
            }

            prev = head;
            head = head->next;
        }

        // 3. Find minimum distance
        int mini = INT_MAX;
        c = 0;

        prev = temp;
        head = temp->next;

        while (head->next != nullptr) {
            c++;

            if ((head->val > prev->val && head->val > head->next->val) ||
                (head->val < prev->val && head->val < head->next->val)) {
                
                mini = min(mini, c);
                c = 0;
            }

            prev = head;
            head = head->next;
        }

        if (mini == INT_MAX)
            return {-1, -1};

        return {mini, maxx};
    }
};