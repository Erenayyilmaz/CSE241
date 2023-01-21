#ifndef UTIL_HPP
#define UTIL_HPP

#include <memory>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

using std::cout;
using std::cin;
using std::endl;


namespace brk{

  /*template <typename T>
  class DeleteArray {
    public:
    void operator()(T *ptr) {
      delete[] ptr;
    }
  };
  */
  template <typename T>
  class PFArray{

    public:
          //iterator  as inner class
          class iterator{
          public:
          
          //these make some functions work you will see
          using value_type = T;
          using reference = T&;
          using pointer = T*;
          using iterator_category = std::random_access_iterator_tag;
          using difference_type = std::ptrdiff_t;    

            // Constructor
            iterator(T *p) {
              ptr_ = p;
            }

            // Iterator operators
            T &operator*() const { return *ptr_; }
            T *operator->() const { return ptr_; }
            
            //++operator prefix
            iterator &operator++()
            {
              ++ptr_;
              return *this;
            }
            //++operator postfix
            iterator operator++(int)
            {
              iterator temp(this->ptr_);
              ++ptr_;
              return temp;
            }
            //--operator prefix
            iterator &operator--()
            {
              --ptr_;
              return *this;
            }
            //--operator postfix
            iterator operator--(int)
            {
              iterator temp(this->ptr_);
              --ptr_;
              return temp;
            }
            
            /*iterator& operator-(int x)
            {
              int i=0;
              while(i++ < x){
              --ptr_;
              }

              return *this;
            }*/

            /*iterator &operator+(int x)
            {
              int i=0;
              while(i++ < x)
              ++ptr_;

              return *this;
            }*/

            //difference_type is long int and is required for sort
            difference_type operator-(const iterator& other) const {
                return (this->ptr_ - other.ptr_);
            }
            //rest in the class is basic comparison operators
            bool operator==(const iterator &other) const {
              return (this->ptr_ == other.ptr_); 
            }
            bool operator!=(const iterator &other) const {
              return (this->ptr_ != other.ptr_); 
            }
            bool operator<(const iterator &other) const {
              return (this->ptr_ < other.ptr_);
            }
            bool operator>(const iterator &other) const {
              return (this->ptr_ > other.ptr_);
            }
            bool operator>=(const iterator &other) const {
              return !(this->ptr_< other.ptr_); 
            }
            bool operator<=(const iterator &other) const {
              return !(this->ptr_ > other.ptr_); 
            }

          private:
              //i store data as template pointer
              T *ptr_;
          };   

    PFArray();
    
    PFArray(int size); 
    
    PFArray(const PFArray &other);
    
    PFArray(PFArray &&other);
    
    ~PFArray();
    
    PFArray &operator=(const PFArray &other);
    
    PFArray &operator=(PFArray &&other);
    
    bool empty() const ;
    
    int size() const;
    
    void erase(iterator it);
    
    void clear();
    
    std::shared_ptr<T> operator[](int index);
    
    T* begin();
    
    T* end();

    const T* cbegin() const;
    
    const T* cend() const;

  private:
    int size_;
    int capacity;
    std::shared_ptr<T> dynamic_array;
  };
}
#endif