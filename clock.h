#ifndef PTIME_H
#define PTIME_H

#include <string>

using namespace std;

class defOClock
{
private:
    int sec;
    int min;
    int hour;
    bool clockActive;

public:
    defOClock();
    defOClock(int h, int m, int s);
    defOClock(int s);

    void setClockActive(bool active);
    void setTime(int h, int min, int s);
    void setTime(int s);

    void clearTime();
    void addSec();
    int toSec();
		string toString();

    static string toString(int sec);


};

#endif // PTIME_H
