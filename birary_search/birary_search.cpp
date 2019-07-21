#include "binary_search.hpp"

using namespace std;

template<class T>
Binary_search<T>::Binary_search(const vector<T>& data) : data_(data), iterations_(0)
{

}

template<class T>
Binary_search<T>::~Binary_search()
{

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
size_t Binary_search<T>::Get_iterations() const
{
  return iterations_;
}

template<class T>
void Binary_search<T>::Set_data(const vector<T>& data)
{
  data_ = { data };
}

template<class T>
bool Binary_search<T>::Find(T to_find, size_t& result)
{
  size_t size = data_.size();

  if (0 == size)
  {
    iterations_ = 0;
    return false;
  }

  size_t index = size / 2;

  iterations_ = 1;

  while (true)
  {
    if (to_find > data_.at(index))
    {
      // Continue to search in upper part of array.

      size_t index_inc = static_cast<size_t>(floor((size - index) / 2.0));

      ++iterations_;

      if (0 == index_inc)
      {
        // To reach the very end of array.
        ++index;
      }
      else
      {
        index += index_inc;
      }

      if (index >= size)
      {
        // Requested item isn't here.
        return false;
      }
    }
    else if (to_find < data_.at(index))
    {
      ++iterations_;

      if (index != 0)
      {
        index -= static_cast<size_t>(ceil(index / 2.0));
      }
      else
      {
        // Requested item isn't here.
        return false;
      }

      // Continue to search in lower part of array.
    }

    if (to_find == data_.at(index))
    {
      // Found it.

      result = index;
      return true;
    }
  }

  return false;
}

template<class T>
size_t Binary_search<T>::Find(T to_find) noexcept(false)
{
  size_t size = data_.size();

  if (0 == size)
  {
    iterations_ = 0;

    throw Binary_search_ex("No data to search through");
  }

  size_t index = size / 2;

  iterations_ = 1;

  while (true)
  {
    if (to_find > data_.at(index))
    {
      // Continue to search in upper part of array.

      size_t index_inc = static_cast<size_t>(floor((size - index) / 2.0));

      ++iterations_;

      if (0 == index_inc)
      {
        // To reach the very end of array.
        ++index;
      }
      else
      {
        index += index_inc;
      }

      if (index >= size)
      {
        // Requested item isn't here.
        throw Binary_search_ex("Failed to find the item");
      }
    }
    else if (to_find < data_.at(index))
    {
      ++iterations_;

      if (index != 0)
      {
        index -= static_cast<size_t>(ceil(index / 2.0));
      }
      else
      {
        // Requested item isn't here.
        throw Binary_search_ex("Failed to find the item");
      }

      // Continue to search in lower part of array.
    }

    if (to_find == data_.at(index))
    {
      // Found it.

      return index;
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
  cout << "Error codes:\n";

  do
  {
    double to_find { 1.0 };
    Binary_search<double> bs({ 1.0, 2.0, 3.0, 4.0 });
    size_t res {};

    bool found  { bs.Find(to_find, res) };
    size_t iter { bs.Get_iterations() };

    cout << "found " << boolalpha << found << " iter " << iter << " res " << res << " to_find " << to_find << endl;
  }
  while (false);

  cout << "Exceptions:\n";

  do
  {
    double to_find { 2.0 };
    Binary_search<double> bs({ 1.0, 2.0, 3.0, 4.0 });

    try
    {
      size_t res  { bs.Find(to_find) };

      size_t iter { bs.Get_iterations() };

      cout << "found iter " << iter << " res " << res << " to_find " << to_find << endl;
    }
    catch (Binary_search_ex& ex)
    {
      cerr << "Exception: " << ex.what() << endl;
    }

  } while (false);

  cin.get();
}
