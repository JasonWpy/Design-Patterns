#ifndef DESIGN_PATTERNS_PROTOTYPE_H
#define DESIGN_PATTERNS_PROTOTYPE_H

#include <iostream>
#include <string>

class person
{
public:
    virtual person *clone() = 0;
    virtual void print_out() = 0;

};

class java_programmer : public person
{
public:
    java_programmer()
    {
        this->m_name = "";
        this->m_age = 0;
        m_resume = NULL;
    }
    java_programmer(std::string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
        m_resume = NULL;
    }

    ~java_programmer()
    {
        if ( m_resume != NULL )
        {
            free(m_resume);
            m_resume = NULL;
        }
    }
    virtual person *clone() override
    {
        java_programmer *p = new java_programmer();
        *p = *this;
        return p;
    }

    void set_resume(char *resume)
    {
        m_resume = new char[strlen(resume) + 1];
        strcpy(m_resume, resume);
    }

    virtual void print_out() override
    {
        std::cout << "m_name:" << m_name << "\t" << "m_age:" << m_age << std::endl;
        if ( m_resume != NULL )
        {
            std::cout << m_resume << std::endl;
        }
    }
protected:
private:
    std::string m_name;
    int m_age;
    char *m_resume;
};

#endif //DESIGN_PATTERNS_PROTOTYPE_H