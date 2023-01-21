#include "dynamic_array.h"

//template <typename T>
//class DynamicArray {
// public:

#include <vector>



//dynamic_array_nmspc::DynamicArray;

template <typename T>
DynamicArray() : size_(0), capacity_(0), data_(nullptr) {}

 // Constructor with size
  explicit DynamicArray(std::size_t size) : size_(size), capacity_(size), data_(std::make_shared<T[]>(size)) {}


   // Constructor with size and value
  template <typename T>
  DynamicArray(std::size_t size, const T& value) : DynamicArray(size)
  {
    for (std::size_t i = 0; i < size_; ++i)
    {
      data_[i] = value;
    }
  }

   ~DynamicArray() {}

// Copy assignment operator
  DynamicArray& operator=(const DynamicArray& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = other.data_;
    return *this;
  }

void push_back(const T& value) {
  // If the array is full, double the capacity
  if (size_ == capacity_) {
    capacity_ *= 2;
    std::shared_ptr<T[]> new_data = std::make_shared<T[]>(capacity_);
    for (std::size_t i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }
    data_ = std::move(new_data);
  }

  // Add the new element to the end of the array
  data_[size_] = value;
  ++size_;
}

  // Move assignment operator
  DynamicArray& operator=(DynamicArray&& other) noexcept {
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = std::move(other.data_);
    other.size_ = 0;
    other.capacity_ = 0;
    return *this;
  }

  // Test whether container is empty
  bool empty() const { return size_ == 0; }

  // Return container size
  std::size_t size() const { return size_; }

  // Erase element pointed by the given iterator
  void erase(std::size_t pos) {
    if (pos >= size_) {
      throw std::out_of_range("Index out of range");
    }
    for (std::size_t i = pos; i < size_ - 1; ++i) {
      data_[i] = data_[i + 1];
    }
    --size_;
  }

  // Clear all content
  void clear() { size_ = 0; }

  // Return iterator to beginning
  T* begin() { return &data_[0]; }
  const T* begin() const { return &data_[0]; }

  // Return iterator to end
  T* end() { return &data_[size_]; }
  const T* end() const { return &data_[size_]; }

  // Return a constant iterator to beginning
  const T* cbegin() const { return &data_[0]; }

  // Return a constant iterator to end
  const T* cend() const { return &data_[size_]; }


  // Copy constructor
  DynamicArray(const DynamicArray& other) : size_(other.size_), capacity_(other.capacity_), data_(other.data_) {}

  // Move constructor
  DynamicArray(DynamicArray&& other) noexcept : size_(other.size_), capacity_(other.capacity_), data_(std::move(other.data_)) {
    other.size_ = 0;
    other.capacity_ = 0;
  }

	//private:
		// size_t size_;
		// size_t capacity_;
		// shared_ptr<T[]> data_;

	//public:
  // Iterator class
  class Iterator {
   public:
	// Constructor
	Iterator(T* p) : ptr_(p) {}

	// Dereference operator
	T& operator*() { return *ptr_; }

	// Member access operator
	T* operator->() { return ptr_; }

	// Pre-increment operator
	Iterator& operator++() {
	  ++ptr_;
	  return *this;
	}

	// Post-increment operator
	Iterator operator++(int) {
	  Iterator tmp(*this);
	  ++ptr_;
	  return tmp;
	}

	// Pre-decrement operator
	Iterator& operator--() {
	  --ptr_;
	  return *this;
	}

  Iterator& operator[](int index)
  {
    return *(ptr_ + index); 
  }

	// Post-decrement operator
	Iterator operator--(int) {
	  Iterator tmp(*this);
	  --ptr_;
	  return tmp;
	}

	// Equal operator
	bool operator==(const Iterator& other) const { return ptr_ == other.ptr_; }

	// Not equal operator
	bool operator!=(const Iterator& other) const { return ptr_ != other.ptr_; }

   private:
	T* ptr_;
  };

	// Const iterator class
  class ConstIterator {
   public:
    // Constructor
    ConstIterator(const T* p) : ptr_(p) {}

    // Dereference operator
    const T& operator*() const { return *ptr_; }

    // Member access operator
    const T* operator->() const { return ptr_; }

    // Pre-increment operator
    ConstIterator& operator++() {
      ++ptr_;
      return *this;
    }

    // Post-increment operator
    ConstIterator operator++(int) {
      ConstIterator tmp(*this);
      ++ptr_;
      return tmp;
    }

    // Pre-decrement operator
    ConstIterator& operator--() {
      --ptr_;
      return *this;
    }

    // Post-decrement operator
    ConstIterator operator--(int) {
      ConstIterator tmp(*this);
      --ptr_;
      return tmp;
    }

    // Equal operator
    bool operator==(const ConstIterator& other) const { return ptr_ == other.ptr_; }

    // Not equal operator
    bool operator!=(const ConstIterator& other) const { return ptr_ != other.ptr_; }

   private:
    const T* ptr_;
  };




