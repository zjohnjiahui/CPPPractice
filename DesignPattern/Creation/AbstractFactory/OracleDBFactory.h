#pragma once
#include "DBFactory.h"
#include <iostream>

class OracleConnection : public IDBConnection {
public:
  void connect() override{    
    std::cout << "OracleConnection" << std::endl;   
  }
};

class OracleCommand : public IDBCommand {
public:
  void command() override{
    std::cout << "OracleCommand" << std::endl;
  }
};

class OracleDataReader : public IDBDataReader {
public:
  void read() override{
    std::cout << "OracleDataReader" << std::endl;
  }
};

class OracleDBFactory : public IDBFactory
{
public:
  std::unique_ptr<IDBConnection> CreateDBConnection() override{
    return std::make_unique<OracleConnection>();
  }
  std::unique_ptr<IDBCommand> CreateDBCommand() override{
    return std::make_unique<OracleCommand>();
  }
  std::unique_ptr<IDBDataReader> CreateDataReader() override{
    return std::make_unique<OracleDataReader>();
  }
};

