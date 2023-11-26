#include "parser.h"

string Parser:: _trim(const string& str)
{
    size_t start = str.find_first_not_of(" \n\r\t");
    size_t until = str.find_last_not_of(" \n\r\t");
    string::const_iterator i = start==string::npos ? str.begin() : str.begin() + start;
    string::const_iterator x = until==string::npos ? str.end()   : str.begin() + until+1;
    return string(i,x);
}

Parser:: Parser() {}
Parser:: Parser(const string& row_url)
{
	URL = row_url;
	int offset = 0;
	size_t pos1, pos2, pos3, pos4;
	x = _trim(row_url);
	offset = offset==0 && x.compare(0, 8, "https://")==0 ? 8 : offset;
	offset = offset==0 && x.compare(0, 7, "http://" )==0 ? 7 : offset;
	pos1 = x.find_first_of('/', offset+1 );
	path = pos1==string::npos ? "" : x.substr(pos1);
	domain = string( x.begin()+offset, pos1 != string::npos ? x.begin()+pos1 : x.end() );
	path = (pos2 = path.find("#"))!=string::npos ? path.substr(0,pos2) : path;
	port = (pos3 = domain.find(":"))!=string::npos ? domain.substr(pos3+1) : "";
	domain = domain.substr(0, pos3!=string::npos ? pos3 : domain.length());
	protocol = offset > 0 ? x.substr(0,offset-3) : "";
	query = (pos4 = path.find("?"))!=string::npos ? path.substr(pos4+1) : "";
	path = pos4!=string::npos ? path.substr(0,pos4) : path;
}

string Parser:: GetProtocol(){
	return protocol;
}

string Parser:: GetDomain(){
	return domain;
}

string Parser:: GetPort(){
	return port;
}

string Parser:: GetPath(){
	return path;
}

string Parser:: GetQuery(){
	return query;
}

string Parser:: GetURL(){
	return URL;
}

Parser:: ~Parser(){}
