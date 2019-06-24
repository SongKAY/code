/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int,vector<int>> sub;
        int n = employees.size();
        vector<int> flag(2001,0);
        map<int,int> importance;
        for(auto each:employees){
            sub[each->id] = each->subordinates;
            importance[each->id] = each->importance;
        }
        int sum = 0;
        queue<int> q;
        q.push(id);
        flag[id] = 1;
        while(!q.empty()){
            int tmp = q.front();
            sum += importance[tmp];
            q.pop();
            for(int i=0;i<sub[tmp].size();i++){
                int t = sub[tmp][i];
                if(flag[t])
                    continue;
                q.push(t);
            }
        }
        return sum;
    }
};
