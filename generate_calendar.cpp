#include <iostream>

int get_feb_days(int year)
{
    if (year % 4 != 0)
        return 28;
    else {
        if (year % 100 == 0 && year % 400 != 0)
            return 28;
        else
            return 29;
        ;
    }
}

void generate_calender(int year, int first_day)
{

    std::cout << "\nCalender for " << year;
    std::string month_name[]{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    // std::string month_name[]{"January", "February"};
    int month_day_count[]{31, get_feb_days(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int month_day{1};
    int month_date{1};

    for (int month_count{0}; std::string month : month_name) {
        std::cout << "\n-- " << month << " " << year << " --" << std::endl;
        int month_days = month_day_count[month_count++];

        // print month
        std::cout
                << "\tMon\tTue\tWed\tThu\tFri\tSat\tSun" << std::endl
                << "\t";
        for (int i = -first_day; i < month_days - 1; ++i) {
            if (i < -1) {
                std::cout << " \t";
            }
            else {
                std::cout << month_date << "\t";
                month_date++;
            }
            if (month_day % 7 == 0)
                std::cout << std::endl
                          << "\t";
            month_day++;
        }
        month_date = 1;
        first_day = (first_day + month_days) % 7;
        month_day = 1;
    }
}

int main()
{

    int year{};
    int first_day{};

    std::cout << "Enter Year: ";
    std::cin >> year;

    std::cout << "Enter First day of year [1: Mon, 2: Tues, ... , 7: Sun]: ";
    std::cin >> first_day;

    generate_calender(year, first_day);
}
