#ifndef DESIGN_PATTERNS_BRIDGE_H
#define DESIGN_PATTERNS_BRIDGE_H

#include <iostream>

class engine
{
public:
    virtual std::string install_engine() = 0;
};

class e4400cc : public engine
{
public:
    std::string install_engine() override
    {
        return "install_e4400cc";
    }
};

class e4500cc : public engine
{
public:
    std::string install_engine() override
    {
        return "install_e4500cc";
    }
};

class car
{
public:
    car(engine *en) : _en(en)
    {
    }

    virtual std::string install_engine() = 0;
protected:
    engine *_en;
};

class bmw5 : public car
{
public:
    bmw5(engine *en) : car(en)
    {
    }
    std::string install_engine() override
    {
        return _en->install_engine();
    }
};

class bmw6 : public car
{
public:
    bmw6(engine *en) : car(en)
    {
    }
    std::string install_engine() override
    {
        return _en->install_engine();
    }
};


#endif //DESIGN_PATTERNS_BRIDGE_H
