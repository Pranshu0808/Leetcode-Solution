class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char,int> freq;
        for(char c : word) freq[c]++;
        
        unordered_map<int,int> countFreq;
        for(auto &p : freq) countFreq[p.second]++;
        
        if(countFreq.size() == 1) {
            auto it = countFreq.begin();
            return it->first == 1 || it->second == 1;
        }
        else if(countFreq.size() == 2) {
            auto it = countFreq.begin();
            int f1 = it->first, c1 = it->second;
            it++;
            int f2 = it->first, c2 = it->second;
            
            if((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)) return true;
            if((abs(f1 - f2) == 1) && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1))) return true;
        }
        return false;
    }
};
