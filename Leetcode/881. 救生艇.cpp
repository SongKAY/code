class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        if(n==1)
            return 1;
        int l = 0;
        int r = n-1;
        int result = 0;
        sort(people.begin(),people.end());
        while(l<r){
            int sum = people[r] + people[l];
            if(sum>limit){
                result += 1;
                r--;
            }
            else if(sum<=limit){
                result += 1;
                r --;
                l ++;
            }
        }
        if(l==r)
            result += 1;
        return result;
    }
};
