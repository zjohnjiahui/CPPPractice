#include "SqlDBFactory.h"
#include <iostream>

void SqlConnection::connect()
{
  std::cout << "SqlConnection" << std::endl;
}

void SqlCommand::command()
{
  std::cout << "SqlCommand" << std::endl;
}

void SqlDataReader::read()
{
  std::cout << "SqlDataReader" << std::endl;
}

std::unique_ptr<IDBConnection> SqlDBFactory::CreateDBConnection()
{
  return std::make_unique<SqlConnection>();
}

std::unique_ptr<IDBCommand> SqlDBFactory::CreateDBCommand()
{
  return std::make_unique<SqlCommand>();
}

std::unique_ptr<IDataReader> SqlDBFactory::CreateDataReader()
{
  return std::make_unique<SqlDataReader>();
}