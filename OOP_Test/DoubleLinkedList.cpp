#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() : mHead{ nullptr }, mTail{ nullptr }
{
}

DoubleLinkedList::~DoubleLinkedList()
{
	DeleteAll();
}

Monster* DoubleLinkedList::CreateMonster(std::string name, int hp)
{
	Monster* elem = new Monster{ name, hp, nullptr };

	if (mTail == nullptr)
	{
		mHead = elem;
		mTail = elem;
	}
	else
	{
		elem->prev = mTail;
		mTail->nxt = elem;
		mTail = elem;
	}

	return elem;
}

void DoubleLinkedList::PrintMonsters()
{
	Monster* element{ mHead };

	std::cout <<
		"================================"
		<< std::endl;
	// Traverse
	while (element != nullptr)
	{
		std::cout << element->name << " : "
			<< element->hp << std::endl;
		element = element->nxt;
	}
	std::cout <<
		"================================"
		<< std::endl;
}

Monster* DoubleLinkedList::FindMonster(std::string name)
{
	Monster* element{ mHead };

	// Traverse
	while (element != nullptr)
	{
		if (element->name == name)
		{
			return element;
		}
		element = element->nxt;
	}

	return nullptr;
}

void DoubleLinkedList::DeleteAll()
{
	Monster* element{ mHead };

	// Traverse
	while (element != nullptr)
	{
		Monster* next = element->nxt;
		delete element;

		element = next;
	}

	mHead = mTail = nullptr;
}

bool DoubleLinkedList::Delete(std::string name)
{
	Monster* element{ FindMonster(name) };

	if (element != nullptr)
	{
		if (element->prev == nullptr)
		{
			mHead = element->nxt;
		}
		else
		{
			element->prev->nxt = element->nxt;
		}

		if (element->nxt == nullptr)
		{
			mTail = element->prev;
		}
		else
		{
			element->nxt->prev = element->prev;
		}

		delete element;
		return true;
	}

	return false;
}
