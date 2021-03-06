class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> temp(numCourses, 0);
        vector<vector<int>> mp(numCourses, temp);
        vector<int> in(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) 
        {
            mp[prerequisites[i].second][prerequisites[i].first] = 1;
            in[prerequisites[i].first]++;
        }
        int cnt = 0;
        vector<int> vis(numCourses, 0);
        while(++cnt <= numCourses)
        {
            int index = -1;
            for(int  i = 0; i < numCourses; i++)
                if(in[i] == 0 && !vis[i])
                {
                    vis[i] = 1;
                    index = i;
                    break;
                }
            if(index == -1) return false;
            for(int i = 0; i < numCourses; i++) if(mp[index][i])in[i]--;
        }
        return true;
    }
};