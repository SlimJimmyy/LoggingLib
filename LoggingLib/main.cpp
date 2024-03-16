#include "Logging.h"




int main() {
	UserLog UserLogs = {};
	//DeveloperLog DevLog = {};
	std::string licenseKey = "*****232&&a4-x2343r=g";
	std::string webhook = "https://discord.com/api/webhooks/1217383494901170236/-BKLSa6dmlWkQHA5qvU8cJZ7hb1koP9YYfhauIhzqguPXsRx7BUEc-GRK7Dptd-8f9os";
	UserLogs.InitLogEventsToWebhook(webhook, licenseKey);
	UserLogs.Failure("Wapow u like hit an error and what not",true,false);
	
	

	Sleep(5000);
	
	return 0;
}


