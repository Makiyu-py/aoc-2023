#include <iostream>
#include <vector>
#include "../utils.hpp"

using namespace std;

int main()
{
    string input_text = aoc_utils::readFile("../inputs/01.txt");
    vector<string> calibration_doc = aoc_utils::split_string(input_text, "\n");

    vector<int> calibration_values;

    for (string line : calibration_doc)
    {
        vector<char> line_numbers;
        for (char& ch : line)
        {
            if (isdigit(ch))
            {
                line_numbers.push_back(ch);
            }
        }

        string value;
        value += line_numbers.front();
        value += line_numbers.back();

        calibration_values.push_back(stoi(value));
    }

    int sum_of_values = 0;

    for (int val : calibration_values)
        sum_of_values += val;
    
    cout << sum_of_values << endl;
}