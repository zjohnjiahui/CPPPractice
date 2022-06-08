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

IDBConnection* SqlDBFactory::CreateDBConnection()
{
  return new SqlConnection();
}

IDBCommand* SqlDBFactory::CreateDBCommand()
{
  return new SqlCommand();
}

IDataReader* SqlDBFactory::CreateDataReader()
{
  return new SqlDataReader();
}