#include <chrono>
#include <iostream>

int main() {
    using namespace std::literals;

    auto now = std::chrono::high_resolution_clock::now();
    auto point_time_t = std::chrono::high_resolution_clock::to_time_t(now);

    std::tm *time_tm = std::localtime(&point_time_t);
    int year = time_tm->tm_year + 1900;
    int month = time_tm->tm_mon + 1;
    int day = time_tm->tm_mday;
    int hour = time_tm->tm_hour;
    int min = time_tm->tm_min;
    int sec = time_tm->tm_sec;

    std::cout << "yyyy-mm-dd hh:mm:ss: " << year
                                         << "-"
                                         << month
                                         << "-"
                                         << day 
                                         << "  "
                                         << hour
                                         << ":"
                                         << min 
                                         << ":"
                                         << sec << std::endl;

    // get milliseconds
    auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto fraction = now - seconds;
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(fraction);
    std::cout << "milliseconds: " << milliseconds.count() << '\n';

    char buffer[256] = {};
    std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", std::localtime(&point_time_t));
    std::cout << "another way of printing date: " << buffer << "\n";
}