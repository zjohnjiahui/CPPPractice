#pragma once
#include <memory>

class IDBConnection {
public:
  virtual ~IDBConnection() { }
  virtual void connect() = 0;
};

class IDBCommand {
public:
  virtual ~IDBCommand() { }
  virtual void command() = 0;
};

class IDataReader {
public:
  virtual ~IDataReader() { }
  virtual void read() = 0;
};


class IDBFactory { // singleton factory
public:
  virtual std::unique_ptr<IDBConnection> CreateDBConnection() = 0;
  virtual std::unique_ptr<IDBCommand> CreateDBCommand() = 0;
  virtual std::unique_ptr<IDataReader> CreateDataReader() = 0;
};