class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;

        // Count frequency
        for (char task : tasks) {
            freq[task]++;
        }

        // Max Heap
        priority_queue<int> maxHeap;

        for (auto it : freq) {
            maxHeap.push(it.second);
        }

        int time = 0;

        while (!maxHeap.empty()) {

            vector<int> temp;

            // One cycle = n + 1
            for (int i = 0; i <= n; i++) {

                if (!maxHeap.empty()) {

                    int curr = maxHeap.top();
                    maxHeap.pop();

                    curr--;

                    if (curr > 0) {
                        temp.push_back(curr);
                    }
                }

                time++;

                // Stop if all tasks are finished
                if (maxHeap.empty() && temp.empty()) {
                    break;
                }
            }

            // Push remaining frequencies back
            for (int f : temp) {
                maxHeap.push(f);
            }
        }

        return time;
    }
};