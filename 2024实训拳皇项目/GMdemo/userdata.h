#pragma once
#pragma once

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <mysql.h>
#include <winsock.h>

class userdata {
private:
	MYSQL* linkDatabase();
	void createTable(MYSQL* conn);
	void insertRecord(MYSQL* conn, std::string username, std::string password);
	void deleteRecord(MYSQL* conn, const std::string& userName);
	void readRecord(MYSQL* conn);
	void updateRecord(MYSQL* conn, const std::string& userName, const std::string& password);
public:
	MYSQL* conn = linkDatabase();
	userdata();
	int isUser(MYSQL* conn, const char* userName);
	int isPass(MYSQL* conn, const char* username, const char* password);
	int signup(MYSQL* conn, const char* username, const char* password);
};
