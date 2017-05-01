#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <map>
#include "Fruit.hpp"
#include "Herb.hpp"
#include "Legume.hpp"
#include "Vegetable.hpp"

class Factory {
//private:
//	Factory();
//	Factory(const Factory& f);
//	Factory& operator=(const Factory& f) { return *this; }
//	
//	typedef std::map<std::string,Plant::CreatePlantFunc> factoryMap;
//	factoryMap m_factoryMap;
//
//public:
//	~Factory() { m_factoryMap.clear(); }
//
//	static Factory * Get() {
//		static Factory inst;
//		return &inst;
//	}
//
//	void Register(const std::string& plantName, Plant::CreatePlantFunc pfnCreate);
//	Factory* CreatePlant(const std::string& plantName);
private:
	typedef std::map<std::string, Plant::CreatePlantFunc *> FactoryMap;
	FactoryMap myFactoryMap;

public:

	Plant * createPlant(std::string t, std::string n, std::vector<bool> in, std::vector<bool> out, std::vector<bool> harv, std::vector<bool> r, std::vector<bool> p, float d, bool m, bool pm, bool pr);
};

#endif FACTORY_HPP_