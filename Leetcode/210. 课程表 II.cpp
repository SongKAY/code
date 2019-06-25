class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> m(numCourses,vector<int>(numCourses,0));
        vector<int> p(numCourses,0);
        int n = prerequisites.size();
        for(int i=0;i<n;i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            m[b][a] = 1;
            p[a] ++;
        }
        vector<int> result;
        queue<int> q;
        vector<int> flag(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(p[i]==0){
                flag[i] = 1;
                q.push(i);
            }
        }
        while(!q.empty()){
            int t = q.front();
            q.pop();
            result.push_back(t);
            for(int i=0;i<numCourses;i++){
                if(flag[i]==1)
                    continue;
                if(m[t][i]==1){
                    p[i] -= 1;
                }
                if(p[i]==0){
                    flag[i] = 1;
                    q.push(i);
                }
            }
        }
        if(result.size()==numCourses)
            return result;
        else{
            result.clear();
            return result;
        }
    }
};
