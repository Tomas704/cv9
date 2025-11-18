#ifndef LIBDF_DATAFRAME_HPP
#define LIBDF_DATAFRAME_HPP

#include <ostream>
#include <vector>

namespace df {

template <typename T> class DataFrame {
public:
  explicit DataFrame(std::vector<T> data);
  void print(std::ostream &ost) const;
  std::size_t size() const;

private:
  std::vector<T> m_data;
};

template <typename T>
DataFrame<T>::DataFrame(std::vector<T> data) : m_data(std::move(data)) {}

template <typename T> void DataFrame<T>::print(std::ostream &ost) const {
  for (const T &item : m_data) {
    ost << item << "\n";
  }
}

template <typename T> std::size_t DataFrame<T>::size() const {
  return m_data.size();
}

} // namespace df

#endif
