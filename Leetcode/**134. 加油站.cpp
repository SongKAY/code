class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int flag = 0;
        if(gas.empty())
            return -1;
        int n = gas.size();
        for(int i=0;i<n;i++){
            int s = i;
            int left = gas[i];
            int j = s;
            while(true){
                left -= cost[j];
                if(left<0)
                    break;
                j ++;
                if(j==n)
                    j = 0;
                if(j==s)
                    return s;
                left += gas[j];
            }
        }
        return -1;
    }
};
