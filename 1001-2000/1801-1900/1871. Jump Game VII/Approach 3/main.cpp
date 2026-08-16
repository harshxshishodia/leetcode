class Solution {
public:
    bool canReach(
        string s,
        int minJump,
        int maxJump
    ) {
        int n =
            static_cast<int>(s.size());

        queue<int> pending;
        pending.push(0);

        int farthestScanned = 0;

        while (!pending.empty()) {
            int index =
                pending.front();

            pending.pop();

            int start = max(
                index + minJump,
                farthestScanned + 1
            );

            int end = min(
                n - 1,
                index + maxJump
            );

            for (int next = start;
                 next <= end;
                 next++) {
                if (s[next] != '0') {
                    continue;
                }

                if (next == n - 1) {
                    return true;
                }

                pending.push(next);
            }

            farthestScanned = max(
                farthestScanned,
                end
            );
        }

        return n == 1;
    }
};
