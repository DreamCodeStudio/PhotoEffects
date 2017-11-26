#include "ColorShader.h"

void ColorShader::ProcessImage(std::string ImagePath, int Intensity)
{
	std::cout << "Running Color Shader v.1.0 with Intensity: " << Intensity << std::endl;
	sf::Image image, newImage;

	/* Try to load image */
	if (!image.loadFromFile(ImagePath))
	{
		std::cout << "Unable to load image: '" << ImagePath << "'" << std::endl;
		return;
	}

	newImage.create(image.getSize().x, image.getSize().y); //Create new empty image

														   /* Process the whole image */
	for (int y = 0; y < static_cast<int>(image.getSize().y); y++)
	{
		for (int x = 0; x < static_cast<int>(image.getSize().x); x++)
		{
			/* Get averrage color value of all nearby pixels */
			int red = 0;
			int green = 0;
			int blue = 0;

			/* Get the averrage values */
			for (int ay = y - Intensity; ay < y + Intensity; ay++)
			{
				for (int ax = x - Intensity; ax < x + Intensity; ax++)
				{
					if (ax < 0 || ay < 0 || ax > static_cast<int>(image.getSize().x) - 1 || ay > static_cast<int>(image.getSize().y) - 1)
					{
						red = red + static_cast<int>(image.getPixel(x, y).r);
						green = green + static_cast<int>(image.getPixel(x, y).g);
						blue = blue + static_cast<int>(image.getPixel(x, y).b);
					}
					else
					{
						red = red + static_cast<int>(image.getPixel(ax, ay).r);
						green = green + static_cast<int>(image.getPixel(ax, ay).g);
						blue = blue + static_cast<int>(image.getPixel(ax, ay).b);
					}
				}
			}

			newImage.setPixel(x, y, sf::Color(red, green, blue));
		}
	}

	int position = ImagePath.find_last_of('.');
	ImagePath.insert(ImagePath.begin() + position, '1');
	newImage.saveToFile(ImagePath);

}