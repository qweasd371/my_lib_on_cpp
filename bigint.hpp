#ifndef MY_LIB_BIGINT_HPP
#define MY_LIB_BIGINT_HPP
#include "my_vector.hpp"

#define operator_macros(sim) operator sim (bigint& value) { \
			value.extend_to(data->get_size()); \
			extend_to(value.get_size()); \
			bigint result; \
			result.extend_to(data->get_size()); \
			for (size_t index = 0; index < data->get_size(); index++) { \
				result[index] = (*data)[index] sim value[index]; \
			} \
			value.delete_zero(); \
			delete_zero(); \
			result.delete_zero(); \
			return result; \
		} 



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
        
        size_t get_size() {
        	return data->get_size();
        }
        
        void reduce_to(size_t size) {
			if (data->get_size() > size) {
				size -= data->get_size();
				while (size--) {
					data->pop_back();
				}
			}
		}

		void extend_to(size_t size) {
			if (data->get_size() < size) {
				size -= data->get_size();
				while (size--) {
					data->push_back(0);
				}
			}
		}
		
		void delete_zero(){
			while (!data->is_empty() && !data->get_last()) {
				data->pop_back();
			}
		}

		bigint operator_macros(&)
		bigint operator_macros(^)
		bigint operator_macros(|)
		

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
