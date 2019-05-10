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
    int getvalue(map<int,Employee*> m,int id){
        int result = 0;
        Employee* employee = m[id];
        result += employee->importance;
        vector<int> temp = employee->subordinates;
        for(int i=0;i<employee->subordinates.size();i++){
            result += getvalue(m,temp[i]);
        }
        return result;
    }
    int getImportance(vector<Employee*> employees, int id) {
        map<int,Employee*> m;
        for(int i=0;i<employees.size();i++)
            m[employees[i]->id] = employees[i];
        return getvalue(m,id);
    }
};
