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

std::unique_ptr<IDBConnection> OracleDBFactory::CreateDBConnection()
{
  return std::make_unique<OracleConnection>();
}

std::unique_ptr<IDBCommand> OracleDBFactory::CreateDBCommand()
{
  return std::make_unique<OracleCommand>();
}

std::unique_ptr<IDataReader> OracleDBFactory::CreateDataReader()
{
  return std::make_unique<OracleDataReader>();
}