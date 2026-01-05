#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());  
        
        vector<int> v; 

        for (int i = deck.size() - 1; i >= 0; i--) {

            if (!v.empty()) {
                int last = v.back();   
                v.pop_back();         
                v.insert(v.begin(), last); 
            }

      
            v.insert(v.begin(), deck[i]);
        }

        return v;
    }
};
