#include "TreeNode.h"

#ifdef  USE_RAYLIB
#include "raylib.h"
#endif //  USE_RAYLIB
#include <string>

TreeNode::TreeNode(int value) : m_value(value), m_left(nullptr), m_right(nullptr)
{
}


TreeNode::~TreeNode()
{
}

void TreeNode::Draw(int x, int y, bool selected)
{
#ifdef USE_RAYLIB
	static char buffer[10];

	sprintf(buffer, "%d", m_value);

	DrawCircle(x, y, 30, YELLOW);

	if (selected == true)
		DrawCircle(x, y, 28, GREEN);
	else
		DrawCircle(x, y, 28, BLACK);


	DrawText(buffer, x - 12, y - 10, 12, WHITE);
#endif // USE_RAYLIB


}