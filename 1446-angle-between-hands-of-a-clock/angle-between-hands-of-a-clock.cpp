class Solution {
public:
    double angleClock(int hour, int minutes){
        int g = hour*60 + minutes;
        double x = g*1.0/60;
        
        if(floor(x) == 12){
            x = x - 12;
        }
        x = x*30;
        double y = minutes*6;
        if(abs(y-x) > 180){
            return 360-abs(y-x);
        }
        return abs(y-x);

    }
};