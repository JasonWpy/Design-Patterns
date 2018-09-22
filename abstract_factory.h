#ifndef DESIGN_PATTERNS_ABSTRUCE_FACTORY_H
#define DESIGN_PATTERNS_ABSTRUCE_FACTORY_H

#include <stdio.h>
#include <string>

/*
 * 工厂模式只能生产一个产品。
 * 抽象工厂可以一下生产一个产品族
 */

class abstract_fruit
{
public:
    virtual std::string say_name() = 0;
};

class abstract_factory
{
public:
    virtual abstract_fruit *create_banana() = 0;
    virtual abstract_fruit *create_apple() = 0;
};

class north_banana : public abstract_fruit
{
public:
    std::string say_name() override
    {
        return "north_banana";
    }
};

class north_apple : public abstract_fruit
{
public:
    std::string say_name() override
    {
        return "north_apple";
    }
};

class south_banana : public abstract_fruit
{
public:
    std::string say_name() override
    {
        return "south_banana";
    }
};

class south_apple : public abstract_fruit
{
public:
    std::string say_name() override
    {
        return "south_apple";
    }
};

class north_factory : public abstract_factory
{
public:
    abstract_fruit *create_banana() override
    {
        return new north_banana();
    }
    abstract_fruit *create_apple() override
    {
        return new north_apple();
    }
};

class south_factory : public abstract_factory
{
public:
    abstract_fruit *create_banana() override
    {
        return new south_banana();
    }
    abstract_fruit *create_apple() override
    {
        return new south_apple();
    }
};

#endif //DESIGN_PATTERNS_ABSTRUCE_FACTORY_H
