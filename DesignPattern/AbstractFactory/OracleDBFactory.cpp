#include "OracleDBFactory.h"
#include <iostream>

void OracleConnection::connect()
{
  std::cout << "OracleConnection" << std::endl;
}

void OracleCommand::command()
{
  std::cout << "OracleCommand" << std::endl;
}

void OracleDataReader::read()
{
  std::cout << "OracleDataReader" << std::endl;
}

IDBConnection* OracleDBFactory::CreateDBConnection()
{
  return new OracleConnection();
}

IDBCommand* OracleDBFactory::CreateDBCommand()
{
  return new OracleCommand();
}

IDataReader* OracleDBFactory::CreateDataReader()
{
  return new OracleDataReader();
}