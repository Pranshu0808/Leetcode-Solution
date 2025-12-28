class FrontMiddleBackQueue {
public:
    vector<int>v;
    int size=0;

    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        v.insert(v.begin(),val);
        size++;
    }
    
    void pushMiddle(int val) {
        int mid=(size)/2;
        v.push_back(0);
        for(int i=v.size()-1;i>mid;i--){   
            v[i]=v[i-1];
        }
        v[mid]=val;
        size++;
    }
    
    void pushBack(int val) {
        v.push_back(val);
        size++;
    }
    
    int popFront() {
        if(v.size()<1) return -1 ;
        int val=v.front();
        v.erase(v.begin());
        size--;
        return val;
    }
    
    int popMiddle() {
        if(v.size()<1) return -1;
        int mid=(size-1)/2;
        int val=v[mid];
        v.erase(v.begin()+mid);
        size--;
        return val;
    }
    
    int popBack() {
        if(v.size()<1) return -1;
        int val=v.back();
        v.erase(v.end()-1);
        size--;
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */