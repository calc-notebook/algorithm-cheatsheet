#include <iostream>

using namespace std;

const string HAAB_MONTH[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu"};
const string HOLLY_MONTH[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int getHaabMonth(const string& month){
    for(int idx=0;idx<19;idx++) if(HAAB_MONTH[idx]==month) return idx;
    return -1;
}

long long calDaysFromBegin(int year, string _month, int day){
    int month=getHaabMonth(_month);

}

