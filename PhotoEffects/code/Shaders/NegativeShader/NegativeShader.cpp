#include "NegativeShader.h"

void NegativeShader::ProcessImage(std::string ImagePath)
{
	std::cout << "Running Negativ Shader v.1.0" << std::endl;

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
			sf::Color pixelColor = image.getPixel(x, y);
			pixelColor = sf::Color(static_cast<int>(255 - pixelColor.r), static_cast<int>(255 - pixelColor.g), static_cast<int>(255 - pixelColor.b));
			newImage.setPixel(x, y, pixelColor);
		}
	}

	int position = ImagePath.find_last_of('.');
	ImagePath.insert(ImagePath.begin() + position, '1');
	newImage.saveToFile(ImagePath);
}