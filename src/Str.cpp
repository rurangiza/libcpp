// The Str class is similar to std::string
// but with additional methods like:
// endswith(), startswith(), split(), strip()

#include "Str.hpp"

/*******************************************************************************
 * CONSTRUCTORS                                                                *
*******************************************************************************/

// Default Constructor
Str::Str() : _data("") {}
// Parameterized Constructor (std::string)
Str::Str(std::string s) : _data(s) {}
// Parameterized Constructor (char*)
Str::Str(char* str) : _data(str) {}
// Parameterized Constructor (const char*)
Str::Str(const char* str) : _data(str) {}
// Parameterized Constructor (int)
Str::Str(int num)
{
    std::stringstream ss;
    ss << num;
    this->_data = ss.str();
}
// Parameterized Constructor (float)
Str::Str(float num)
{
    std::stringstream ss;
    ss << num;
    this->_data = ss.str();
}
// Parameterized Constructor (char)
Str::Str(char c) { _data = c; }
// Parameterized Constructor (bool)
Str::Str(bool value) {
    _data = value ? "true" : "false";
}

// Copy Constructor
Str::Str(const Str& rhs)
{
    this->_data = rhs.getData();
}
// Destructor
Str::~Str() {}

/*******************************************************************************
 * OPERATOR OVERLOADING                                                        *
*******************************************************************************/

Str&
Str::operator= (std::string& rhs)
{
    _data = rhs;
    return *this;
}

Str&
Str::operator= (const char* rhs)
{
    _data = rhs;
    return *this;
}

Str&
Str::operator= (Str& rhs)
{
    _data = rhs.getData();
    return *this;
}

// Str&
// Str::operator+ (std::string& rhs)
// {
//     return ;
// }

bool
Str::operator== (std::string& rhs)
{
    if (rhs == _data)
        return true;
    return false;
}

std::ostream&
operator<< (std::ostream& os, Str& rhs)
{
    os << rhs.getData();
    return os;
}

std::ostream&
operator<< (std::ostream& os, const Str& rhs)
{
    os << rhs.getData();
    return os;
}

// When the argument is a temporary object (rvalue)
// std::ostream&
// Str::operator<< (std::ostream& os, const Str& rhs)
// {
//     os << rhs.getData();
//         return os;
// }

// MEMBER FUNCTIONS

size_t Str::size() const { return _data.size(); }

bool Str::endswith(std::string keyword)
{
    if (this->_data.size() == 0)
        return false;
    size_t found = _data.find(keyword);
    if (found == std::string::npos )
        return false;
    if (found + keyword.size() != this->_data.size())
        return false;
    return true;
}
bool Str::startswith()
{
    return false;
}

// ACCESSORS
std::string Str::getData() const
{
    return _data;
}