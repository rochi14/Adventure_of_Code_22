#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
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
        do{  //read data from file object and put it into string.
            if (!tp.empty()) {
                calories_current = calories_current + stoi(tp);
            }else {
                calories.push_back(calories_current);
                if (calories_max < calories_current) {
                    calories_max = calories_current;
                    calories_max_index = counter;
                }
                calories_current=0;
                counter++;
            }   //print the data of the string
        } while (getline(newfile, tp));
    }
    calories.push_back(calories_current); //
    std::sort(calories.begin(), calories.end(), greater <>());
    std::cout << "Printing calories of elves \n";
    for (int i = 0; i < calories.size(); i++) {
        std::cout << calories[i] << "\n";
    }
    std::cout << " Max Calories :: " << calories_max << "\n";
    std::cout << " Elf with Max Calories :: " << (calories_max_index + 1) << "\n";
    std::cout << "Sum of 3 highest Calories :: " << (calories[0] + calories[1] + calories[2]) << "\n";
	std::cin.get();
	return 0;
}