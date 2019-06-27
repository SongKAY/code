class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        if(ops.empty())
            return sum;
        stack<int> temp;
        for(auto a:ops){
            if(a=="C"||a=="D"||a=="+"){
                if(a=="C"){
                    if(!temp.empty())
                        temp.pop();
                }
                else if(a=="D"){
                    int t1 = temp.top();
                    t1 *= 2;
                    temp.push(t1);
                }
                else{
                    int t1 = temp.top();
                    temp.pop();
                    int t2 = temp.top();
                    temp.pop();
                    temp.push(t2);
                    temp.push(t1);
                    temp.push(t1+t2);
                }
            }
            else{
                temp.push(stoi(a));
            }
        }
        while(!temp.empty()){
            sum += temp.top();
            temp.pop();
        }
        return sum;
    }
};
