#include <iostream>
#include<mutex>

class lazy_singleton
{
private:
    lazy_singleton()
    {
        printf("lazy_singleton construct\n");
    }

public:
    static lazy_singleton *get_instance()
    {
        if ( _single == NULL )  // double check
        {
            std::lock_guard<std::mutex> lk(_mtx);
            if ( _single == NULL )
            {
                _single = new lazy_singleton();
            }
        }
        return _single;
    }

    static void free_instance()
    {
        if ( _single != NULL )
        {
            delete _single;
            _single = NULL;
        }
    }


private:
    static std::mutex _mtx;
    static lazy_singleton *_single;
};
std::mutex lazy_singleton::_mtx;
lazy_singleton *lazy_singleton::_single = NULL;

class eager_singleton
{
private:
    eager_singleton()
    {
        printf("eager_singleton construct\n");
    }

public:
    static eager_singleton *get_instance()
    {
        return _single;
    }

    static void free_instance()
    {
        if ( _single != NULL )
        {
            delete _single;
            _single = NULL;
        }
    }


private:
    static eager_singleton *_single;
};

eager_singleton *eager_singleton::_single = new eager_singleton();
