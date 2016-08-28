#pragma once

#include <string.h>
#include <utility>


namespace trivial
{
class String{
private:
    char* _data;

public:
    String()
    :_data(new char[1])
    {
        *_data='\0';
    }
    
    String(const char* str)
    :_data(new char[strlen(str)+1])
    {
        strcpy(_data, str);
    }

    String(String str)
    :_data(new char[str.size()+1])
    {
        strcpy(_data, str.c_str());
    }

    ~String()
    {
        delete _data;
    }
    
    String& operator=(String str) //pass by value
    {
        swap(str);
        return *this;
    }

    size_t size() const
    {
        return strlen(_data);
    }

    const char* c_str() const
    {
        return _data;
    }
    
    void swap(String& str)
    {
        std::swap(_data, str.c_str());
    }
    
};


}