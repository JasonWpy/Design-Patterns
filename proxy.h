#ifndef DESIGN_PATTERNS_PROXY_H
#define DESIGN_PATTERNS_PROXY_H

#include <iostream>
#include <string>
class subject
{
public:
    virtual std::string sell_book() = 0;
};

class real_subject_book : public subject
{
public:
    std::string sell_book() override
    {
        return "sell_book";
    }
};

class dangdang_proxy : public subject
{
public:
    std::string sell_book() override
    {
        real_subject_book *rsb = new real_subject_book();
        cut();
        return rsb->sell_book();
    }

public:
    std::string cut()
    {
        return "cut";
    }

};

#endif //DESIGN_PATTERNS_PROXY_H
