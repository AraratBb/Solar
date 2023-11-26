#include <string>
#include <iostream>

using namespace std;

class Parser
{
private:
	string path, domain, x, protocol, port, query, tid, URL;
	string _trim(const string& str);
public:
	Parser();
	Parser(const string& row_url);
	string GetProtocol();
	string GetDomain();
	string GetPort();
	string GetPath();
	string GetQuery();
	string GetURL();
	string GetTid();
	~Parser();
};
