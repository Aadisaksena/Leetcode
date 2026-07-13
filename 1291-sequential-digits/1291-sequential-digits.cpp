class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> store = {12,123,1234,12345,123456,1234567,12345678,123456789};
        vector<int> ones  = {11,111,1111,11111,111111,1111111,11111111,111111111};

        vector<int> ans;

        int i;
        for (i = 0; i < store.size(); i++) {
            if (store[i] > low)
                break;
        }

        // Process the previous digit length (numbers that may have been missed)
        if (i > 0) {
            int num = store[i - 1];
            while (num % 10 != 0) {
                if (num >= low && num <= high)
                    ans.push_back(num);
                num += ones[i - 1];
            }
        }

        // Process current and larger digit lengths
        while (i < store.size()) {
            int num = store[i];

            while (num % 10 != 0) {
                if (num >= low && num <= high)
                    ans.push_back(num);

                if (num > high)
                    return ans;

                num += ones[i];
            }

            i++;
        }

        return ans;
    }
};