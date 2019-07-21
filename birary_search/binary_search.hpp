#ifndef _BINARY_SEARCH_HPP_
#define _BINARY_SEARCH_HPP_

#include <iostream>
#include <vector>

#include <string>
#include <typeinfo>

#include <cmath>

class Binary_search_ex : public std::runtime_error
{
  public:

  explicit Binary_search_ex(const char *msg) : runtime_error(msg)
  {
    
  }

  explicit Binary_search_ex(std::string& msg) : runtime_error(msg)
  {

  }

  virtual ~Binary_search_ex() noexcept
  {
  }

  virtual const char* what() const noexcept
  {
    return std::runtime_error::what();
  }
};

template<class T>
class Binary_search
{
  public:

  Binary_search() = default;

  Binary_search(const std::vector<T>& data);

  std::string Get_type() const;

  std::vector<T> Get_data() const;

  size_t Get_iterations() const;

  void Set_data(const std::vector<T>& data);

  virtual ~Binary_search();

  bool   Find(T element, std::size_t& result);
  size_t Find(T to_find) noexcept(false);

  private:

  std::vector<T> data_;
  size_t iterations_;
};

#endif // _BINARY_SEARCH_HPP_
