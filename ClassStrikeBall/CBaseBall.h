#pragma once

class CBaseBall
{
public:
	CBaseBall();
	~CBaseBall();

	// 랜덤 구해서 백터에 넣기
	void GetRandNumProc(void);

	// 사용자 입력 받은다음 3개로 분리해서 벡터에 넣기
	bool GetUserInputProc(void);

	// 스트라이크, 볼 판정
	bool CheckResult(void);

	// 결과 출력
	void PrintResult(void);

private:
	int generateRand(void);
	int getUniqueRand(void);

	bool inputVectorProc(std::vector<int>& vectorParam, int param);

	// 범위 & 중복 체크
	bool outOfRange(int param);
	bool isDupclicate(std::vector<int>& vectorParam, int param);

	bool isInputVaild(int userInput);
	int getUserInput(void);
	bool splitToVector(int userInput);

	bool countStrike(void);
	bool countBall(void);

	// 배열의 특정 인덱스<까지> 어떠한 값이 있는지
	int valueInVector(std::vector<int>& inputVector, int idx, int value);

private:
	std::vector<int> _randVector;
	std::vector<int> _userInputVector;

	int _strike;
	int _ball;

	const int BALL_NUMS = 3;
};