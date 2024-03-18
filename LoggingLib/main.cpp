#include "Logging.h"


//void Caller(void *func, ...) {
//	//above here i'll run my other code
//
//	//then this is called when i am done
//	func(...);
//}

int main() {
	UserLog UserLogs = {};
	DeveloperLog DevLog = {};
	UserLogs.Log("test print");
	UserLogs.Warning("test print");
	UserLogs.Failure("test print",false,false);
	UserLogs.Success("test print");
	UserLogs.Instruction("test print");
	std::cout << "\n\n";
	DevLog.InitDevMode();
	DevLog.Failure("test print");
	DevLog.Log("test print");
	DevLog.Success("test print");
	
	
	


	
	

	Sleep(5000);
	
	return 0;
}


