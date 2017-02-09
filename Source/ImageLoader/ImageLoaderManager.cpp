#include "ImageLoaderManager.h"
#include "BMPImageLoader.h"
#include "../Image.h"
#include "../Filetypes.h"

using namespace GEI;
using namespace Loader;

ImageLoaderManager* ImageLoaderManager::m_instance = nullptr;

ImageLoaderManager* ImageLoaderManager::Instance()
{
	if (m_instance == nullptr)
		m_instance = new ImageLoaderManager();

	return m_instance;
}

ImageLoaderManager::ImageLoaderManager()
{
	bmpLoader = new BMPImageLoader();
}

ImageLoaderManager::~ImageLoaderManager()
{
	delete bmpLoader;
}

bool ImageLoaderManager::Save(Image* image)
{
	switch (image->GetFileType())
	{
	case Filetype::BMP:
		bmpLoader->Save(image);
		break;

	case Filetype::NOTDEFINED:
		//TODO: Throw error;
		return false;

	default:
		//TODO: Throw error
		return false;
	}

	return false;
}

bool ImageLoaderManager::Load(Image* image)
{
	switch (image->GetFileType())
	{
	case Filetype::BMP:
		return bmpLoader->Load(image);
		break;

	case Filetype::NOTDEFINED:
		//TODO: Throw error;
		return false;

	default:
		//TODO: Throw error
		return false;
	}
}