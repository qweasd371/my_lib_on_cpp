#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP
#include <initializer_list>
#include <iostream>
#include <format>
#include <utility>
#include "my_exeptions.hpp"

namespace my_lib {
	template <typename T>
	class my_vector {
	private:
		T* data = nullptr;
		size_t size = 0;
	public:
		my_vector<T>& get_data() {
			return &this;
		}
		size_t get_size() {
			return size;
		}
		my_vector(std::initializer_list<T> list)  {
			for (T element : list) {
				push_back(element);
			}
		}
		~my_vector () {
			free(data);
		}

		void push_back(T value) {
			void* new_data_maybe_null = realloc(data, sizeof(T)*(++size));

			if (new_data_maybe_null == nullptr) {
				throw my_expt::memory_error("realloc return NULL");
			}
			T* new_data = static_cast<T*>(new_data_maybe_null);
			new_data[size-1]  = value;
			data = new_data;
		}
		T pop_back() {
			T tample = data[size-1];
			void* new_data_maybe_null = realloc(data, sizeof(T)*(--size));

			if (new_data_maybe_null == nullptr) {
				throw my_expt::memory_error("realloc return NULL");
			}
			T* new_data = static_cast<T*>(new_data_maybe_null);
			data = new_data;
			return tample;
		}

		T* begin() {
			return &data[0];
		}
		T* end() {
			return &data[size];
		}
		void map(T(*func)(T)){
			for (T* i = begin(); i != end(); ++i){
				*i = func(*i);
			}
		}
		void print() {
			for (T* i = begin(); i != end(); ++i){
				std::cout << *i << " ";
			}
			std::cout << "\n";
		}
		T& operator[](size_t index) {
			if (index >= size) {
				throw my_expt::index_error(std::format("Index out of range (index = {})", index));
			}
			return data[index];
		}
		const T& operator[](size_t index) const {
			if (index >= size) {
				throw my_expt::index_error(std::format("Index out of range (index = {})", index));
			}
			return data[index];
		}

	};
}
#endif