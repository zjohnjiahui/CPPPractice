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
    std::shared_ptr<IDBConnection> con;
    con.reset(_factory->CreateDBConnection());

    std::shared_ptr<IDBCommand> command;
    command.reset(_factory->CreateDBCommand());

    std::shared_ptr<IDataReader> reader;
    reader.reset(_factory->CreateDataReader());

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
