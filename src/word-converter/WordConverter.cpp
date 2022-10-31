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

WordConverter::WordConverter(const std::string &inputString)
{
    originalInputString = inputString;
    formattedOutputString = inputString;

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

    // create the regular expression to locate the number in English
    std::string coreRegex = "(";
    
    for (auto const& [key, val] : textAsNumbers)
    {
      coreRegex.append(std::string(key + "|"));
    }
    
    coreRegex.erase(coreRegex.end()-1); // erase the last |
    coreRegex.append(")");

    regexpression.append(coreRegex);
    regexpression.append(".+");
    regexpression.append(coreRegex);
}

WordConverter::~WordConverter()
{
}

void WordConverter::getNumbersFromString(std::vector<std::string> &out)
{
    std::string in = originalInputString;
    in.erase(in.end()-1); // erase the last dot

    // replace hyphen (-) character if they are used
    std::replace(in.begin(), in.end(), hyphen, whitespace);

    std::stringstream stream(in); // get the string as a stream

    std::string str;
    while (std::getline(stream, str, ' ')) {
        if(textAsNumbers.find(str) != textAsNumbers.end()) {
            out.push_back(str);

        }
    }

    std::string result;
    std::regex e(regexpression);
    std::regex_replace (std::back_inserter(result),
            in.begin(),
            in.end(),
            e,
            "$");
    
    std::cout << "here : " << result << std::endl;
}

double WordConverter::getValue(const std::vector<std::string> &inputString)
{
    double totalValue = 0;
    double accumulated = 0;

    for (auto &text: inputString) {
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
