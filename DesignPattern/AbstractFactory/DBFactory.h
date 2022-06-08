#pragma once

class IDBConnection {
public:
  virtual void connect() = 0;
};

class IDBCommand {
public:
  virtual void command() = 0;
};

class IDataReader {
public:
  virtual void read() = 0;
};


class IDBFactory {
public:
  virtual IDBConnection* CreateDBConnection() = 0;
  virtual IDBCommand* CreateDBCommand() = 0;
  virtual IDataReader* CreateDataReader() = 0;

};