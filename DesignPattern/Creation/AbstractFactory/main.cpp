#include <iostream>
#include <memory>
#include "DBFactory.h"
#include "OracleDBFactory.h"

class User
{
  IDBFactory* _factory;
public:
  User(IDBFactory* fac) : _factory(fac) { }

  void accessDB() 
  {
    std::unique_ptr<IDBConnection> con = _factory->CreateDBConnection();
    std::unique_ptr<IDBCommand> command = _factory->CreateDBCommand();
    std::unique_ptr<IDataReader> reader = _factory->CreateDataReader();

    con->connect();
    command->command();
    reader->read();
  }
};

int main()
{
  OracleDBFactory* Oracle = new OracleDBFactory();
  User user(Oracle);
  user.accessDB();

  delete Oracle;
  return 0;
}