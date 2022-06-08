#pragma once
#include "DBFactory.h"

class SqlConnection : public IDBConnection {
public:
  void connect() override;
};

class SqlCommand : public IDBCommand {
public:
  void command() override;
};

class SqlDataReader : public IDataReader {
public:
  void read() override;
};


class SqlDBFactory :public IDBFactory {
public:
  IDBConnection* CreateDBConnection() override;
  IDBCommand* CreateDBCommand() override;
  IDataReader* CreateDataReader() override;
};