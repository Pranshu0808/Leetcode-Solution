class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = {
            "Thursday","Friday", "Saturday", "Sunday",
            "Monday", "Tuesday", "Wednesday"
        };
        
        vector<int> monthDays = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int totalDays = 0;
        
        for (int y = 1971; y < year; y++) {
            totalDays += 365;
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                totalDays += 1;
        }
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            monthDays[1] = 29;
        
        for (int m = 0; m < month - 1; m++)
            totalDays += monthDays[m];
        
        totalDays += day;
        
        return days[totalDays % 7];
    }
};