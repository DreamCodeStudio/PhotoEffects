#include "BlackWhiteShader.h"

void BlackWhiteShader::ProcessImage(std::string ImagePath)
{
	std::cout << "Running BlackWhite Shader v.1.0" << std::endl;

	sf::Image image;
	if (!image.loadFromFile(ImagePath))
	{
		std::cout << "Unable to load image: '" << ImagePath << "'" << std::endl;
		return;
	}

	sf::Image newImage;
	newImage.create(image.getSize().x, image.getSize().y);
	for (unsigned int y = 0; y < image.getSize().y; y++)
	{
		for (unsigned int x = 0; x < image.getSize().x; x++)
		{
			int AverageBrightness = (static_cast<int>(image.getPixel(x, y).r) + static_cast<int>(image.getPixel(x, y).g) + static_cast<int>(image.getPixel(x, y).b)) / 3;
			newImage.setPixel(x, y, sf::Color(AverageBrightness, AverageBrightness, AverageBrightness));
		}
	}

	int position = ImagePath.find_last_of('.');
	ImagePath.insert(ImagePath.begin() + position, '1');
	newImage.saveToFile(ImagePath);
}