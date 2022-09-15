#pragma once
#include "DBFactory.h"
#include <iostream>

class SqlConnection : public IDBConnection {
public:
  void connect() override {
    std::cout << "SqlConnection" << std::endl;
  }
};

class SqlCommand : public IDBCommand {
public:
  void command() override {
    std::cout << "SqlCommand" << std::endl;
  }
};

class SqlDataReader : public IDBDataReader {
public:
  void read() override {
    std::cout << "SqlDataReader" << std::endl;
  }
};


class SqlDBFactory :public IDBFactory {
public:
  std::unique_ptr<IDBConnection> CreateDBConnection() override {
    return std::make_unique<SqlConnection>();
  }
  std::unique_ptr<IDBCommand> CreateDBCommand() override {
    return std::make_unique<SqlCommand>();
  }
  std::unique_ptr<IDBDataReader> CreateDataReader() override {
    return std::make_unique<SqlDataReader>();
  }
};
