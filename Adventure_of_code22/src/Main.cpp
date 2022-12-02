#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
using namespace std;
class Day1 {
public:
    void task(){
        fstream newfile;
        std::vector<int> calories;
        int calories_current = 0;
        int counter = 0;
        int calories_max = 0;
        int calories_max_index = -1;
        newfile.open("C:/Users/rochi/Documents/GitHub/Adventure_of_Code_22/Adventure_of_code22/input_text.txt", ios::in);  // open a file to perform write operation using file object
        if (newfile.is_open()) {   //checking whether the file is open
            string tp;
            getline(newfile, tp);
            do {  //read data from file object and put it into string.
                if (!tp.empty()) {
                    calories_current = calories_current + stoi(tp);
                }
                else {
                    calories.push_back(calories_current);
                    if (calories_max < calories_current) {
                        calories_max = calories_current;
                        calories_max_index = counter;
                    }
                    calories_current = 0;
                    counter++;
                }   //print the data of the string
            } while (getline(newfile, tp));
        }
        calories.push_back(calories_current); //
        std::sort(calories.begin(), calories.end(), greater <>());
        std::cout << " Max Calories :: " << calories_max << "\n";
        std::cout << " Elf with Max Calories :: " << (calories_max_index + 1) << "\n";
        std::cout << "Sum of 3 highest Calories :: " << (calories[0] + calories[1] + calories[2]) << "\n";
    }
};
class Day2 {

public:
    struct pair_hash {
        inline std::size_t operator()(const std::pair<int, int>& v) const {
            return v.first * 31 + v.second;
        }
    };
    std::unordered_map<char, int> player1;
    std::unordered_map<char, int> player2;
    std::unordered_map<int, int> winpair;
    std::unordered_map<int, int> losspair;
    std::unordered_set<std::pair<int, int>,pair_hash> win;
    void setup() {
        player1.insert({ 'A',1 });
        player1.insert({ 'B',2 });
        player1.insert({ 'C',3 });

        player2.insert({ 'X',1 });
        player2.insert({ 'Y',2 });
        player2.insert({ 'Z',3 });

        win.insert({ 3, 1 });
        win.insert({ 1, 2 });
        win.insert({ 2, 3 });

        winpair.insert({ 3, 1 });
        winpair.insert({ 1, 2 });
        winpair.insert({ 2, 3 });

        losspair.insert({ 1, 3 });
        losspair.insert({ 2, 1 });
        losspair.insert({ 3, 2 });

    }
    int calcWinner(char moveA, char moveB) {
        int movep1 = player1.find(moveA)->second;
        int movep2 = player2.find(moveB)->second;
        if (movep1 == movep2) return (movep2 + 3);
        std::pair<int, int> match = { movep1,movep2 };
        if (win.find(match)==win.end()) {
            return movep2;
        }
        else
        {
            return movep2 + 6;
        }
    }
    int calcPtsBasedOnSuggestion(char moveA, char moveB) {
        int movep1 = player1.find(moveA)->second;
        int movep2 = player2.find(moveB)->second;
        switch (movep2) {
            case 1:
                return 0 + losspair.find(movep1)->second;
                break;
            case 2:
                return movep1 + 3;
                break;
            case 3:
                return 6 + winpair.find(movep1)->second;
                break;
        }
        return 0;
    }
    void task() {       
        setup();
        fstream newfile;
        newfile.open("D:/Personal/Adventure_of_Code_22/Adventure_of_code22/input_text_day2.txt", ios::in);  // open a file to perform write operation using file object
        int result = 0;
        if (newfile.is_open()) {   //checking whether the file is open
            string tp;
            while (getline(newfile, tp)) {
                const char* str = tp.c_str();
                result += calcPtsBasedOnSuggestion(str[0], str[2]);
            }
        }
        std::cout << "Result :: "<< result << "\n";
    }
};
int main() {
    Day2 obj;
    obj.task();
    std::cin.get();
	return 0;
}