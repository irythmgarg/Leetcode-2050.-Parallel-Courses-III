class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        // Graph adjacency list: course -> list of dependent courses
        unordered_map<int, vector<int>> mp;

        // Indegree vector: how many prerequisites each course has
        vector<int> indegree(n, 0);

        // Stores the maximum time needed to complete each course
        unordered_map<int, int> maxans;

        int mainans = 0;

        // Build the graph and fill indegree information
        for (int i = 0; i < relations.size(); i++) {
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;
            mp[u].push_back(v);
            indegree[v]++;
        }

        // Queue for topological sort
        queue<int> q;

        // Push all courses that have no prerequisites
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                maxans[i] = time[i];
                mainans = max(mainans, maxans[i]);
            }
        }

        // Topological sort + DP on course time
        while (!q.empty()) {
            int top = q.front();
            q.pop();

            // Traverse the dependent courses
            for (int a : mp[top]) {
                indegree[a]--;  // Remove edge

                // Update max time to complete course `a`
                maxans[a] = max(maxans[a], maxans[top] + time[a]);
                mainans = max(mainans, maxans[a]);

                // If all prerequisites are done, push to queue
                if (indegree[a] == 0)
                    q.push(a);
            }
        }

        return mainans;
    }
};
