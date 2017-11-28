#include <iostream>

/* Shaders */
#include "Shaders\BlurShader\BlurShader.h"
#include "Shaders\ColorShader\ColorShader.h"
#include "Shaders\SketchShader\SketchShader.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Use -help for a list of parameters!" << std::endl;
		return 1;
	}

	/* Check the parameter */
	if (strcmp(argv[1], "-help") == 0)		//Show list of parameters
	{
		std::cout << "PhotoEffects <Path to image> <Shader option> <Intensity>" << std::endl;
		std::cout << std::endl;
		std::cout << "<Shader option>: " << std::endl;
		std::cout << "-b	(Blur Shader)	Add some unsharpness to the image" << std::endl;
		std::cout << "-c	(Color Shader)  Summerizes color values to create a colorful image" << std::endl;
		std::cout << "-s	(Sketch Shader)	Will only show the outlines of the image" << std::endl;
		std::cout << std::endl;
		std::cout << "<Intensity>" << std::endl;
		std::cout << "For Blur Shader: The radius in which pixels influence there adjacent" << std::endl;
		std::cout << "For Color Shader: The radius in which the pixels' color values are summerized (Using values higher than 1 will end in a strange looking unusable image)" << std::endl;
		return 1;
	}

	/* Check if user has entered enough parameter to process a image */
	if (argc < 3)
	{
		std::cout << "Use -help for a list of parameters!" << std::endl;
		return 1;
	}

	/* If the user wants to use the Blur Shader... */
	if (strcmp(argv[2], "-b") == 0)
	{
		int Intensity = 5;				//Set Intensity to default value 
		if (argc >= 4)
		{
			Intensity = atoi(argv[3]); // If the user has set the intensity use it 
		}

		BlurShader::ProcessImage(argv[1], Intensity);
		return 1;
	}

	/* If the user wants to use the Color Shader... */
	if (strcmp(argv[2], "-c") == 0)
	{
		int Intensity = 1;				//Set Intensity to default value 
		if (argc >= 4)
		{
			Intensity = atoi(argv[3]); // If the user has set the intensity use it 
		}

		ColorShader::ProcessImage(argv[1], Intensity);
		return 1;
	}
	
	/* If the user wants to use the Sketch Shader */
	if (strcmp(argv[2], "-s") == 0)
	{
		int Intensity = 20;				//Set Intensity to default value 
		if (argc >= 4)
		{
			Intensity = atoi(argv[3]); // If the user has set the intensity use it 
		}

		SketchShader::ProcessImage(argv[1], Intensity);
		return 1;
	}

	std::cout << "Use -help for a list of parameters!" << std::endl;
	return 0;
}