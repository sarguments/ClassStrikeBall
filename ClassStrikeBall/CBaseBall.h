#pragma once

class CBaseBall
{
public:
	CBaseBall();
	~CBaseBall();

	// ���� ���ؼ� ���Ϳ� �ֱ�
	void GetRandNumProc(void);

	// ����� �Է� �������� 3���� �и��ؼ� ���Ϳ� �ֱ�
	bool GetUserInputProc(void);

	// ��Ʈ����ũ, �� ����
	bool CheckResult(void);

	// ��� ���
	void PrintResult(void);

private:
	int generateRand(void);
	int getUniqueRand(void);

	bool inputVectorProc(std::vector<int>& vectorParam, int param);

	// ���� & �ߺ� üũ
	bool outOfRange(int param);
	bool isDupclicate(std::vector<int>& vectorParam, int param);

	bool isInputVaild(int userInput);
	int getUserInput(void);
	bool splitToVector(int userInput);

	bool countStrike(void);
	bool countBall(void);

	// �迭�� Ư�� �ε���<����> ��� ���� �ִ���
	int valueInVector(std::vector<int>& inputVector, int idx, int value);

private:
	std::vector<int> _randVector;
	std::vector<int> _userInputVector;

	int _strike;
	int _ball;

	const int BALL_NUMS = 3;
};