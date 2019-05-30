class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> temp;
        int l = -1;
        int r = 0;
        int start = 0;
        while(start<n&&seats[start]!=1){
            start ++;
        }
        if(start>0){
            temp.push_back(start);
        }
        l = start;
        for(int i=start+1;i<n;i++){
            if(seats[i]==0)
                continue;
            else{
                int cnt = i - l - 1;
                if(cnt%2==0)
                    temp.push_back(cnt/2);
                else
                    temp.push_back(cnt/2+1);
                l = i;
                r = 0;
            }
        }
        if(r==0){
            temp.push_back(n-1-l);
        }
        sort(temp.begin(),temp.end());
        return temp[temp.size()-1];
    }
};
