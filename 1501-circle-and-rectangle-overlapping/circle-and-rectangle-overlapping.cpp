class Solution {
public:
    int find_nearest(int x1,int x2,int xCenter){
        int h = max(x1,x2);
        int l = min(x1,x2);
        if(xCenter<l){
            return l;
        }
        else if(xCenter>=l && xCenter<=h){
            return xCenter;
        }
        else{
            return h;
        }
    }
    int distance(int x1,int y1,int x2,int y2){
        int x = abs(x1-x2);
        int y = abs(y1-y2);
        int ans = x*x+y*y;
        return ans;
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // nearest point on rectange to circle
        int x = find_nearest(x1,x2,xCenter);
        int y = find_nearest(y1,y2,yCenter);
        int d = distance(x,y,xCenter,yCenter);
        return d<=radius*radius;

    }
};