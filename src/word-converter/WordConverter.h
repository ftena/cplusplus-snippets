#ifndef WORDCONVERTER_H
#define WORDCONVERTER_H

#include <map>
#include <string>
#include <vector>

class WordConverter
{
public:
    WordConverter(const std::string &input);
    ~WordConverter();
    std::string process();
private:
    void extractNumber(std::vector<std::string> &out);
    double getNumberValue(const std::vector<std::string> &input);
    std::string getFormattedString(double input);

    std::string inputString; // the original string used as input
    std::string formattedString; // the string formatted with the right format
    std::map<std::string, double> textAsNumbers; // map with text and its value as number
    std::string regexpression; // it stores the regex to locate the number in English (TODO)

    // some static characters and values
    static const char hyphen;
    static const char whitespace;
    static const char dollar;
    static const int onehundred;
    static const int onethousand;
};

#endif // WORDCONVERTER_H
