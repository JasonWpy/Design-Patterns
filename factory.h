#ifndef DESIGN_PATTERNS_FACTORY_H
#define DESIGN_PATTERNS_FACTORY_H

#include <stdlib.h>
#include <string>

/*
 * 解耦，添加新的类型不需要修改原有代码
 * 添加一个新的工厂，继承abst_factory, create 新的对象
 */

    class fruit
{
public:
    virtual std::string say_name() = 0;
};

class banana : public fruit
{
public:
    std::string say_name() override
    {
        return "banana";
    }
};

class apple : public fruit
{
public:
    std::string say_name() override
    {
        return "apple";
    }
};

class abst_factory
{
public:
    virtual fruit *create() = 0;
};

class banana_factory : public abst_factory
{
public:
    fruit *create() override
    {
        return new banana();
    }
};

class apple_factory : public abst_factory
{
public:
    fruit *create() override
    {
        return new apple();
    }
};
#endif //DESIGN_PATTERNS_FACTORY_H
