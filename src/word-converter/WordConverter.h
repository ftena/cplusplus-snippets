#ifndef WORDCONVERTER_H
#define WORDCONVERTER_H

#include <map>
#include <string>
#include <vector>

class WordConverter
{
public:
    WordConverter();
    ~WordConverter();
    void getNumbersFromString(const std::string &inputString, std::vector<std::string> &out);
    double getValue(const std::vector<std::string> &inputString);
private:
    std::map<std::string, double> textAsNumbers;
    const char hyphen = '-';
    const char whitespace = ' ';
    const int onehundred = 100;
    const int onethousand = 1000;
};

#endif // WORDCONVERTER_H
