
class RandomizedSet {
public:
    vector<int> list;
    unordered_map<int, int> map;
    
    RandomizedSet() {}
    
    bool insert(int val) {
        if (map.count(val)) return false;
        list.push_back(val);
        map[val] = list.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!map.count(val)) return false;
        int index = map[val];
        int lastElement = list.back();
        list[index] = lastElement;
        map[lastElement] = index;
        

        list.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % list.size();
        return list[randomIndex];
    }
};