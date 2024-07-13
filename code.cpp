class Solution {
public:
   vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& health, string dir) {
        int n = pos.size();
        vector<int> ids(n);
        for (int i = 0; i < n; i++) {
            ids[i] = i;
        }
        auto compare = [&](int a, int b) {
            return pos[a] < pos[b];
        };
        sort(ids.begin(), ids.end(), compare);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int id = ids[i];
            if (dir[id] == 'R') {
                st.push(id);
            } else {
                while (!st.empty() && health[id] > 0) {
                    if (health[id] > health[st.top()]) {
                        health[id]--;
                        health[st.top()] = 0;
                        st.pop();
                    } else if (health[id] < health[st.top()]) {
                        health[st.top()]--;
                        health[id] = 0;
                    } else {
                        health[st.top()] = 0;
                        health[id] = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (health[i] > 0) {
                ans.push_back(health[i]);
            }
        }
        return ans;
    }
};
