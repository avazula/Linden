#include "Factory.hpp"

//Factory::Factory() {
//	Register("Fruit", &Fruit::Create);
//	Register("Herb", &Herb::Create);
//	Register("Legume", &Legume::Create);
//	Register("Vegetable", &Vegetable::Create);
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
//		return *it.second();
//	}
//	return NULL;
//}

Plant * Factory::createPlant(std::string t, std::string n, std::vector<bool> in, std::vector<bool> out, std::vector<bool> harv, std::vector<bool> r, std::vector<bool> p, float d, bool m, bool pm, bool pr)
{
	if (t == "herb") return Herb::Create(n, in, out, harv, pr);
	if (t == "fruit") return Fruit::Create(n, in, out, harv, r, p, m, pm);
	if (t == "vegetable") return Vegetable::Create(n, in, out, harv, d, m, pm);
	if (t == "legume") return Legume::Create(n, in, out, harv, m);
	else return nullptr;
}
