#pragma once
#include <Windows.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

class discord {
public:
	/*IDK if this is like considered malware due to not asking user/s
	if they consent, so if you use this, you should totally ask them for permission
	im not releasing source to this cause im not 100% sure, probably will in future.
	once i do more research! I'd love to release it cause its pre cool.
	*/
	std::string GetDiscordUsernameFromRPC(bool user, bool ID); 

};