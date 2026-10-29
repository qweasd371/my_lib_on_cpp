#ifndef MY_LIB_BIGINT_HPP
#define MY_LIB_BIGINT_HPP
#include "my_vector.hpp"

namespace my_lib {
    class bigint {
    private:
        my_vector<unsigned short>* data;
        bool is_negative = false;
    public:
        bigint(long long int value = 0) {
            data = new my_vector<unsigned short>();
            std::string tamp = std::to_string(value);
            for (const unsigned char c: tamp) {
                if (c == '-') {
                    is_negative = true;
                } else {
                    data->push_back(static_cast<unsigned short>(c)-static_cast<unsigned short>('0'));
                }
            }
            data->revers();
        }

        ~bigint() {
            delete data;
        }
        void print_data(const std::string& sep = {" "}) {
            data->print(sep);
        }
        bigint operator+(bigint& value) {
            size_t index = 0;
            short carry = 0;
            bigint result{};
            unsigned short temp = 0;
            while (true) {
                
            }
        }



        unsigned short& operator[](size_t index) {
            return (*data)[index];
        }
        const unsigned short& operator[](size_t index) const {
            return (*data)[index];
        }
        my_vector<unsigned short>* get_data() {
            return data;
        }
    };
}

#endif
