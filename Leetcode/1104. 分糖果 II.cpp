class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int pre = 1;
        for(;;pre++){
            if(pre*(pre+1)/2>candies){
                break;
            }
        }
        pre -= 1;
        if(pre<=num_people){
            vector<int> result;
            int sum = 0;
            for(int i=1;i<=pre;i++){
                sum += i;
                result.push_back(i);
            }
            while(result.size()<num_people){
                if(sum<candies){
                    result.push_back(candies-sum);
                    sum = candies;
                }
                else
                    result.push_back(0);
            }
            return result;
        }
        else{
            int k = pre/num_people;
            int left = pre%num_people;
            vector<int> result;
            for(int i=1;i<=num_people;i++){
                int sum = 0;
                if(i<=left){
                    sum = i*(k+1)+k*(k+1)/2*num_people;
                }
                else if(i==left+1){
                    sum = i*k+k*(k-1)/2*num_people + candies - (1 + pre)*pre/2;
                }
                else
                    sum = i*k+k*(k-1)/2*num_people;
                result.push_back(sum);
            }
            return result;
        }
    }
};
