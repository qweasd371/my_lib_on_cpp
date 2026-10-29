#ifndef MY_LIB_MY_EXEPTIONS_HPP
#define MY_LIB_MY_EXEPTIONS_HPP

#include <exception>
#include <string>
namespace my_expt{
    class index_error : public std::exception {
    public:
        index_error(std::string  message) : message{std::move(message)} {}
        const char* what() const noexcept override {
            return message.c_str();
        }
    private:
        std::string message;
    };

    class memory_error : public std::exception {
    public:
        memory_error(std::string message) : message{std::move(message)} {}
        const char* what() const noexcept override {
            return message.c_str();
        }
    private:
        std::string message;
    };
    
    class empty_vector_error : public std::exception {
    public:
    	empty_vector_error(std::string message) : message{std::move(message)} {}
    	const char* what() const noexcept override {
    		return message.c_str();
    	}
    private:
    	std::string message;
    };
}

#endif
