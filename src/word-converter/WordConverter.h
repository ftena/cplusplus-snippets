#ifndef WORDCONVERTER_H
#define WORDCONVERTER_H

#include <map>
#include <string>

class WordConverter
{
    public:
        WordConverter();
        ~WordConverter();
    private:
        std::map<std::string, double> textAsNumbers;
};

#endif // WORDCONVERTER_H
