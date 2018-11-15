
/**
 * 
 *  读取配置文件
 *  记录的格式为 key = value
 *  不支持分段[section]
 *  
 *  TDL 2018.11.15
 */
#ifndef __CONFIGFILE_H__
#define __CONFIGFILE_H__
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

class ConfigFile
{
public:
	typedef string KeyType;
	typedef string ValueType;
public:
	ConfigFile() = default;
	bool ReadConfigFile(const string file_name);
	bool ReReadConfigFile(const string file_name); // 重新读取配置文件
	ValueType GetValue(const KeyType Key)const;
private:
	fstream _fstream;
	map<KeyType, ValueType> _map;

	// 分隔配置文件的一行 格式 key=value
	bool Split(string line, string &key, string &value);
	// 去除字符串首位空格
	string EraseSpace(string &s);
};

// 字符串转数字
template <class Type>
Type StringToDigit(const string& str)
{
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

#endif // __CONFIGFILE_H__
