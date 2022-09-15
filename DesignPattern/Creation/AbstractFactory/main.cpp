#include <iostream>
#include <memory>
#include "OracleDBFactory.h"

class User
{
  std::unique_ptr<IDBFactory> _factory;
public:
  User(std::unique_ptr<IDBFactory>& fac) : _factory(std::move(fac)) { }

  void accessDB() 
  {
    std::unique_ptr<IDBConnection> con = _factory->CreateDBConnection();
    std::unique_ptr<IDBCommand> command = _factory->CreateDBCommand();
    std::unique_ptr<IDBDataReader> reader = _factory->CreateDataReader();

    con->connect();
    command->command();
    reader->read();
  }
};

int main()
{
  std::unique_ptr<IDBFactory> Oracle = std::make_unique<OracleDBFactory>();
  User user(Oracle);
  user.accessDB();

  return 0;
}