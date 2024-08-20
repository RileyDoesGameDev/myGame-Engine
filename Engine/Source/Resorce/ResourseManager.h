#pragma once
#include "Resorce.h"
#include "Core/Singleton.h"
#include "Core/EString.h"
#include <map>
#include <iostream>

class ResourceManager : public Singleton<ResourceManager>
{
public:
	void Clear() { m_resources.clear(); }

	template<typename T, typename ... TArgs>
	res_t<T> Get(const std::string& name, TArgs ... args);
	friend Singleton;
protected:
		ResourceManager() = default;

private:
	std::map<std::string, res_t<Resource>> m_resources;
};

template<typename T, typename ... TArgs>
inline res_t<T> ResourceManager::Get(const std::string& name, TArgs... args)
{
	std::string lowerName = ToLower(name);


	if (m_resources.find(lowerName) != m_resources.end())
	{
		return std::dynamic_pointer_cast<T>(m_resources[lowerName]);
	}

	res_t<T> resource = std::make_shared<T>();
	if(!resource->Create(lowerName, args...))
	{
		std::cerr << "could not create resource:" << name << std::endl;
		return res_t<T>();
	}
	m_resources[lowerName] = resource;
	return resource;

}
