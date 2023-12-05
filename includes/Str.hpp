// The Str class is similar to std::string
// but with additional methods like:
// endswith(), startswith(), split(), strip()

#ifndef STR_HPP
    #define STR_HPP

    #include <iostream>
    #include <string>
    #include <sstream>

    class Str {
        private:
            std::string _data;

        public:
            Str();
            Str(std::string s);
            Str(char* str);
            Str(const char* str);
            Str(int num);
            Str(float num);
            Str(char c);
            Str(bool value);

            Str(const Str& rhs);

            ~Str();

            /**
             * Operator Overloading
             */
            // friend std::ostream& operator<<(std::ostream& os, const Str& rhs);
            
            Str& operator= (Str& rhs);
            Str& operator= (std::string& rhs);
            Str& operator= (const char* rhs);

            bool operator== (Str& rhs);
            bool operator== (std::string& rhs);
            bool operator== (const char* rhs);

            Str& operator+ (std::string& rhs);
            // Str& operator+= (std::string& rhs);
            // Str& operator- (std::string& rhs);
            // Str& operator-= (std::string& rhs);

            /**
             * Capacity
             */
            size_t size() const;

            /**
             * Getters
             */
            std::string getData() const;

            // custom methods
            bool endswith(std::string keyword);
            bool startswith();
            // Str lower()
            // Str upper()
            // Str title()
            // Str* split()
            // size_t find()
            // void strip()

            // CHECKERS
            // bool isalnum()
            // bool isalpha()
            // bool isdigit()

    };

    std::ostream& operator<<(std::ostream& os, Str& rhs);
    std::ostream& operator<<(std::ostream& os, const Str& rhs);

#endif