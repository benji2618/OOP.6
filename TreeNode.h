#pragma once
#include <iostream>
#include <string.h>

// מגישים: אילי אזולאי 318249828
// בנימין ללוש 328944657

using namespace std;

#define MAX_CHILDREN 4

template<class T>
class TreeNode {

private:

T* Data;
TreeNode<T>* Parent;
TreeNode<T>* Children[4];
int count;
int Counter;

public:

	TreeNode(TreeNode<T>* parent,T* data):Parent(parent), Data(data), count(1);
	{
		parent->addChild(this);
		for (int i = 0; i < 4; i++)
		{
			Children[i] = nullptr;
		}
		
	};

	TreeNode(T* data):Parent(NULL), Data(data),count(1);
	{
		for (int i = 0; i < 4; i++)
		{
			Children[i] = nullptr;
		}
	}

	~TreeNode(){};

	T* getData() const
	{
		return Data;
	}

	void setData(T* data)
	{
		Data = data;
	}

	void addChild(T* data)
	{
		if (count >= 4)
		{
			cout << "have max child" << endl;
			return;
		}
		TreeNode<T>* Children[count] = new TreeNode<T>(this,data);
	}

	void addChild(TreeNode<T>* newChild)
	{
		if (count >= 4)
		{
			cout << "have max child" << endl;
			return;
		}
		Children[count] = newChild;
	}

	void removeChild() //removes the nodes last entered child or if no children - does nothing
	{
		Children[count] = nullptr;
	}

	TreeNode<T>* findChild(T* data) const // returns ptr or NULL
	{
		for (int i = 0; i < count; i++)
		{
			if (Children[i].Data == data)
			{
				return Children[i];
			}
		}
		return NULL;
	}

	int findChildIndx(T* data) const // returns childs indx or -1
	{
		for (int i = 0; i < count; i++)
		{
			if (Children[i].Data == data)
			{
				return i;
			}
		}
		return -1;
	}
	TreeNode<T>* getChild(int indx) const
	{
		return Children[i];
	}

	TreeNode<T>* getNextChild() const
	{
		TreeNode<T>* Temp = Children[Counter];
		Counter = (Counter + 1) % 4;
		return Temp;
	}

	TreeNode<T>* getPrevChild() const
	{
		TreeNode<T>* Temp = Children[Counter];
		Counter--;
		if (Counter < 0)
		{
			Counter = 3;
		}
		
		return Temp;
	}

	TreeNode<T>* getParent() const
	{
		return Parent;
	}

	void setParent(TreeNode<T>* parent)
	{
		Parent = parent;
	}

	int getNumChildren() const
	{
		return count;
	}

};
