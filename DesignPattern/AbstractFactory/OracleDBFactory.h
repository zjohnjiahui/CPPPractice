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
  IDBConnection* CreateDBConnection() override;
  IDBCommand* CreateDBCommand() override;
  IDataReader* CreateDataReader() override;
};