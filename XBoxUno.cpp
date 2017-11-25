// XBoxUno.cpp : main project file.

#include "stdafx.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;
using namespace System;
using namespace System::IO::Ports;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480



int main()
{



	GLFWwindow *window;

	// Initialize the library
	if (!glfwInit())
	{
		return -1;
	}

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "XBox Controller", NULL, NULL);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	glViewport(0.0f, 0.0f, screenWidth, screenHeight); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
	glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
	glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); // essentially set coordinate system
	glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
	glLoadIdentity(); // same as above comment



					  // Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		int present = glfwJoystickPresent(GLFW_JOYSTICK_1);
		//cout << present << endl;

		if (1 == present)
		{
			int axesCount;
			const float *axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);

			//cout << round(axes[1]) << endl; //Выводит 0, 1 или -1 (Y левого стика) 
			
			SerialPort port("COM3", 9600);
			port.Open();
			
			//int input = Convert::ToInt32(Console::ReadLine());
			int input2 = Convert::ToInt32(round(axes[1]));
			if (input2 == 1)
				port.Write("A");
			else
				port.Write("b");
			

		}

		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();










	return 0;
}