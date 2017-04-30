//#ifndef FACTORY_HPP_
//#define FACTORY_HPP_
//
//#include <map>
//#include <boost/any.hpp>
//#include "Plant.hpp"
//
//class Factory {
//private:
//	Factory();
//	Factory(const Factory& f);
//	Factory& operator=(const Factory& f) { return *this; }
//	
//	typedef std::map<boost::any, boost::any> factoryMap;
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
//
//};
//
//#endif FACTORY_HPP_