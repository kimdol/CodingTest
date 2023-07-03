#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

class RoomAssignment
{
private:
	class Schedule
	{
	public:
		int mStart;
		int mEnd;

	public:
		bool operator <(Schedule& s) const
		{
			if (mEnd == s.mEnd)
			{
				return mStart < s.mStart;
			}
			return mEnd < s.mEnd;
		}
	};

private:
	int N;
	int mResult;
	std::vector<Schedule> mvSchedule;

public:
	RoomAssignment()
		: N{}, mResult{ 0 }, mvSchedule{}
	{

	}
	~RoomAssignment()
	{

	}

public:
	void Input()
	{
		std::cin >> N;

		for (int i = 0; i < N; i++)
		{
			Schedule schd;
			std::cin >> schd.mStart >> schd.mEnd;
			mvSchedule.push_back(schd);
		}

	}
	void Output()
	{
		AssignmentCalculation();
		std::cout << mResult << std::endl;
	}

private:
	void AssignmentCalculation()
	{
		std::sort(mvSchedule.begin(), mvSchedule.end());
		// 제일 작은 End Time을 가진 스케쥴을 찾아서 기억하라
		int pick{};
		if (N > 0)
		{
			pick = mvSchedule[0].mEnd;
			mResult++;
		}
		// 고른 스케쥴의 End time보다 큰 스케쥴이 없을 때 까지 무한반복
		for(int i = 1; i < N; i++)
		{
			// pick이 start time보다 작나? 아니네 다음 스케쥴로 넘어가서 어 맞네 그러면 end부터 시작해야지
			if (pick <= mvSchedule[i].mStart)
			{
				pick = mvSchedule[i].mEnd;
				mResult++;
			}
		}
	}
};

int main()
{
	RoomAssignment ra;

	ra.Input();
	ra.Output();

}
