#ifndef DESIGN_PATTERNS_BUILDER_H
#define DESIGN_PATTERNS_BUILDER_H

#include <iostream>
#include <string>

using namespace std;

class house
{
public:
    void setDoor(string door)
    {
        this->m_door = door;
    }

    void setWall(string wall)
    {
        this->m_wall = wall;
    }
    void setWindow(string window)
    {
        this->m_window = window;
    }

    string getDoor( )
    {
        cout << m_door << endl;
        return this->m_door ;
    }

    string getWall()
    {
        cout << m_wall << endl;
        return this->m_wall;
    }
    string getWindow()
    {
        cout << m_window << endl;
        return m_window;
    }

private:
    string	m_door;
    string	m_wall;
    string	m_window;
};


class builder
{
public:
    virtual void make_wall() = 0;
    virtual void make_door() = 0;
    virtual void make_window() = 0;
    virtual house *get_house() = 0;
};

class flat_builder : public builder
{
public:
    flat_builder()
    {
        _house = new house();
    }
    void make_wall() override
    {
        _house->setWall("flat_wall");
    }
    void make_door() override
    {
        _house->setDoor("flat_door");
    }
    void make_window() override
    {
        _house->setWall("flat_window");
    }
    house *get_house() override
    {
        return _house;
    }
private:
    house *_house;
};

class villa_builder : public builder
{
public:
    villa_builder()
    {
        _house = new house();
    }
    void make_wall() override
    {
        _house->setWall("villa_wall");
    }
    void make_door() override
    {
        _house->setDoor("villa_door");
    }
    void make_window() override
    {
        _house->setWall("villa_window");
    }
    house *get_house() override
    {
        return _house;
    }
private:
    house *_house;
};

class director
{
public:
    director()
    {
    }
    void set_builder(builder *buil)
    {
        _builder = buil;
    }
    void construct()
    {
        _builder->make_wall();
        _builder->make_door();
        _builder->make_window();
    }
private:
    builder *_builder;
};
#endif //DESIGN_PATTERNS_BUILDER_H
