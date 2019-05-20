class Solution {
public:
    int result = -1;
    bool check(int start, vector<int>& gas, vector<int>& cost){
        int n = gas.size();
        int have = gas[start];
        int t = start;
        int next = (t+1) % n;
        start = next;
        while(1){
            if(have-cost[t]<0)
                return false;
            have = have - cost[t] + gas[next];
            t = next;
            next = (t+1)%n;
            if(next==start)
                return true;
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i=0;i<n;i++){
            int have = gas[i];
            if(check(i,gas,cost)){
                return i;
            }
        }
        return result;
    }
};
