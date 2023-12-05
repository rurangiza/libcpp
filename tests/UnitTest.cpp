#include "UnitTest.hpp"
using std::cout;
using std::endl;

void
UnitTest::constructors()
{
    std::string s       = "string";
    // char*       schar   = "char*"; // conversion from string literal to 'char *' is deprecated in c++11
    const char* scharc  = "const char*";
    int         n       = 42;

    // Parameterized Constructor (std::string)
    Str a(s);
    // Parameterized Constructor (char*)
    // Str b(schar); // deprecated
    // Parameterized Constructor (const char*)
    Str c(scharc);
    // Parameterized Constructor (int)
    Str d(n);

    Str e("string literal");

    bool boolean = true;

    cout << a << endl
         << c << endl
         << d << ": int" << endl
         << e << endl
         << Str(a) << " (in Str)" << endl
         << Str(s) << " (in string)" << endl
         << Str(scharc) << " (in const char*)" << endl
         << Str("const char*") << " (in const char*)" << endl
         << Str(boolean) << endl
         << Str(false) << endl
         << Str(std::string("hello")) << endl
         ;
}