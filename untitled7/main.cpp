#include <iostream>
#include <fstream>

int main() {
    std::string name="0", surname, date;
    int sum;
    while (name!="1") {
        std::cout << "Enter the name and surname of the recipient of the funds"
                     ", the date of issue in the format DD.MM.YYYY, "
                     "the amount of payment in rubles.\nTo exit the program, enter 1."<<std::endl;
        std::cin >> name;
        if (name != "1") {
            std::cin >> surname >> date >> sum;

            if (date.length()==10 && sum > 0 && (std::stoi(date.substr(0, 2)) > 0 &&
                            std::stoi(date.substr(0, 2)) < 31) &&
                (std::stoi(date.substr(3, 2)) > 0 &&
                 std::stoi(date.substr(3, 2)) < 12)) {
                std::ofstream file("..\\statement.txt", std::ios::app);
                file << std::endl << name<<" " << surname<<" " << date<<" " << sum;
                file.close();
            } else
                std::cout << "Err!"<<std::endl;
        }
        else
            return 0;
    }
}
