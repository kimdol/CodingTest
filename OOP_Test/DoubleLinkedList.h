#pragma once
#define interface struct
#include <iostream>
#include "Monster.h"

interface List
{
	virtual Monster* CreateMonster(std::string name, int hp) = 0; // Tail 방향으로 Monster 데이터를 추가하는 함수입니다.
	virtual void PrintMonsters() = 0; // List를 순회하면서 Monster 데이터들을 출력하는 함수입니다.
	virtual Monster* FindMonster(std::string name) = 0; // List를 순회하면서 원하는 Monster 데이터를 찾는 함수입니다.
	virtual void DeleteAll() = 0; // List를 순회해서 모든 Monster 데이터들을 삭제하는 함수입니다.
	virtual bool Delete(std::string name) = 0; // 원하는 Monster 데이터 1개를 삭제하는 함수입니다.

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

