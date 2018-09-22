#ifndef DESIGN_PATTERNS_SIMPLE_FACTORY_H
#define DESIGN_PATTERNS_SIMPLE_FACTORY_H

#include <stdio.h>
#include <stdlib.h>
/*
 * 不符合开闭原则，高内聚方面做的不好
 * 如果要添加新的类型，需要修改原有的代码，即在factory类的create方法中添加新的类型
 */
class simple_fruit
{
public:
    virtual void get_fruit() = 0;

};

class simple_banana : public simple_fruit
{
public:
    void get_fruit() override
    {
        printf("simple_banana\n");
    }
};

class simple_apple : public simple_fruit
{
public:
    void get_fruit() override
    {
        printf("simple_apple\n");
    }
};

class factory
{
public:
    simple_fruit *create(char *p)
    {
        if ( strcmp(p, "simple_banana") == 0 )
        {
            return new simple_banana();
        }
        else if ( strcmp(p, "simple_apple") == 0 )
        {
            return new simple_apple();
        } else
        {
            printf("not support\n");
        }
        return NULL;
    }
};

#endif //DESIGN_PATTERNS_SIMPLE_FACTORY_H
