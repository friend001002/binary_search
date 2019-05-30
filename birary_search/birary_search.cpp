#include "binary_search.hpp"

using namespace std;

template<class T>
Binary_search<T>::Binary_search(const vector<T>& data)
{
  data_ = data;
}

template<class T>
string Binary_search<T>::Get_type() const
{
  return typeid(T).name();
}

template<class T>
vector<T> Binary_search<T>::Get_data() const
{
  return data_;
}

template<class T>
void Binary_search<T>::Set_data(const vector<T>& data)
{
  data_ = data;
}

template<class T>
Binary_search<T>::~Binary_search()
{

}

template<class T>
bool Binary_search<T>::Find(T element, size_t& result) const
{
  size_t size = data_.size();

  if (0 == size)
  {
    return false;
  }

  bool even = false;

  size_t index = size / 2;

  if (data_.size() % 2 == 0)
  {
    // Even number of elements.
    --index;

    even = true;
  }

  while (true)
  {
    if (element > data_.at(index))
    {
      // Continue to search in upper part of array.

      size_t add = static_cast<size_t>(floor((size - index) / 2.0));

      if (0 == add)
      {
        // To reach the very end of array.
        ++index;
      }
      else
      {
        index += add;
      }

      if (index >= size)
      {
        // Requested item isn't here.
        return false;
      }

      if (even)
      {
        //++index;
      }
    }
    else if (element < data_.at(index))
    {
      if (index != 0)
      {
        index -= static_cast<size_t>(ceil(index / 2.0));
      }
      else
      {
        // Requested item isn't here.
        return false;
      }

      if (even)
      {
        //++index;
      }

      // Continue to search in lower part of array.
    }

    if (element == data_.at(index))
    {
      // Found it.

      result = index;
      return true;
    }
  }

  return false;
}

/*void Test()
{
  Binary_search<double> bs({ 1.0, 2.0, 3.0, 4.0 });
  size_t res = 0;

  _ASSERT_EXPR(false == bs.Find(0.0, res), L"Failed test 1");

  _ASSERT_EXPR(true == bs.Find(1.0, res) && 0 == res, L"Failed test 2");
  _ASSERT_EXPR(true == bs.Find(2.0, res) && 1 == res, L"Failed test 3");
  _ASSERT_EXPR(true == bs.Find(3.0, res) && 2 == res, L"Failed test 4");
  _ASSERT_EXPR(true == bs.Find(4.0, res) && 3 == res, L"Failed test 5");

  _ASSERT_EXPR(false == bs.Find(5.0, res), L"Failed test 6");
}*/

int main()
{
  //Test();

  cin.get();
}
