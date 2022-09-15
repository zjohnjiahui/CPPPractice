#pragma once
#include "DBFactory.h"

class OracleConnection : public IDBConnection {
public:
  void connect() override;
};

class OracleCommand : public IDBCommand {
public:
  void command() override;
};

class OracleDataReader : public IDataReader {
public:
  void read() override;
};

class OracleDBFactory : public IDBFactory
{
public:
  std::unique_ptr<IDBConnection> CreateDBConnection() override;
  std::unique_ptr<IDBCommand> CreateDBCommand() override;
  std::unique_ptr<IDataReader> CreateDataReader() override;
};

