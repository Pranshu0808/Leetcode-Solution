class Solution {
public:
    string arrangeWords(string text) {
        text = text + " ";
        vector<pair<int , string>> vv;
        string s;
        int idx = 0;   
        for(int i = 0; i < text.size(); ++i){
            if (text[i] == ' ') {
                if (!s.empty()){
                    vv.push_back({(int)s.size(), s});
                    s = "";
                }
            } 
            else{
                s = s + text[i];
            }
        }
        stable_sort(vv.begin(), vv.end(), [](auto &a, auto &b){
            return a.first < b.first;
        });

        string sd;
        for (int i = 0; i < vv.size(); ++i){
            if (i) sd += " ";
            sd += vv[i].second;
        }
        transform(sd.begin(), sd.end(), sd.begin(), ::tolower);

        if(!sd.empty()){ 
        sd[0] = toupper(sd[0]);
        }

        return sd;
    }
};
