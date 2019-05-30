#ifndef _BINARY_SEARCH_HPP_
#define _BINARY_SEARCH_HPP_

#include <iostream>
#include <vector>

#include <string>
#include <typeinfo>

#include <cmath>

template<class T>
class Binary_search
{
  public:

  Binary_search() = default;

  Binary_search(const std::vector<T>& data);

  std::string Get_type() const;

  std::vector<T> Get_data() const;

  void Set_data(const std::vector<T>& data);

  virtual ~Binary_search();

  bool Find(T element, std::size_t& result) const;

  private:

  std::vector<T> data_;
};

#endif // _BINARY_SEARCH_HPP_
