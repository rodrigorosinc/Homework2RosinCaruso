#include <iostream>
#include <iomanip>
#include <string>

enum constructors {
    default_constructor = 0,
    first_constructor = 1, 
    second_constructor = 2, 
    third_constructor = 3, 
    fourth_constructor = 4
};

class Time {
    private:
    int hours;
    int minutes;
    int seconds;
    std::string am_pm;

    public:
    //Validations
    bool isValidHour(int h) {return (h >= 0 && h <= 12);}
    bool isValidMinute(int m) {return (m >= 0 && m < 60);}
    bool isValidSecond(int s) {return (s >= 0 && s < 60);}
    bool isValidPeriod(std::string period) {return (period == "a.m." || period == "p.m.");}
    // Default constructor
    Time() : hours(0), minutes(0), seconds(0), am_pm("a.m.") {}
    // Constructor with hour
    Time(int h) {
        if (!isValidHour(h)) {throw std::invalid_argument("Invalid hour");}
        hours = h;
        minutes = 0;
        seconds = 0;
        am_pm = "a.m.";
    }
    // Constructor with hour and minute
    Time(int h, int m) {
        if (!isValidHour(h)) {throw std::invalid_argument("Invalid hour");}
        if (!isValidMinute(m)) {throw std::invalid_argument("Invalid minute");}
        hours = h;
        minutes = m;
        seconds = 0;
        am_pm = "a.m.";
    }
    // Constructor with hour, minute and second
    Time(int h, int m, int s) {
        if (!isValidHour(h)) {throw std::invalid_argument("Invalid hour");}
        if (!isValidMinute(m)) {throw std::invalid_argument("Invalid minute");}
        if (!isValidSecond(s)) {throw std::invalid_argument("Invalid second");}
        hours = h;
        minutes = m;
        seconds = s;
        am_pm = "a.m.";
    }
    // Constructor with hour, minute, second and period
    Time(int h, int m, int s, std::string period) {
        if (!isValidMinute(m)) {throw std::invalid_argument("Invalid minute");}
        if (!isValidSecond(s)) {throw std::invalid_argument("Invalid second");}
        if (!isValidPeriod(period)) {throw std::invalid_argument("Invalid period");}
        if (am_pm == "p.m." && h < 12) {throw std::invalid_argument("Invalid hour");}
        if (h >= 24 || h < 0) {throw std::invalid_argument("Invalid hour");}
        hours = h;
        minutes = m;
        seconds = s;
        am_pm = period;
    }

    void readTime() {
        std::cout << "Time: " << std::setw(2) << std::setfill('0') << hours << "h, "
                  << std::setw(2) << std::setfill('0') << minutes << "m, "
                  << std::setw(2) << std::setfill('0') << seconds << "s "
                  << am_pm << std::endl;
    }

    void readTime24hFormat (){
        int h24 = hours;
        if (am_pm == "p.m." && hours != 12) h24 += 12;
        if (am_pm == "a.m." && hours == 12) h24 = 0;
        std::cout << "Time in 24h format: " << std::setw(2) << std::setfill('0') << h24 << "h, "
                  << std::setw(2) << std::setfill('0') << minutes << "m, "
                  << std::setw(2) << std::setfill('0') << seconds << "s" << std::endl;
    }

    // Getters
    int getHours() {return hours;}
    int getMinutes() {return minutes;}
    int getSeconds() {return seconds;}
    std::string getAmPm() {return am_pm;}
    
    // Setters
    void setHours(int h) {
        if (!isValidHour(h)) {throw std::invalid_argument("Invalid hour");}
        hours = h;
    }
    void setMinutes(int m) {
        if (!isValidMinute(m)) {throw std::invalid_argument("Invalid minute");}
        minutes = m;
    }
    void setSeconds(int s) {
        if (!isValidSecond(s)) {throw std::invalid_argument("Invalid second");}
        seconds = s;
    }
    void setAmPm(std::string period) {
        if (!isValidPeriod(period)) {throw std::invalid_argument("Invalid period");}
        am_pm = period;
    }
};


void changeTime(Time& t) {
    bool error = true, change;
    std::cout << std::endl;
    std::cout << "Do you want to change the time? (yes (1) - no (0)): ";
    std::cin >> change;
    if (change) {
        while (error) {
            try {
                error = false;
                int h, m, s;
                std::string period;
                std::cout << "Enter new hour: ";
                std::cin >> h;
                std::cout << "Enter new minute: ";
                std::cin >> m;
                std::cout << "Enter new second: ";
                std::cin >> s;
                std::cout << "Enter new period (a.m./p.m.): ";
                std::cin >> period;
                t.setHours(h); t.setMinutes(m); t.setSeconds(s); t.setAmPm(period);
                std::cout << "Time changed successfully!" << std::endl;
                std::cout << std::endl;
            } catch (std::invalid_argument& e) {
                error = true;
                std::cout << e.what() << std::endl;
            }
        }
        t.readTime();
        t.readTime24hFormat();
    } else {
        std::cout << "Time not changed." << std::endl;
    }
    return;
}


int main (){
    bool error = true;
    while(error){
        try {
            error = false;
            int h, m, s, constructor;
            std::string period;
            std::cout << std::endl;
            std::cout << "Which constructor would you use?" << std::endl;
            std::cout << "0. Default constructor (a.m. default)" << std::endl;
            std::cout << "1. Constructor with hour (a.m. default)" << std::endl;
            std::cout << "2. Constructor with hour and minute (a.m. default)" << std::endl;
            std::cout << "3. Constructor with hour, minute and second (a.m. default)" << std::endl;
            std::cout << "4. Constructor with hour, minute, second and period" << std::endl;
            std::cout << "-> ";
            std::cin >> constructor;
            if (constructor == default_constructor) {
                Time t1;
                t1.readTime();
                t1.readTime24hFormat();
                changeTime(t1);
            } 
            else if (constructor == first_constructor) {
                std::cout << "Enter hour: ";
                std::cin >> h;
                Time t2(h);
                t2.readTime();
                t2.readTime24hFormat();
                changeTime(t2);
            } 
            else if (constructor == second_constructor) {
                std::cout << "Enter hour: ";
                std::cin >> h;
                std::cout << "Enter minute: ";
                std::cin >> m;
                Time t3(h, m);
                t3.readTime();
                t3.readTime24hFormat();
                changeTime(t3);
            } 
            else if (constructor == third_constructor) {
                std::cout << "Enter hour: ";
                std::cin >> h;
                std::cout << "Enter minute: ";
                std::cin >> m;
                std::cout << "Enter second: ";
                std::cin >> s;
                Time t4(h, m, s);
                t4.readTime();
                t4.readTime24hFormat();
                changeTime(t4);
            } 
            else if (constructor == fourth_constructor) {
                std::cout << "Enter hour: ";
                std::cin >> h;
                std::cout << "Enter minute: ";
                std::cin >> m;
                std::cout << "Enter second: ";
                std::cin >> s;
                std::cout << "Enter period (a.m./p.m.): ";
                std::cin >> period;
                Time t5(h, m, s, period);
                t5.readTime();
                t5.readTime24hFormat();
                changeTime(t5);
            } 
            else {
                throw std::invalid_argument("Invalid constructor option");
            }

        } catch (std::invalid_argument& e) {
            std::cout << std::endl;
            error = true;
            std::cout << e.what() << std::endl;
            std::cout << "Please enter valid values." << std::endl;
        }
    }
    return 0;
}
