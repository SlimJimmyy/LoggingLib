#pragma once
#include <boost/asio/ip/host_name.hpp>
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <source_location>s
#include <functional>
#include <curl/curl.h>
#include <wininet.h>
#include <filesystem>
#include <lmcons.h> 
#include <fstream>
#include "discord.h"
class UserLog {
private: 
	bool LogEventsToWebhook;
	std::string URL;
	std::string userKey;
	bool ID;
	bool userID;

public:
	// A function to allow for error logging, this only enables failure to send failures to webhook as well as reverse attempts!, i doubt you'd want to be spammed by success and warnings
	void InitLogEventsToWebhook(std::string WebhookURL, std::string LicenseKey);


	// A general printing function which strives to seem neutral and conform to a theme
	void Log(const std::string Message);
	// A Self Called/Defined Succes, Use when you know something has been properly used.
	void Success(const std::string Message);
	// A Self Called/Defined Failure, Use when you know something has been improperly used.
	void Failure(const std::string Message, bool userid, bool id);
	// A Global Program Warning For Anything 
	void Warning(const std::string Message); 
	// User Instruction They Should Follow
	void Instruction(const std::string Message);

	// Run this when your protection(if any) is triggered to run.
	//void ReverseAttempt(const std::string MessageToWebhook, std::string URL, std::string Field);

	/*
	This is an example of what your "Field" string can look like. This is what will be sent the the webhook! 
	NOTE:THIS EXAMPLE IS SPECIFICALLY MADE FOR DISCORD, BUT WILL WORK WITH ANY WEBHOOK AS LONG AS YOU STRUCTURE THE FIELD DATA CORRECTLY
	"{\"content\": null,\"embeds\": [{\"title\":\"YOUR TITLE HERE\",\"description\":\"YOUR DESCRIPTION HERE\",\"color\": 2444}],\"attachments\": []}";
	The URL is for the webhook url!
	*/
	void SendToWebhook(std::string URL, std::string Field);

	//Gets external ip address by accessing a webLink that returns the external IP
	std::string GetIp(); 


};
/*
USERSIDE EXAMPLES

	Due to the prolific nature of this statement
	Listener aggression is advised 

	std::string URL = "https://discord.com/api/webhooks/1217383494901170236/-BKLSa6dmlWkQHA5qvU8cJZ7hb1koP9YYfhauIhzqguPXsRx7BUEc-GRK7Dptd-8f9os";
	std::string title = "title";
	std::string description = "description";
	std::string color = "16724735"; //https://www.mathsisfun.com/hexadecimal-decimal-colors.html link to help u decide your lil colors
	std::string content = "";

	std::string field = "{\"content\": " + std::string("\"") + content + "\"" + "," + "\"embeds\": " + "[{\"title\": " + "\"" + title + "\"" + "," + "\"description\":" + "\"" + description + "\"" + "," + "\"color\": " + "\"" + color + "\"" + "}]}";
	UserLogs.SendToWebhook(URL, field);




	// INIT EVENT LOGGING TO DISCORD WEBHOOK/MOST WEBHOOKS

	UserLog UserLogs = {};
	std::string licenseKey = "KEY HERE";
	std::string webhook = "WEBHOOK HERE";
	UserLogs.InitLogEventsToWebhook(webhook, licenseKey);
	UserLogs.Failure("TEXT TO BE DISPLAYED TO USER");


*/




class DeveloperLog {
private: 
	bool DevMode;
public:
	
	void InitDevMode();

	
	void Log(const std::string Message);
	void Success(const std::string Message);
	void Failure(const std::string Message);

	//Call this inside of a function you want the name logged
	void LogFunction(const std::source_location& Func = std::source_location::current()); 


};
