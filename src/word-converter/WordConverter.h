#ifndef WORDCONVERTER_H
#define WORDCONVERTER_H

#include <map>
#include <string>
#include <vector>

class WordConverter
{
public:
    WordConverter(const std::string &inputString);
    ~WordConverter();
    void getNumbersFromString(std::vector<std::string> &out);
    double getValue(const std::vector<std::string> &inputString);
private:
    std::string originalInputString; // the original string
    std::string formattedOutputString; // the string with the right format
    std::map<std::string, double> textAsNumbers; // map with text and its value as number
    std::string regexpression; // it stores the regex to locate the number in English

    // some static characters and values
    static const char hyphen;
    static const char whitespace;
    static const char dollar;
    static const int onehundred;
    static const int onethousand;
};

#endif // WORDCONVERTER_H
