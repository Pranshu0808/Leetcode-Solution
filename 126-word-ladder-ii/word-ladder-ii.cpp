class Solution{
public:

    void dfs(string word, string beginWord,
             unordered_map<string, vector<string>>& parent,
             vector<string>& path,
             vector<vector<string>>& ans){

        if(word == beginWord){
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for(auto p : parent[word]){
            path.push_back(p);
            dfs(p, beginWord, parent, path, ans);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                         vector<string>& wordList){

        unordered_set<string> st(wordList.begin(), wordList.end());

        vector<vector<string>> ans;

        if(st.find(endWord) == st.end()){
            return ans;
        }

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, int> level;
        level[beginWord] = 0;

        unordered_map<string, vector<string>> parent;

        int shortest = -1;

        while(!q.empty()){
            string current = q.front();
            q.pop();

            int currLevel = level[current];

            // Don't explore paths longer than shortest path
            if(shortest != -1 && currLevel >= shortest){
                continue;
            }

            string word = current;

            for(int i = 0; i < word.size(); i++){
                char original = word[i];

                for(char c = 'a'; c <= 'z'; c++){
                    if(c == original) continue;

                    word[i] = c;

                    if(st.count(word)){

                        // First time reaching this word
                        if(level.find(word) == level.end()){
                            level[word] = currLevel + 1;
                            q.push(word);
                            parent[word].push_back(current);

                            if(word == endWord){
                                shortest = currLevel + 1;
                            }
                        }

                        // Same shortest level reached again
                        else if(level[word] == currLevel + 1){
                            parent[word].push_back(current);
                        }
                    }
                }

                word[i] = original;
            }
        }

        if(level.find(endWord) == level.end()){
            return ans;
        }

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, parent, path, ans);

        return ans;
    }
};