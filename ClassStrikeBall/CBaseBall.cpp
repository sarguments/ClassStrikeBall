#include "stdafx.h"
#include "CBaseBall.h"

CBaseBall::CBaseBall()
{
	srand((unsigned int)time(NULL));

	_randVector.reserve(BALL_NUMS);
	_userInputVector.reserve(BALL_NUMS);
}

CBaseBall::~CBaseBall()
{
}

void CBaseBall::GetRandNumProc(void)
{
	while (_randVector.size() != 3)	{
		// 1 ~ 9 의 유니크한 랜덤값을 구한다.
		int randNum = getUniqueRand();
		inputVectorProc(_randVector, randNum);
	}
}

int CBaseBall::generateRand(void)
{
	return rand() % 9 + 1;
}

int CBaseBall::getUniqueRand(void)
{
	int randNum = generateRand();
	bool isDup = isDupclicate(_randVector, randNum);

	while (isDup) {
		randNum = generateRand();
	}

	return randNum;
}

bool CBaseBall::inputVectorProc(std::vector<int>& vectorParam, int param)
{
	vectorParam.push_back(param);
	return true;
}

bool CBaseBall::outOfRange(int param)
{
	int limit = (int)pow(10, BALL_NUMS);

	if (param < 0 || param >= limit)
		return true;

	if (param < (limit - 1))
		return true;

	return false;
}

bool CBaseBall::isDupclicate(std::vector<int>& vectorParam, int param)
{
	// vectorParam 안에서 param에 해당하는 값이 있는지 검사한다.
	auto iter = std::find(vectorParam.begin(), vectorParam.end(), param);
	if (iter == vectorParam.end())
	{
		// 못찾은 경우
		return false;
	}

	return true;
}

bool CBaseBall::GetUserInputProc(void)
{
	// TODO : 초기화
	_strike = 0;
	_ball = 0;

	int localUserInput = getUserInput();
	splitToVector(localUserInput);

	while (!isInputVaild(localUserInput)) {
		localUserInput = getUserInput();
		splitToVector(localUserInput);
	}

	return true;
}

bool CBaseBall::isInputVaild(int userInput)
{
	if (outOfRange(userInput))
		return false;

	for (int i = 0; i < BALL_NUMS; i++) {
		if (valueInVector(_userInputVector, i, _userInputVector[i]) != -1)
			return false;
	}

	return true;
}

int CBaseBall::getUserInput(void)
{
	int userInput = 0;
	std::wcout << L"input number : ";
	std::wcin >> userInput;
	
	return userInput;
}

bool CBaseBall::splitToVector(int userInput)
{
	_userInputVector.clear();
	int mod = (int)pow(10, BALL_NUMS);
	int divide = mod / 10;

	for (int i = 0; i < BALL_NUMS; i++)	{
		int Num = (userInput % mod) / divide;
		inputVectorProc(_userInputVector, Num);

		mod /= 10;
		divide /= 10;
	}

	return true;
}

bool CBaseBall::CheckResult(void)
{
	countStrike();
	countBall();

	PrintResult();

	if (_strike == 3)
		return true;

	if (_strike == 0 && _ball == 0)
		std::wcout << L"nothing" << std::endl;

	return false;
}

bool CBaseBall::countStrike(void)
{
	for (int i = 0; i < BALL_NUMS; i++)	{
		if (_randVector[i] == _userInputVector[i])
			_strike++;
	}

	return true;
}

bool CBaseBall::countBall(void)
{
	int count = 0;

	for (int i = 0; i < BALL_NUMS; i++)	{
		if (isDupclicate(_randVector, _userInputVector[i]))
			count++;
	}
	_ball = count - _strike;

	return true;
}

void CBaseBall::PrintResult(void)
{
	for (auto i : _randVector) {
		std::wcout << i << std::endl;
	}

	std::wcout << L"---------------------" << std::endl;
	std::wcout << L"strike : " << _strike << L"// ball : " << _ball << std::endl;
}

int CBaseBall::valueInVector(std::vector<int>& inputVector, int idx, int value)
{
	for (int i = 0; i < idx; i++) {
		if (inputVector[i] == value)
			return i;
	}

	return -1;
}
