#include <iostream>
#include <string>
struct  DateNow
{
    int day, month, year;
    DateNow(int &dayval, int monthval, int yearval)
        :day{dayval}, month{monthval}, year{yearval}
    {
    }
};
struct DateTomorow
{
    DateNow Now;
    const std::string MonthName [12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    DateTomorow(const DateNow Value)
        : Now{Value}
    {
        UpdateDate();
    }
    bool Kabisat(){
        if(Now.year % 4 == 0) return true;
        return false;
    }
    void UpdateDate(){
        if (Now.month == 2){
            if(Now.year % 4 == 0 && Now.day >= 29){
                Now.month++;
                Now.day = 1;
            }else if (Now.day >= 28){
                Now.month++;
                Now.day = 1;
            }else Now.day++;
        }
        else if (Now.month == 2 || Now.month == 4 || Now.month == 6 || Now.month == 9 || Now.month == 11){
            if(Now.day >= 30){
                Now.day = 1;
                Now.month++;
            }else Now.day++;
        }
        else {
            
            if(Now.day == 31 && Now.month != 12){
                Now.day = 1;
                Now.month++;
            }else if(Now.month == 12){
                Now.day = 1;
                Now.month = 1;
                Now.year++;
            }else Now.day++;
        }
    }
    void Display(){
        std::cout << Now.day << " " << MonthName[Now.month - 1] << " " << Now.year;
    }

};

bool LoopProgam(){
    bool Loop;
    do{
        Loop = false;
        std::string option;
        std::cout << "\n\napakah ingin mengulang progam (y/t)";
        std::cin >> option;
        if (option == "Y" || option == "y"){
            return true;
        }else if (option == "T" || option == "t"){
            return false;
        }else Loop = true;
    }while(Loop);
  return false;  
}
int main(){
    bool Loop;
    do{
        Loop = false;
        std::string str [3];
        int Value [3];
        std::cout << "Masukkan Tanggal Hari ini (dd mm yy) : ";
        std::cin >> str[0] >> str[1] >> str[2];
        for(int i = 0; i < 3; i++){
            try {
            Value[i] = std::stoi(str[i]);
            } catch (std::invalid_argument& e) {
                std::cout << "\ntidak sesuai format" << std::endl;
                Loop = true;
                break;
            }
        }
        if (Loop) continue;
        if (Value[0] > 31 || Value[0] < 0 || Value[1] > 12 || Value[1] < 0){
            Loop = false;
            continue;
        } 
        DateTomorow Tomorow (DateNow(Value[0],Value[1], Value[2]));
        Tomorow.Display();
        Loop = LoopProgam();

    }while(Loop);
}