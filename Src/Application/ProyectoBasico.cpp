#include "ProyectoBasico.h"
#include <OgreConfigFile.h>
#include <OgreException.h>


ProyectoBasico::ProyectoBasico() : mRoot(0), mResourcesCfg(Ogre::StringUtil::BLANK), mPluginsCfg(Ogre::StringUtil::BLANK)
{
}

ProyectoBasico::~ProyectoBasico()
{
	delete mRoot;
}

bool ProyectoBasico::go()
{
#ifdef _DEBUG
	mResourcesCfg = "resources_d.cfg";
	mPluginsCfg = "plugins_d.cfg";
#else
	mResourcesCfg = "resources.cfg";
	mPluginsCfg = "plugins.cfg";
#endif

	mRoot = new Ogre::Root(mPluginsCfg);

	//Parsea nuestro cfg de resources
	Ogre::ConfigFile cf;
	cf.load(mResourcesCfg);

	//Nos permite iterar por las secciones descubiertas por el parseador
	Ogre::ConfigFile::SectionIterator secIt = cf.getSectionIterator();

	while (secIt.hasMoreElements())
	{
		//Preguntamos si hay otro iterador que nos deje iterar a través de los objetos de cada sección
		Ogre::ConfigFile::SettingsMultiMap* settings = secIt.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator it;

		//Escanear cada item (multimap)
		//Esto nos sirve para que Ogre sepa dónde buscar los recursos, pero no los inicializa
		for (it = settings->begin(); it != settings->end(); ++it)
		{
			locType = it->first;
			name = it->second;
			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, locType);
		}
	
	}


	return true;
}



