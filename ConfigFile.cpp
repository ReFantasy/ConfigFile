#include "ConfigFile.h"

bool ConfigFile::ReadConfigFile(const string file_name)
{
	if (!_map.empty())
		return false;
	_fstream.open(file_name);
	if (!_fstream)
		return false;  // 读取配置文件失败
	string line;
	while (getline(_fstream, line))
	{
		//cout << line << endl;
		string key, value;
		bool splite = Split(line, key, value);  
		if (splite)
		{
			key = EraseSpace(key);
			value = EraseSpace(value);
			//插入到map
			_map.insert(make_pair(key,value));
		}
	}
	
	_fstream.close();
}

bool ConfigFile::ReReadConfigFile(const string file_name)
{
	_map.clear();
	return ReReadConfigFile(file_name);
}

ConfigFile::ValueType ConfigFile::GetValue(const KeyType Key)const
{
	auto iter = _map.find(Key);
	if (iter == _map.end())
		return KeyType();
	else
		return iter->second;
}

bool ConfigFile::Split(string line, string &key, string &value)
{
	string::iterator iter_equal_sign = line.end();
	if ((iter_equal_sign = find(line.begin(),line.end(), '=')) == line.end())
		return false;  // 找不到'='不是有效行

	// 分割 key和 value
	key = string(line.begin(), iter_equal_sign);
	value = string(iter_equal_sign + 1, line.end());

	// 去除首位空格
	
}

std::string ConfigFile::EraseSpace(string &s)
{
	if (s.empty())
		return s;

	string::iterator b, e;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			b = s.begin() + i;
			break;
		}
	}
	for (int i = s.size()-1; i >=0; i--)
	{
		if (s[i] != ' ')
		{
			e = s.begin() + i;
			break;
		}
	}
	return string(b, e + 1);
}
