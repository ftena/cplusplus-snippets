#include <iostream>
#include <algorithm>
#include <sstream>
#include <regex>

#include "WordConverter.h"

const char WordConverter::hyphen = '-';
const char WordConverter::whitespace = ' ';
const char WordConverter::dollar = '$';
const int WordConverter::onehundred = 100;
const int WordConverter::onethousand = 1000;

WordConverter::WordConverter(const std::string &input)
{
    inputString = input;
    formattedString = input;

    textAsNumbers =
    {{"one",1},
     {"two",2},
     {"three",3},
     {"four",4},
     {"five",5},
     {"six",6},
     {"seven",7},
     {"eight",8},
     {"nine",9},
     {"ten",10},
     {"eleven",11},
     {"twelve",12},
     {"thirteen",13},
     {"fourteen",14},
     {"fifteen",15},
     {"sixteen",16},
     {"seventeen",17},
     {"eighteen",18},
     {"nineteen",19},
     {"twenty",20},
     {"thirty",30},
     {"forty",40},
     {"fifty",50},
     {"sixty",60},
     {"seventy",70},
     {"eighty",80},
     {"ninety",90},
     {"hundred",100},
     {"thousand",1000},
     {"million",1000000},
     {"billion",1000000000}};
}

WordConverter::~WordConverter()
{
}

std::string WordConverter::process()
{
    std::vector<std::string> out;
    double numberValue;

    extractNumber(out);
    numberValue = getNumberValue(out);
    return getFormattedString(numberValue);
}

void WordConverter::extractNumber(std::vector<std::string> &out)
{
    std::string in = inputString;
    std::string formatted;
    in.erase(in.end()-1); // erase the last dot

    // replace hyphen (-) character if they are used
    std::replace(in.begin(), in.end(), hyphen, whitespace);

    std::stringstream stream(in); // get the string as a stream

    formatted = in;

    std::string str;
    while (std::getline(stream, str, ' '))
    {
        if(textAsNumbers.find(str) != textAsNumbers.end())
        {
            out.push_back(str);

            std::regex e(str);
            formatted = std::regex_replace(formatted,
                                           e,
                                           std::string(1, dollar));
        }
    }

    formattedString = formatted;
}

double WordConverter::getNumberValue(const std::vector<std::string> &input)
{
    double totalValue = 0;
    double accumulated = 0;

    for (auto &text: input) {
        double currentValue = textAsNumbers[text];

        if (currentValue >= onethousand)
        {
            totalValue += accumulated * currentValue;
            accumulated = 0;
        }
        else if (currentValue >= onehundred)
        {
            accumulated *= currentValue;
        }
        else accumulated += currentValue;
    }

    return totalValue + accumulated;
}

std::string WordConverter::getFormattedString(double input)
{
    std::string result;
    std::regex e("(\\$.*\\$)|(\\$)");
    std::regex_replace(std::back_inserter(result),
                       formattedString.begin(),
                       formattedString.end(),
                       e,
                       std::to_string(long(input)));
    return result;
}
