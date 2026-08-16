class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        int answer = 0;
        int start = 0;

        while (start < n) {
            int end = start;

            if (end + 1 < n &&
                arr[end] < arr[end + 1]) {
                while (end + 1 < n &&
                       arr[end] < arr[end + 1]) {
                    end++;
                }

                if (end + 1 < n &&
                    arr[end] > arr[end + 1]) {
                    while (end + 1 < n &&
                           arr[end] > arr[end + 1]) {
                        end++;
                    }

                    answer = max(
                        answer,
                        end - start + 1
                    );
                }
            }

            start =
                max(
                    end,
                    start + 1
                );
        }

        return answer;
    }
};
