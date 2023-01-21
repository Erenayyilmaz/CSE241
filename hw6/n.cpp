#include <iostream>
#include <memory>	 // for std::shared_ptr
#include <stdexcept> // for std::out_of_range
#include <algorithm>  // for std::find, std::for_each
#include <numeric>  // for std::iota
#include <random>  // for std::default_random_engine
#include <vector>  // for std::vector

template <typename T>
class DynamicArray
{
public:
	// Iterator class
	class Iterator
	{
	public:
		Iterator(std::shared_ptr<T> data, size_t index)
			: data_(data), index_(index) {}

		// Iterator operators
		T &operator*() const { return data_.get()[index_]; }
		T *operator->() const { return &data_.get()[index_]; }
		Iterator &operator++()
		{ // prefix ++
			++index_;
			return *this;
		}
		Iterator operator++(int)
		{ // postfix ++
			Iterator tmp(*this);
			++index_;
			return tmp;
		}
		Iterator &operator--()
		{ // prefix --
			--index_;
			return *this;
		}
		Iterator operator--(int)
		{ // postfix --
			Iterator tmp(*this);
			--index_;
			return tmp;
		}
		Iterator &operator=(const Iterator &other)
		{
			data_ = other.data_;
			index_ = other.index_;
			return *this;
		}
		bool operator==(const Iterator &other) const
		{
			return data_ == other.data_ && index_ == other.index_;
		}
		bool operator!=(const Iterator &other) const { return !(*this == other); }

	private:
		std::shared_ptr<T> data_;
		size_t index_;
	};

	// Constructors
	DynamicArray() : data_(std::make_shared<T[]>(0)), size_(0) {}
	DynamicArray(size_t size) : data_(std::make_shared<T[]>(size)), size_(size) {}
	DynamicArray(const DynamicArray &other)
		: data_(other.data_), size_(other.size_) {}

	// Assignment operator
	DynamicArray &operator=(const DynamicArray &other)
	{
		if (this != &other)
		{
			data_ = other.data_;
			size_ = other.size_;
		}
		return *this;
	}

	// Move constructor and move assignment operator
	DynamicArray(DynamicArray &&other) noexcept
		: data_(std::move(other.data_)), size_(other.size_)
	{
		other.size_ = 0;
	}
	DynamicArray &operator=(DynamicArray &&other) noexcept
	{
		if (this != &other)
		{
			data_ = std::move(other.data_);
			size_ = other.size_;
			other.size_ = 0;
		}
		return *this;
	}

	// Element access
	T &operator[](size_t index)
	{
		if (index >= size_)
		{
			throw std::out_of_range("Index out of range");
		}
		return data_.get()[index];
	}
	// Iterators
	Iterator begin() { return Iterator(data_, 0); }
	Iterator end() { return Iterator(data_, size_); }
	const Iterator cbegin() const { return Iterator(data_, 0); }
	const Iterator cend() const { return Iterator(data_, size_); }

	// Capacity
	bool empty() const { return size_ == 0; }
	size_t size() const { return size_; }

	// Modifiers
	void erase(Iterator pos)
	{
		if (pos.index_ >= size_)
		{
			throw std::out_of_range("Invalid iterator");
		}
		std::shared_ptr<T> new_data = std::make_shared<T[]>(size_ - 1);
		for (size_t i = 0; i < pos.index_; ++i)
		{
			new_data.get()[i] = data_.get()[i];
		}
		for (size_t i = pos.index_ + 1; i < size_; ++i)
		{
			new_data.get()[i - 1] = data_.get()[i];
		}
		data_ = std::move(new_data);
		--size_;
	}
	void clear()
	{
		data_ = std::make_shared<T[]>(0);
		size_ = 0;
	}
	void push_back(const T &element)
	{
		std::shared_ptr<T> new_data(new T[size_ + 1], std::default_delete<T[]>());
		for (size_t i = 0; i < size_; ++i)
		{
			new_data.get()[i] = data_.get()[i];
		}
		new_data.get()[size_] = element;
		data_ = std::move(new_data);
		++size_;
	}
	void pop_back()
	{
		if (size_ == 0)
		{
			throw std::out_of_range("Cannot pop from empty array");
		}
		std::shared_ptr<T> new_data = std::make_shared<T[]>(size_ - 1);
		for (size_t i = 0; i < size_ - 1; ++i)
		{
			new_data.get()[i] = data_.get()[i];
		}
		data_ = std::move(new_data);
		--size_;
	}

private:
	std::shared_ptr<T[]> data_;
	size_t size_;
};

int main()
{
	// Create a dynamic array of integers
	DynamicArray<int> array;
	for (int i = 0; i < 10; ++i)
	{
		array.push_back(i);
	}

	// Test size and empty functions
	std::cout << "Size: " << array.size() << std::endl;	  // prints "Size: 10"
	std::cout << "Empty: " << array.empty() << std::endl; // prints "Empty: 0"

	// Test element access and iterators
	std::cout << "Elements:";
	for (int i : array)
	{
		std::cout << " " << i;
	}

	return 0;
}