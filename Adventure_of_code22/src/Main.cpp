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
class Day3 {
public:
    /*int calcValueForString(string sub1, string sub2) {
        //string sub1 = s1.substr(0, s1.length() / 2);
        //string sub2 = s1.substr(s1.length() / 2, s1.length());
        int a1[52] = { 0 }; // first character is blank ;first 26 are lower case and rest upper case 
        int a2[52] = { 0 };
        int i =0, j =0;
        for (i = 0; i < (int)sub1.length(); i++) {
            int ch = (int)sub1[i];
            if ( ch>= 65 && ch <= 90) {
                int diff = ch - 65;
                a1[25 + diff + 1]++;
            }
            if (ch >= 97 && ch <= 122) {
                int diff = ch - 97;
                a1[diff]++;
            }
        }
        for (i = 0; i < (int)sub2.length(); i++) {
            int ch = (int)sub2[i];
            if (ch >= 65 && ch <= 90) {
                int diff = ch - 65;
                a2[25 + diff + 1]++;
            }
            if (ch >= 97 && ch <= 122) {
                int diff = ch - 97;
                a2[diff]++;
            }
        }
        for (i = 0; i < 52; i++) {
            if (a1[i] != 0 && a2[i] != 0) {
                return i+1; 
            }
        }
        return 0;
    }*/
    void checkFreqOfCharacters(string sub1, int (&array)[52]) {
        int i = 0, j = 0;
        for (i = 0; i < (int)sub1.length(); i++) {
            int ch = (int)sub1[i];
            if (ch >= 65 && ch <= 90) {
                int diff = ch - 65;
                array[25 + diff + 1]++;
            }
            if (ch >= 97 && ch <= 122) {
                int diff = ch - 97;
                array[diff]++;
            }
        }
    }
    int calcValueForString(string sub1, string sub2) {
        //string sub1 = s1.substr(0, s1.length() / 2);
        //string sub2 = s1.substr(s1.length() / 2, s1.length());
        int a1[52] = { 0 }; // first character is blank ;first 26 are lower case and rest upper case 
        int a2[52] = { 0 };
        checkFreqOfCharacters(sub1, a1);
        checkFreqOfCharacters(sub2, a2);
        for (int i = 0; i < 52; i++) {
            if (a1[i] != 0 && a2[i] != 0) {
                return i + 1;
            }
        }
        return 0;
    }
    void task() {
        fstream newfile;
        newfile.open("D:/Personal/Adventure_of_Code_22/Adventure_of_code22/input_text_day3.txt", ios::in);  // open a file to perform write operation using file object
        int result = 0;
        if (newfile.is_open()) {   //checking whether the file is open
            string tp;
            while (getline(newfile, tp)) {
                int val = calcValueForString(tp.substr(0,tp.length()/2),tp.substr(tp.length()/2+1));
                result += val;
            }
        }
        std::cout << "Result :: "<< result << "\n";
    }
    int calcValueForString3(string s1, string s2, string s3) {
        int a1[52] = { 0 }; // first character is blank ;first 26 are lower case and rest upper case 
        int a2[52] = { 0 };
        int a3[52] = { 0 };
        checkFreqOfCharacters(s1, a1);
        checkFreqOfCharacters(s2, a2);
        checkFreqOfCharacters(s3, a3);
        for (int i = 0; i < 52; i++) {
            if (a1[i] != 0 && a2[i] != 0 && a3[i] != 0) {
                return i + 1;
            }
        }
        return 0;
    }
    void task2() {
        fstream newfile;
        newfile.open("D:/Personal/Adventure_of_Code_22/Adventure_of_code22/input_text_day3.txt", ios::in);  // open a file to perform write operation using file object
        int result = 0;
        if (newfile.is_open()) {   //checking whether the file is open
            string tp;
            while (getline(newfile, tp)) {
                string s1 = tp;
                getline(newfile, tp);
                string s2 = tp;
                getline(newfile, tp);
                string s3 = tp;
                int val = calcValueForString3(s1,s2,s3);
                result += val;
            }
        }
        std::cout << "Result :: " << result << "\n";
    }
};
int main() {
    Day3 obj;
    obj.task2();
    std::cin.get();
	return 0;
}