#include "Userdata.h"

userdata::userdata()
{
	createTable(conn);
}

MYSQL* userdata::linkDatabase() {
	MYSQL* conn = mysql_init(NULL);
	int timeout = 3;
	if (conn != NULL) {
		mysql_options(conn, MYSQL_OPT_CONNECT_TIMEOUT, (const char*)&timeout);
		mysql_options(conn, MYSQL_OPT_READ_TIMEOUT, (const char*)&timeout);
		mysql_options(conn, MYSQL_OPT_WRITE_TIMEOUT, (const char*)&timeout);
	}
	char host_name[1024] = "localhost";
	char user_name[1024] = "root";
	char user_password[1024] = "123456";
	char server_name[1024] = "game";
	unsigned short host_port = 3306;
	if (!mysql_real_connect(conn, host_name, user_name, user_password, server_name, host_port, NULL, 0)) {
		int error_code = mysql_errno(conn);
		mysql_close(conn);
		std::cout << "链接失败！" << mysql_error(conn) << std::endl;
	}
	else {
		std::cout << "链接成功！" << std::endl;
	}
	return conn;
}

void userdata::createTable(MYSQL* conn)
{
	std::string query = "CREATE TABLE IF NOT EXISTS gameUser("
		"no INT PRIMARY KEY AUTO_INCREMENT, "
		"username VARCHAR(256),"
		"password VARCHAR(256));";
	if (mysql_query(conn, query.c_str())) {
		std::cerr << "Create table failed: " << mysql_error(conn) << std::endl;
	}
}

void userdata::insertRecord(MYSQL* conn, std::string username, std::string password)
{
	std::string query = "INSERT INTO gameUser(username, password) VALUES('" + username + "','" + password + "');";
	if (mysql_query(conn, query.c_str())) {
		std::cerr << "Insert record failed: " << mysql_error(conn) << std::endl;
	}
}

void userdata::deleteRecord(MYSQL* conn, const std::string& username)
{
	std::string query = "DELETE FROM gameUser WHERE username = '" + username + "';";
	if (mysql_query(conn, query.c_str())) {
		std::cerr << "Delete record failed: " << mysql_error(conn) << std::endl;
	}
}

void userdata::readRecord(MYSQL* conn)
{
	std::string query = "SELECT * FROM gameUser";
	if (mysql_query(conn, query.c_str())) {
		std::cerr << "Select query failed: " << mysql_error(conn) << std::endl;
		return;
	}

	MYSQL_RES* result = mysql_store_result(conn);
	if (!result) {
		std::cerr << "Store result failed: " << mysql_error(conn) << std::endl;
	}

	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;

	while (row = mysql_fetch_row(result)) {
		for (int i = 0; i < num_fields; i++) {
			std::cout << (row[i] ? row[i] : "NULL") << " ";
		}
		std::cout << std::endl;
	}

	mysql_free_result(result);
}

void userdata::updateRecord(MYSQL* conn, const std::string& username, const std::string& password) {
	std::string query = "UPDATE gameUser SET username = '" + username + "', password = '" + password + "' WHERE username = '" + username + "';";
	if (mysql_query(conn, query.c_str())) {
		std::cerr << "Update record failed: " << mysql_error(conn) << std::endl;
	}
}

int userdata::isUser(MYSQL* conn, const char* username) {
	std::string query = "SELECT * FROM gameUser";
	if (mysql_query(conn, query.c_str())) {
		std::cerr << "Select query failed: " << mysql_error(conn) << std::endl;
		return 0; //状态0：获取数据错误。
	}

	MYSQL_RES* result = mysql_store_result(conn);
	if (!result) {
		std::cerr << "Store result failed: " << mysql_error(conn) << std::endl;
		return 0; //状态0：获取数据错误。
	}

	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;

	while (row = mysql_fetch_row(result)) {
		if (strcmp(username, row[1]) == 0) {
			mysql_free_result(result);
			return 1; //状态1：账号存在，进入下一个输入密码界面。
		}
	}
	mysql_free_result(result);
	return 2; //状态2：账号不存在，提示进行注册。
}

int userdata::isPass(MYSQL* conn, const char* username, const char* password) {
	std::string name = username;
	std::string query = "SELECT password FROM gameUser WHERE username = '" + name + "';";
	if (mysql_query(conn, query.c_str())) {
		std::cerr << "Select query failed: " << mysql_error(conn) << std::endl;
		return 0; //状态0：获取数据错误。
	}

	MYSQL_RES* result = mysql_store_result(conn);
	if (!result) {
		std::cerr << "Store result failed: " << mysql_error(conn) << std::endl;
		return 0; //状态0：获取数据错误。
	}

	MYSQL_ROW row = mysql_fetch_row(result);
	if (!row) {
		std::cerr << "No username！" << std::endl;
	}

	if (!strcmp(password, row[0])) {
		
		return 3; //状态3：密码正确，登陆成功。
	}
	else {
		
		return 4; //状态4：密码错误，提示重新输入。
	}
}

int userdata::signup(MYSQL* conn, const char* username, const char* password) {
	if (isUser(conn, username) == 1) {
		return 1; //状态1：该用户已存在；
	}
	else if (isUser(conn, username) == 2) {
		std::string name = username, pass = password;
		insertRecord(conn, name, pass);
		return 2;  //状态2：用户注册成功。
	}
}