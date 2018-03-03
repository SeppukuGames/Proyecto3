#include <OgreRoot.h>

class ProyectoBasico
{
public:

	ProyectoBasico();
	virtual ~ProyectoBasico();

	bool go();

private:
	Ogre::Root* mRoot;
	Ogre::String mResourcesCfg;
	Ogre::String mPluginsCfg;
	Ogre::String name, locType;//Informacion del archivo de configuracion parseado
};