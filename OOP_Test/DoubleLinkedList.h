#pragma once
#define interface struct
#include <iostream>
#include "Monster.h"

interface List
{
	virtual Monster* CreateMonster(std::string name, int hp) = 0; // Tail �������� Monster �����͸� �߰��ϴ� �Լ��Դϴ�.
	virtual void PrintMonsters() = 0; // List�� ��ȸ�ϸ鼭 Monster �����͵��� ����ϴ� �Լ��Դϴ�.
	virtual Monster* FindMonster(std::string name) = 0; // List�� ��ȸ�ϸ鼭 ���ϴ� Monster �����͸� ã�� �Լ��Դϴ�.
	virtual void DeleteAll() = 0; // List�� ��ȸ�ؼ� ��� Monster �����͵��� �����ϴ� �Լ��Դϴ�.
	virtual bool Delete(std::string name) = 0; // ���ϴ� Monster ������ 1���� �����ϴ� �Լ��Դϴ�.

protected:
	~List() = default;
};

class DoubleLinkedList :
    public List
{
protected:
	Monster* mHead;
	Monster* mTail;

public:
	DoubleLinkedList();
	virtual ~DoubleLinkedList();
	
public:
	Monster* CreateMonster(std::string name, int hp) override;
	void PrintMonsters() override;
	Monster* FindMonster(std::string name) override;
	void DeleteAll() override;
	bool Delete(std::string name) override;
};

