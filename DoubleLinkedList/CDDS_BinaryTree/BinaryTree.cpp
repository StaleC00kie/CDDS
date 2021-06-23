#include "BinaryTree.h"
#include "TreeNode.h"

#include <iostream>
#include <cstdlib>

#ifdef  USE_RAYLIB
#include "raylib.h"
#endif //  USE_RAYLIB

using namespace std;


BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while(m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const 
{ 
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
bool BinaryTree::Insert(int a_nValue)
{
	TreeNode* pParent = nullptr;

	if (IsEmpty())
	{
		m_pRoot = new TreeNode(a_nValue);
		return true;
	}
	else
	{
		TreeNode* pCurrent = m_pRoot;

		while (pCurrent)
		{
			pParent = pCurrent;

			if (a_nValue == pCurrent->GetData())
			{
				return false;
			}
			else if (a_nValue > pCurrent->GetData())
			{
				pCurrent = pCurrent->GetRight();
			}
			else
			{
				pCurrent = pCurrent->GetLeft();
			}
		}

		if (a_nValue > pParent->GetData())
		{
			pParent->SetRight(new TreeNode(a_nValue));
		}
		else
		{
			pParent->SetLeft(new TreeNode(a_nValue));
		}

		return true;
	}
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& pCurrent, TreeNode*& pParent)
{

	if (IsEmpty())
	{
		return false;
	}

	pCurrent = m_pRoot;
	pParent = nullptr;

	while (pCurrent != nullptr)
	{
		if (a_nSearchValue == pCurrent->GetData())
		{
			return true;
		}
		else
		{
			pParent = pCurrent;

			if (a_nSearchValue > pCurrent->GetData())
			{
				pCurrent = pCurrent->GetRight();
			}
			else
			{
				pCurrent = pCurrent->GetRight();
			}
		}
	}

	return false;
}

bool BinaryTree::Remove(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	if (!FindNode(a_nValue, pCurrent, pParent))
	{
		return false;
	}

	if (pCurrent->HasRight())
	{
		TreeNode* pMinNode = pCurrent->GetRight();
		TreeNode* pMinParent = pCurrent;

		while (pMinNode->HasLeft())
		{
			pMinParent = pMinNode;
			pMinNode = pMinNode->GetLeft();
		}

		pCurrent->SetData(pMinNode->GetData());

		if (pMinParent->GetLeft() == pMinNode)
		{
			pMinParent->SetLeft(pMinNode->GetRight());
		}
		else
		{
			pMinParent->SetRight(pMinNode->GetRight());
		}

		delete pMinNode;
	}
	else
	{
		if (pParent)
		{
			if (pParent->GetLeft() == pCurrent)
			{
				pParent->SetLeft(pCurrent->GetLeft());
			}
			else
			{
				pParent->SetRight(pCurrent->GetLeft());
			}
		}
		else
		{
			m_pRoot = pCurrent->GetLeft();

			delete pCurrent;
		}
	}

	return true;
}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
    PrintUnorderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
#ifdef  USE_RAYLIB
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);

			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
#endif //  USE_RAYLIB



}