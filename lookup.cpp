#include <map>
#include <sstream>
#include <iostream>
#include <stdexcept>

class Table
{
  typedef std::map<std::pair<int, int>, int> TableMap;
  TableMap m_table;

  Table( )
  {
    m_table[std::make_pair(0, 0)] = 1;
    m_table[std::make_pair(0, 8)] = 3;
  }

  Table(Table&);
  Table& operator=(Table&);

public:
  static Table& GetSingleton( )
  {
    static Table instance;
    return instance;
  }

  int operator()(int x, int y) const
  {
    TableMap::const_iterator it = m_table.find(std::make_pair(x, y));

    if (it == m_table.end( ))
    {
      std::stringstream ss;
      ss << "Value (" << x << "," << y << ") not in table";
      throw std::out_of_range(ss.str( ));
    }

    return it->second;
  }
};

int main( )
{
  try
  {
    std::cout << Table::GetSingleton( )(0, 0) << std::endl;
    std::cout << Table::GetSingleton( )(0, 1) << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what( ) << std::endl;
  }

  return 0;
}