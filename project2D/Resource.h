// #include, using, etc
#pragma once
#include <string.h>
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Resource Templated object.
//--------------------------------------------------------------------------------------
template<typename T>
class Resource
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//
	// Param:
	//		szFileName: A char pointer of the file name path of the resource.
	//--------------------------------------------------------------------------------------
	Resource(char* szFileName)
	{
		_ASSERT(szFileName);

		int length = strlen(szFileName) + 1;
		m_szFileName = new char[length];
		_ASSERT(m_szFileName);
		strcpy_s(m_szFileName, length, szFileName);

		m_pData = new T(szFileName);
		_ASSERT(m_pData);
	}

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Resource()
	{
		delete m_pData;
		delete[] m_szFileName;
	}

	//--------------------------------------------------------------------------------------
	// A char pointer m_szFileName
	//--------------------------------------------------------------------------------------
	char* m_szFileName;

	//--------------------------------------------------------------------------------------
	// A T pointer m_pData.
	//--------------------------------------------------------------------------------------
	T* m_pData;
};