#include "SketchShader.h"

void SketchShader::ProcessImage(std::string ImagePath, int Intensity)
{
	std::cout << "Running Sketch Shader v.1.0 with Intensity: " << Intensity << std::endl;
	
	sf::Image image;
	if (image.loadFromFile(ImagePath) != true) //Try to load image from file
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
			newImage.setPixel(x, y, sf::Color(255, 255, 255));

			if (x > 0 && y > 0 && x + 1 < image.getSize().x && y + 1 < image.getSize().y)
			{
				if (abs(static_cast<int>(image.getPixel(x, y - 1).r) - static_cast<int>(image.getPixel(x, y).r)) > Intensity)
				{
					newImage.setPixel(x, y, sf::Color(0, 0, 0));
				}
				if (abs(static_cast<int>(image.getPixel(x + 1, y - 1).r) - static_cast<int>(image.getPixel(x, y).r)) > Intensity)
				{
					newImage.setPixel(x, y, sf::Color(0, 0, 0));
				}
				if (abs(static_cast<int>(image.getPixel(x + 1, y).r) - static_cast<int>(image.getPixel(x, y).r)) > Intensity)
				{
					newImage.setPixel(x, y, sf::Color(0, 0, 0));
				}
				if (abs(static_cast<int>(image.getPixel(x + 1, y + 1).r) - static_cast<int>(image.getPixel(x, y).r)) > Intensity)
				{
					newImage.setPixel(x, y, sf::Color(0, 0, 0));
				}
				if (abs(static_cast<int>(image.getPixel(x, y + 1).r) - static_cast<int>(image.getPixel(x, y).r)) > Intensity)
				{
					newImage.setPixel(x, y, sf::Color(0, 0, 0));
				}
				if (abs(static_cast<int>(image.getPixel(x - 1, y + 1).r) - static_cast<int>(image.getPixel(x, y).r)) > Intensity)
				{
					newImage.setPixel(x, y, sf::Color(0, 0, 0));
				}
				if (abs(static_cast<int>(image.getPixel(x - 1, y).r) - static_cast<int>(image.getPixel(x, y).r)) > Intensity)
				{
					newImage.setPixel(x, y, sf::Color(0, 0, 0));
				}
				if (abs(static_cast<int>(image.getPixel(x - 1, y - 1).r) - static_cast<int>(image.getPixel(x, y).r)) > Intensity)
				{
					newImage.setPixel(x, y, sf::Color(0, 0, 0));
				}
			}

		}
	}

	int position = ImagePath.find_last_of('.');
	ImagePath.insert(ImagePath.begin() + position, '1');
	newImage.saveToFile(ImagePath);
}