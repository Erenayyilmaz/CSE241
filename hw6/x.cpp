
include "util.hpp"

using namespace brk;

  // Default constructor
  template <typename T>
  PFArray<T>::PFArray(){
    this->size_=0;
    this->capacity=0;
    this->dynamic_array=nullptr;
  }

  // Constructor with  given size size
  template <typename T>
  PFArray<T>::PFArray(int size) 
  {
    this->size_ = size;
    this->capacity = size;
    //dynamic_array(new T[size], DeleteArray<T>())
    this->dynamic_array = std::shared_ptr<T>(new T[size], std::default_delete<T[]>());

  }
   
  // Copy constructor
  template <typename T>
  PFArray<T>::PFArray(const PFArray &other)
  {
    this->size_=other.size_;
    this->capacity=other.capacity;
    this->dynamic_array=other.dynamic_array;

  }

  // Move constructor
  template <typename T>
  PFArray<T>::PFArray(PFArray &&other)
  {
    this->size_=other.size_;
    this->capacity=other.capacity;
    this->dynamic_array = std::move(other.dynamic_array);
    other.size_ = 0;
    other.capacity = 0;
    other.dynamic_array=nullptr;
    
  }

  // Destructor
    template <typename T>
  PFArray<T>::~PFArray() {
  }

  // Copy assignemnt operator
  template <typename T>
  PFArray<T> &PFArray<T>::operator=(const PFArray &other)
  {
    this->size_ = other.size_;
      this->capacity = other.capacity;
      this->dynamic_array = other.dynamic_array;
    
    return *this; 
      
  }

  //move assignment operator
  template <typename T>
  PFArray<T> &PFArray<T>::operator=(PFArray &&other)
  {
      this->size_ = other.size_;
      this->capacity = other.capacity;
      this->dynamic_array = std::move(other.dynamic_array);
      other.size_ = 0;
      other.capacity = 0;
      other.dynamic_array=nullptr;
    
    return *this;
  }

  //funtion checks if size is 0 (empty or not)
  template <typename T>
  bool PFArray<T>::empty() const {
    if(this->size_==0)
      return true;
    else
      return false;
  }
  //returns size
  template <typename T>
  int PFArray<T>::size() const {
     return this->size_; 
  }

  //function clear deletes content of PFArray
  template <typename T>
  void PFArray<T>::clear() {
    this->size_ = 0; 
    this->capacity=0;
    this->dynamic_array=nullptr;
  }
  
  /*template <typename T>
  std::shared_ptr<T> PFArray<T>::operator[](int index){
      return *(dynamic_array + index);
  }*/
  
  //Returns first first pointer of dynamic_array
  template <typename T>
  T* PFArray<T>::begin() { return dynamic_array.get(); }
  
  //returns last+1 of dynamic array
  template <typename T>
  T* PFArray<T>::end() { return dynamic_array.get() + size_; }

  //const version
  template <typename T>
  const T* PFArray<T>::cbegin() const{ return dynamic_array.get(); }
  //constversion
  template <typename T>
  const T* PFArray<T>::cend() const{ return dynamic_array.get() + size_; }

  //erase, deletes an element and overrides rest 
  template <typename T>
  void PFArray<T>::erase(iterator it){

    if(it < begin() || it >= end()){
      throw std::out_of_range("iterator is out of range\n");
    }
    int i=0;
    for(auto my_it = begin();my_it!=end();my_it++){
      if((my_it)==(it)){
        std::cout <<"value of element in index(" <<i<<")is: "<<(*my_it)<<std::endl;;
        break;
      }
      i++;
    }

    for(auto& del_it = it;del_it!=end()-1;del_it++){  
        *(dynamic_array.get()+i) = *(dynamic_array.get()+i+1);
    i++;
    }
    --this->size_;

  }