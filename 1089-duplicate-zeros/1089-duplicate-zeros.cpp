class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zero = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0)
                zero++;
        }
        int n = arr.size();
        int ns = n + zero;
        int i = n - 1;
        int j = ns - 1;
        while (i >= 0 && j >= 0) {
            if (arr[i] == 0) {
                i = i - 1;
                if (j < n) {
                    arr[j] = 0;
                }
                j = j - 1;
                if (j < n) {
                    arr[j] = 0;
                }
                j = j - 1;
            }
            else if(arr[i] != 0) {
                if (j < n) {
                    arr[j] = arr[i];
                }
                j = j - 1;
                i = i - 1;
            }
        }
    }
};