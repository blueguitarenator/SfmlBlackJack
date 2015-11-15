#include "ResourceLoader.h"

using namespace std;

const string ResourceLoader::ARCON_FONT = "Arcon-Regular.otf";
const string ResourceLoader::REISLING_FONT = "riesling.ttf";

const string ResourceLoader::FELT = "felt.png";
const string ResourceLoader::CHIPS = "chips.png";
const string ResourceLoader::CARD_BACK = "back.png";

ResourceLoader::ResourceLoader()
{
}


ResourceLoader::~ResourceLoader()
{
}

void ResourceLoader::loadFont(sf::Font& font, const std::string& fontName)
{
	if (!font.loadFromFile(fontName))
	{
		throw "Font not found: " + fontName;
	}
}

void ResourceLoader::loadTexture(sf::Texture& texture, const std::string& filename)
{
	if (!texture.loadFromFile(filename))
	{
		throw "Could not load: " + filename;
	}
}