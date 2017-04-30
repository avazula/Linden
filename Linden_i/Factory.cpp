//#include "Factory.hpp"
//
//Factory::Factory() {
//	Register("Fruit", &Fruit::Create);
//
//}
//
//void Factory::Register(const std::string& plantName, Plant::CreatePlantFunc pfnCreate)
//{
//	m_factoryMap[plantName] = pfnCreate;
//}
//
//Factory * Factory::CreatePlant(const std::string & plantName)
//{
//	factoryMap::iterator it = m_factoryMap.find(plantName);
//	if (it != m_factoryMap.end()) {
//		return it->second();
//	}
//	return NULL;
//}
