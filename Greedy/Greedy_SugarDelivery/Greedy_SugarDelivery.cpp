// 내가푼것

#include <iostream>

using namespace std;

class SugarDeliverySystem
{

private:
	const int FIVEKG = 5;
	const int THREEKG = 3;
	int mTotalWeight;
	int mResult;

public:
	SugarDeliverySystem()
		: mTotalWeight{}, mResult{}
	{

	}
	~SugarDeliverySystem()
	{

	}
public:
	void Input()
	{
		cin >> mTotalWeight;
	}
	// 전체 설탕무게에 대하여 3, 5kg 봉지가지고 최소 봉지 수를 출력
	void Output()
	{
		FirstWay();

	}
	// 첫번째 방법
	void FirstWay()
	{
		int cnt{ 0 };
		mResult = mTotalWeight;

		// 무한루프
		while (true)
		{
			// 먼저 5으로 나눈 나머지가 0인지 확인한다.
			if (mResult % FIVEKG)
			{
				// 0이 아니면 일단 3를 뺀 나머지를 뱉어내고 카운트센다.
				mResult -= THREEKG;
				cnt++;
				if (mResult == 0)
				{
					cout << cnt;
					break;
				}
				else if (mResult < 0)
				{
					cout << -1;
					break;
				}
			}
			else
			{
				// 참이면 5으로 나눈 값 + 카운트센것을 출력한다.
				cout << mResult / FIVEKG + cnt;
				break;
			}
		}
	}

};

int main()
{
	SugarDeliverySystem sds;
	sds.Input();
	sds.Output();
}

/*
#include <stdio.h>
#include <algorithm>


using namespace std;

int memo[5002] = { 0, };

int sultang(int s) {
	if (s < 0) {
		return 200000000;
	}
	if (s == 0) {
		return 0;
	}
	if (memo[s] != 0) {
		return memo[s];
	}
	else {
		memo[s] = min(sultang(s - 3), sultang(s - 5)) + 1;
		return memo[s];
	}
}

int main() {
	int s;
	scanf("%d", &s);
	int m = sultang(s);
	if (m >= 200000000) {
		m = -1;
	}
	printf("%d", m);
}
*/