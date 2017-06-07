#pragma once
#include <string.h>

template<typename T>
class Resource
{
public:
	Resource(char* szFileName, T data)
	{
		int length = strlen(szFileName) + 1;
		m_szFileName = new char[length];
		strcpy(m_szFileName, length, szFileName);

		m_pData = new T(szFileName);
	}

	//Template Specialisation
	/*template<>
	Resource(char* szFileName, T data)
	{
		int length = strlen(szFileName) + 1;
		m_szFileName = new char[length];
		strcpy(m_szFileName, length, szFileName);

		m_pData = new T(szFileName);
	}*/

	~Resource()
	{
		delete m_pData;
		delete[] m_szFileName;
	}

	char m_szFileName;
	T* m_pData;
};