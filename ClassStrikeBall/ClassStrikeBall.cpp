#include "stdafx.h"
#include "CBaseBall.h"

int main()
{
	CBaseBall* MyBaseBall = new CBaseBall();
	MyBaseBall->GetRandNumProc();

	while (1) {
		MyBaseBall->GetUserInputProc();

		if (MyBaseBall->CheckResult()) {
			std::wcout << L"--------end--------" << std::endl;
			break;
		}
	}

	delete MyBaseBall;

    return 0;
}

