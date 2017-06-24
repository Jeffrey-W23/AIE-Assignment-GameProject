// #include, using, etc
#pragma once
#include "AssociativeArray.h"
#include "Resource.h"
#include "string.h"

//--------------------------------------------------------------------------------------
// ResourceManager Templated object.
//--------------------------------------------------------------------------------------
template<typename T>
class ResourceManager
{
public:

	//--------------------------------------------------------------------------------------
	// LoadResource: Load a resource into the resource machine.
	//
	// Param:
	//		szFileName: A char pointer for the file you want to load.
	//
	// Return:
	//		T: Returns T for the resource
	//--------------------------------------------------------------------------------------
	T* LoadResource(char* szFileName)
	{
		_ASSERT(szFileName);

		// Check if resource is already loaded. if it is, return it.
		if (m_ResourceList.IsItem(szFileName))
		{
			return m_ResourceList[szFileName]->m_pData;
		}

		// Resource is not loaded, so load it
		Resource<T>* pResource = new Resource<T>(szFileName);
		_ASSERT(pResource);
		m_ResourceList.AddItem(szFileName, pResource);
		return pResource->m_pData;
	}

	//--------------------------------------------------------------------------------------
	// UnloadAllResources: Unload all the resources.
	//--------------------------------------------------------------------------------------
	void UnloadAllResources()
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}

		m_ResourceList.Clear();
	}

	//--------------------------------------------------------------------------------------
	// create: A function for creating an instance of the ResourceManager
	//--------------------------------------------------------------------------------------
	static void Create()
	{
		if (!m_pInstance)
		{
			m_pInstance = new ResourceManager<T>();
			_ASSERT(m_pInstance);
		}
	}

	//--------------------------------------------------------------------------------------
	// destroy: A function for deleting the ResourceManager instance.
	//--------------------------------------------------------------------------------------
	static void Destroy()
	{
		delete m_pInstance;
	}

	//--------------------------------------------------------------------------------------
	// Instance: The function for providing access.
	//--------------------------------------------------------------------------------------
	static ResourceManager<T>* GetInstance()
	{
		return m_pInstance;
	}

private:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	ResourceManager()
	{
	}

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~ResourceManager()
	{
		UnloadAllResources();
	}

	//--------------------------------------------------------------------------------------
	// An AssociativeArray of Resource T pointers ResourceManager.
	//--------------------------------------------------------------------------------------
	AssociativeArray<Resource<T>*> m_ResourceList;

	//--------------------------------------------------------------------------------------
	// The one and only instance of this class
	//--------------------------------------------------------------------------------------
	static ResourceManager<T>* m_pInstance;
};

//--------------------------------------------------------------------------------------
// The one and only instance of this class
//--------------------------------------------------------------------------------------
template<typename T>
ResourceManager<T>* ResourceManager<T>::m_pInstance = nullptr;