#include "ImageLoaderManager.h"
#include "../Image.h"

using namespace GEI;
using namespace Loader;

ImageLoaderManager* ImageLoaderManager::Instance()
{
	if (_instance == nullptr)
		_instance = new ImageLoaderManager();

	return _instance;
}

ImageLoaderManager::ImageLoaderManager()
{

}

ImageLoaderManager::~ImageLoaderManager()
{

}

bool ImageLoaderManager::Save(Image* image)
{
	return false;
}

bool ImageLoaderManager::Load(Image* image)
{
	return false;
}