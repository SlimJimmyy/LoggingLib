#include "Logging.h"
#define SUCCESS "[+] "
#define NEUTRAL "[X] "
#define FAILURE "[!!!] "
#define WARNING "[!] "
#define INSTRUCTION "[*] "
#define DEVMODE "[DEV-MODE] "

void UserLog::Log(const std::string Message) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);

	time_t now = time(0);
	struct tm tstruct;
	char CurTime[80];
	tstruct = *localtime(&now);
	strftime(CurTime, sizeof(CurTime), "%X", &tstruct);
	std::cout << NEUTRAL << "[" << CurTime << "] " << Message << std::endl;

	SetConsoleTextAttribute(hConsole, 9);

}


	

	


void UserLog::Success(const std::string Message) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	time_t now = time(0);
	struct tm tstruct;
	char CurTime[80];
	tstruct = *localtime(&now);
	strftime(CurTime, sizeof(CurTime), "%X", &tstruct);
	std::cout << SUCCESS << "[" << CurTime << "] " << Message << std::endl;

	SetConsoleTextAttribute(hConsole, 9);
}
void UserLog::InitLogEventsToWebhook(std::string WebhookURL,std::string LicenseKey) {	
	URL = WebhookURL;

	if (LicenseKey != "")
		userKey = LicenseKey;

	LogEventsToWebhook = true;

}

void UserLog::Failure(const std::string Message,bool userid, bool id) {
	discord disc = {};
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);

	time_t now = time(0);
	struct tm tstruct;
	char CurTime[80];
	tstruct = *localtime(&now);
	strftime(CurTime, sizeof(CurTime), "%X", &tstruct);

	std::cout << FAILURE << "[" << CurTime << "] " << Message << std::endl;


	SetConsoleTextAttribute(hConsole, 9);
	if (LogEventsToWebhook) {
		std::string title = "APPLICATION FAILURE";
		std::string discordInformation = disc.GetDiscordUsernameFromRPC(!userid, !id);
		std::string description = "User Has Experienced An Application Failure \\nIP: " + std::string("```") + GetIp()+"```" + "\\nLicense Key: " +"```" + userKey + "```" + "\\nPC Name: " + "```" + boost::asio::ip::host_name() + "```" + "Discord Identifier" + "```" + discordInformation + "```";
		std::string color = "16711680"; //https://www.mathsisfun.com/hexadecimal-decimal-colors.html link to help u decide your lil colors
		std::string content = "***Failure***";

		std::string field = "{\"content\": " + std::string("\"") + content + "\"" + "," + "\"embeds\": " + "[{\"title\": " + "\"" + title + "\"" + "," + "\"description\":" + "\"" + description + "\"" + "," + "\"color\": " + "\"" + color + "\"" + "}]}";


		SendToWebhook(URL, field);
		
	}
	
	
	
}
void UserLog::Warning(const std::string Message) {
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);

	time_t now = time(0);
	struct tm tstruct;
	char CurTime[80];
	tstruct = *localtime(&now);
	strftime(CurTime, sizeof(CurTime), "%X", &tstruct);

	std::cout << WARNING << "[" << CurTime << "] " << Message << std::endl;

	SetConsoleTextAttribute(hConsole, 9);
}
void UserLog::Instruction(const std::string Message) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);

	time_t now = time(0);
	struct tm tstruct;
	char CurTime[80];
	tstruct = *localtime(&now);
	strftime(CurTime, sizeof(CurTime), "%X", &tstruct);

	std::cout << INSTRUCTION << "[" << CurTime << "] " << Message << std::endl;

	SetConsoleTextAttribute(hConsole, 9);
}

std::string UserLog::GetIp() {
	HINTERNET net = InternetOpen(L"IP retriever",INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0);
	HINTERNET conn = InternetOpenUrl(net,L"http://myexternalip.com/raw",NULL,0,INTERNET_FLAG_RELOAD,0);
	char buffer[4096];
	DWORD read;

	InternetReadFile(conn, buffer, sizeof(buffer) / sizeof(buffer[0]), &read);
	InternetCloseHandle(net);

	return std::string(buffer, read);

}

void UserLog::SendToWebhook(std::string URL, std::string Field) {

	CURL* curl;
	CURLcode response;
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if (curl) {
		struct curl_slist* headers = nullptr;
		headers = curl_slist_append(headers, "Content-Type: application/json");

		curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, Field.data());
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

		response = curl_easy_perform(curl);

		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();

}

/*template<typename Func, typename... Args>

void forwardArgs(Func func, Args&&... args) {
	if (DevMode){



		func(args...);

	}
	else
		Failure("DevMode Not Enabled");
}*/



/*
DevSideLogs
*/

void DeveloperLog::InitDevMode() {
	DevMode = true;
	SetConsoleTitle(L"Dev Mode");
	Success("Dev Mode Enabled");
	

}

void DeveloperLog::Log(const std::string Message) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);

	time_t now = time(0);
	struct tm tstruct;
	char CurTime[80];
	tstruct = *localtime(&now);
	strftime(CurTime, sizeof(CurTime), "%X", &tstruct);

	std::cout << DEVMODE << "[" << CurTime << "] " << Message << std::endl;

	SetConsoleTextAttribute(hConsole, 9);
}


void DeveloperLog::Success(const std::string Message) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	time_t now = time(0);
	struct tm tstruct;
	char CurTime[80];
	tstruct = *localtime(&now);
	strftime(CurTime, sizeof(CurTime), "%X", &tstruct);

	std::cout << DEVMODE << "[" << CurTime << "] " << Message << std::endl;

	SetConsoleTextAttribute(hConsole, 9);
}


void DeveloperLog::Failure(const std::string Message) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);

	time_t now = time(0);
	struct tm tstruct;
	char CurTime[80];
	tstruct = *localtime(&now);
	strftime(CurTime, sizeof(CurTime), "%X", &tstruct);

	std::cout << DEVMODE << "[" << CurTime << "] " << Message << std::endl;

	SetConsoleTextAttribute(hConsole, 9);
}


void DeveloperLog::LogFunction(const std::source_location& Func) {
	if (DevMode)
		std::cout << Func.function_name() <<" At Line: " << Func.line()<< std::endl;
		
	else 
		Failure("DevMode Not Enabled");
	

}



/*
UserSide Examples

	// INIT EVENT LOGGING TO DISCORD WEBHOOK/MOST WEBHOOKS

	UserLog UserLogs = {};
	std::string licenseKey = "KEY HERE";
	std::string webhook = "WEBHOOK HERE";
	UserLogs.InitLogEventsToWebhook(webhook, licenseKey); 
	UserLogs.Failure("TEXT TO BE DISPLAYED TO USER");


*/