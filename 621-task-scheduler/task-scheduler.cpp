
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char ch : tasks) {
            freq[ch - 'A']++;
        }

        sort(freq.begin(), freq.end());

        int maxFreq = freq[25];

        int idleSlots = (maxFreq - 1) * n;

        for (int i = 24; i >= 0; i--) {
            idleSlots -= min(maxFreq - 1, freq[i]);
        }

        return tasks.size() + max(0, idleSlots);
    }
};
