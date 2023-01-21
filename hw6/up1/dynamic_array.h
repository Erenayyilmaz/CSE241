#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

namespace dynamic_array_nmspc{ 
template <typename T>
class DynamicArray {
public:
	//template <typename T>
	class Iterator {
	private:
			T* ptr_;
	public:
		Iterator(T* p) : ptr_(p) 
		{

		};

		T& operator*()
		{
			return *ptr_;
		}
		
		T* operator->()
		{
			return ptr_;
		}
		
		Iterator& operator++()
		{
			++ptr_;
			return *this;
		}
		
		Iterator operator++(int)
		{
			Iterator tmp(*this);
			++ptr_;
			return tmp;
		}
		
		Iterator& operator--()
		{
			--ptr_;
			return *this;
		}

		Iterator operator--(int)
		{
			Iterator tmp(*this);
			--ptr_;
			return tmp;
		}


		bool operator==(const Iterator& other) const { return ptr_ == other.ptr_; }

		bool operator!=(const Iterator& other) const { return ptr_ != other.ptr_; }

		long int operator-(const Iterator& other) const { return ptr_ - other.ptr_; }

		bool operator<(const Iterator& other) const { return ptr_ < other.ptr_; }

		bool operator>(const Iterator& other) const { return ptr_ > other.ptr_; }

		bool operator>=(const Iterator& other) const { return ptr_ >= other.ptr_; }

		bool operator<=(const Iterator& other) const { return ptr_ <= other.ptr_; }
	};

	// Const iterator class
	class ConstIterator {
	private:
			T* ptr_;
	public:

	long int operator-(const ConstIterator& other) const { return ptr_ - other.ptr_; }
	bool operator<(const ConstIterator& other) const { return ptr_ < other.ptr_; }
	bool operator>(const ConstIterator& other) const { return ptr_ > other.ptr_; }
	bool operator>=(const ConstIterator& other) const { return ptr_ >= other.ptr_; }
	bool operator<=(const ConstIterator& other) const { return ptr_ <= other.ptr_; }
	bool operator==(const ConstIterator& other) const { return ptr_ == other.ptr_; }
	bool operator!=(const ConstIterator& other) const { return ptr_ != other.ptr_; }

	ConstIterator(const T* p) : ptr_(p) {}

	const T& operator*() const { return *ptr_; }

	const T* operator->() const { return ptr_; }

	ConstIterator& operator++()
	{
		++ptr_;
		return *this;
	}
	ConstIterator operator++(int)
	{
		ConstIterator tmp(*this);
		++ptr_;
		return tmp;
	}
	ConstIterator& operator--()
	{
		--ptr_;
		return *this;
	}
	ConstIterator operator--(int)
	{
		ConstIterator tmp(*this);
		--ptr_;
		return tmp;
	}
};

	T& operator[](size_t index)
	{
		if (index >= _size)
			throw out_of_range("Index out of range");
		return _data[index];
	}

	DynamicArray() : _size(0), _capacity(0), _data(nullptr) {};

	DynamicArray(size_t size) : _size(size), _capacity(size) 
	{
		_data = shared_ptr<T[]>(new T[_capacity],default_delete<T[]>());
	}

	DynamicArray(size_t size, const T& value) : DynamicArray(size)
	{
		for (size_t i = 0; i < _size; ++i)
			_data[i] = value;
	}

	DynamicArray(const DynamicArray& other) : _size(other._size), _capacity(other._capacity), _data(other._data) {}

	DynamicArray(DynamicArray&& other) noexcept : _size(other._size), _capacity(other._capacity), _data(move(other._data))
	{
		other._size = 0;
		other._capacity = 0;
	}

	void add_elem(T elem)
	{
		if (_size == _capacity)
		{
			_capacity *= 2;
			shared_ptr<T[]> new_data(new T[_capacity]);
			for (size_t i = 0; i < _size; i++)
				new_data.get()[i] = _data.get()[i];

			_data = new_data;
		}
		_data.get()[_size] = elem;
		_size++;
	}
	
	~DynamicArray()
	{
		//_data.reset();
	}

	DynamicArray& operator=(const DynamicArray& other)
	{
		if (this == &other)
			return *this;

		shared_ptr<T> new_data(new T[other._size]);
		for (size_t i = 0; i < other._size; i++)
			new_data[i] = other._data[i];

		_data = new_data;
		_size = other._size;
		_capacity = other._capacity;

		return (*this);
	}

	DynamicArray& operator=(DynamicArray&& other) noexcept
	{//move
			_size = other._size;
			_capacity = other._capacity;
			_data = move(other._data);
			other._size = 0;
			other._capacity = 0;
			return *this;
	}

	bool empty() const { return _size == 0; }

	size_t size() const { return _size; }

	void erase(size_t pos)
	{
		if (pos >= _size) 
			throw out_of_range("Index out of range");
		for (size_t i = pos; i < _size - 1; ++i)
			_data[i] = _data[i + 1];
		--_size;
	}

	void clear() { _size = 0; }

	T* begin() { return &_data[0]; }

	const T* begin() const { return &_data[0]; }

	T* end() { return &_data[_size]; }

	const T* end() const { return &_data[_size]; }

	const T* cbegin() const { return &_data[0]; }

	const T* cend() const { return &_data[_size]; }

	size_t capacity() const
	{
		return (_capacity);
	}

//private:
	size_t _size;
	size_t _capacity;
	shared_ptr<T[]> _data;
};


}
/*
		template class DynamicArray<int>;
		template class DynamicArray<double>;
		template class DynamicArray<string>;
		*/
#endif        // DYNAMIC_ARRAY_H