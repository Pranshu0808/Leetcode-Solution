class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {
        int maxElement = 0;
        int n = nums.size();

        unordered_map<int,int> mpp;
        for(auto &element : nums){
            mpp[element]++;
        }

        for(int i = 0; i < n; i++){
            maxElement = max(maxElement, nums[i]);
        }
        
        maxElement = max(maxElement, maxVal);

        vector<long long> spf(maxElement + 1);
        for(long long i = 0; i <= maxElement; i++){
            spf[i] = i;
        }
        for(long long i = 2; i <= maxElement; i++){
            if(spf[i] == i){
                for(long long j = i*i; j <= maxElement; j+=i){
                    if(spf[j] == j){
                        spf[j] = i;
                    }
                }
            }
        }

        vector<long long> freq(maxElement + 1);

        for(long long i = 2; i <= maxElement; i++){
            for(long long j = i; j <= maxElement; j+=i){
                if(mpp.find(j) != mpp.end()){
                    freq[i] += mpp[j];
                }
            }
        }
        
        long long score = 0;

        for(int i = 1; i <= maxElement; i++){
            long long totalDependent = 0;
            int num = i;

            vector<int> facs;
            int temp = num;
            
            while(temp > 1){
                int factor = spf[temp];
                facs.push_back(factor);
                while(temp % factor == 0){
                    temp = temp / factor;
                }
            }
            int sz = facs.size();
            for(int mask = 1; mask < (1<<sz); mask++){
                long long product = 1;
                int parity = 0;
                for(int idx = 0; idx < sz; idx++){
                    if(mask & (1<<idx)){
                        product *= facs[idx];
                        parity = parity ^ 1;
                    }
                }
                if(parity & 1){
                    totalDependent += freq[product];
                }
                else {
                    totalDependent -= freq[product];
                }
            }

            if(mpp.find(num) != mpp.end()){
                if(num == 1) score = max(score, 1LL);
                else score = max(score, num - (totalDependent - 1));
            }
            else if(num <= maxVal){
                if(num == 1){
                    score = max(score, 0LL);
                }
                else
                {   
                    score = max(score, num - max(1LL,(totalDependent)));
                }
                
            }
        }
        return score;

    }
};