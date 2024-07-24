#include "data.hpp"


std::ostream& operator<<(std::ostream& os, const Data& data){
    const time_t t = data.get_full_date();

    tm *ltm = localtime(&t);
    os << ltm->tm_hour << ":" << ltm->tm_min << " ";
    os << ltm->tm_mday << "/" << 1+ltm->tm_mon << "/" << 1900+ltm->tm_year;

    return os;
}