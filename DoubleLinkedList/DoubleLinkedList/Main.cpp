#include "DoubleLinkedList.h"
#include "Main.h"
#include "raylib.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{

	// Initialization
  //--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	while (!WindowShouldClose)
	{
		Update();
	}


	return 0;
}

void Main::DisplayMenu()
{
	cout << "Double Linked List: " << endl;

	cout << "S to Add a node to the start" << endl;
	cout << "E to Add a node to the End" << endl;
	cout << "R to Remove a node" << endl;
	cout << "I to Insert a node at a position" << endl;
}

