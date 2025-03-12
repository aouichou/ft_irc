/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Marvin.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:55:57 by aouichou          #+#    #+#             */
/*   Updated: 2024/02/02 06:33:32 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"
#include "Monitorer.hpp"
#include <string.h>

static std::string extractOperators(const std::string& users)
{
    std::istringstream iss(users);
    std::string user;
    std::string operators;
    while (iss >> user)
	{
        if (user[0] == '@')
		{
            user = user.substr(1);
            if (!operators.empty())
			{
                operators += ' ';
            }
            operators += user;
        }
    }
    return operators;
}

static std::string fillIt(std::string str, size_t len)
{
	if (str.length() < len)
		str.insert(str.end(), len - str.length(), ' ');
	else
	{
		str.erase(str.begin() + len - 1, str.end());
		str.append(".");
	}
	return (str);
};

static std::string	_getBotMessage()
{
	std::string Greeting = BLUE;
	Greeting.append("\n\n\n\n\n\n\n██████████████████████████████████████████████████████████████████████████████████\n");
	Greeting.append("█                                                                                █\n");
	Greeting.append("█           ███╗   ███╗   █████╗   ██████╗   ██╗   ██╗  ██╗  ███╗   ██╗          █\n");
	Greeting.append("█           ████╗ ████║  ██╔══██╗  ██╔══██╗  ██║   ██║  ██║  ████╗  ██║          █\n");
	Greeting.append("█ ████╗     ██╔████╔██║  ███████║  ██████╔╝  ██║   ██║  ██║  ██╔██╗ ██║   ████╗  █\n");
	Greeting.append("█ ╚═══╝     ██║╚██╔╝██║  ██╔══██║  ██╔══██╗  ╚██╗ ██╔╝  ██║  ██║╚██╗██║   ╚═══╝  █\n");
	Greeting.append("█           ██║ ╚═╝ ██║  ██║  ██║  ██║  ██║   ╚████╔╝   ██║  ██║ ╚████║          █\n");
	Greeting.append("█           ╚═╝     ╚═╝  ╚═╝  ╚═╝  ╚═╝  ╚═╝    ╚═══╝    ╚═╝  ╚═╝  ╚═══╝          █\n");
	Greeting.append("█                                                                                █\n");
	Greeting.append("█             ▒█░▒█ ▒█▀▀▀ ▒█░░░ ▒█▀▀█      ▒█▀▄▀█ ▒█▀▀▀ ▒█▄░▒█ ▒█░▒█             █\n");
	Greeting.append("█             ▒█▀▀█ ▒█▀▀▀ ▒█░░░ ▒█▄▄█      ▒█▒█▒█ ▒█▀▀▀ ▒█▒█▒█ ▒█░▒█             █\n");
	Greeting.append("█             ▒█░▒█ ▒█▄▄▄ ▒█▄▄█ ▒█░░░      ▒█░░▒█ ▒█▄▄▄ ▒█░░▀█ ░▀▄▄▀             █\n");
	Greeting.append("█                                                                                █\n");
	Greeting.append("██████████████████████████████████████████████████████████████████████████████████\n");
	Greeting.append(BLUE "█                                                                                █\n");
	Greeting.append(BLUE "█\t" RED " Usage: MARVIN [COMMAND_NUMBER] [MORE_OPTIONS]" BLUE "\r\t\t\t\t\t\t\t\t\t\t █\n");
	Greeting.append(BLUE "█\t How Can I Help You: (You can use The following list of commands)\r\t\t\t\t\t\t\t\t\t\t █\n");
	Greeting.append(BLUE "█\t " CYAN "[0]" RESET " : to List all Your stats" BLUE "\r\t\t\t\t\t\t\t\t\t\t █\n");
	Greeting.append(BLUE "█\t " CYAN "[1]" RESET " : to List all Your Joined Channels" BLUE "\r\t\t\t\t\t\t\t\t\t\t █\n");
	Greeting.append(BLUE "█\t " CYAN "[2]" RESET " : to see How many user online" BLUE "\r\t\t\t\t\t\t\t\t\t\t █\n");
	Greeting.append(BLUE "█\t " CYAN "[3]" RESET " : to List all Channels in Server" BLUE "\r\t\t\t\t\t\t\t\t\t\t █\n");
	Greeting.append(BLUE "█\t " CYAN "[4]" RESET " : to List stats of specific Channel" BLUE "\r\t\t\t\t\t\t\t\t\t\t █\n");
	Greeting.append(BLUE "█\t " CYAN "[5]" RESET " : to List Infos about the Server" BLUE "\r\t\t\t\t\t\t\t\t\t\t █\n");
	Greeting.append(BLUE "█                                                                                █\n");
	Greeting.append(BLUE "██████████████████████████████████████████████████████████████████████████████████\n\n\n\n");
	Greeting.append(RESET);
	return (Greeting);
};

static std::string	getAllChannels(User *user)
{
	
	std::string channels(YELLOW "█████████████████████████████████████████████████████████████████████████████████████████\n");
	channels.append("███████████████████████████████"BOLD"  All channels joined"RESET YELLOW" ████████████████████████████████████\n");
	channels.append("█████████████████████████████████████████████████████████████████████████████████████████\n");
	channels.append("█              █              █                      █                                  █\n");
	channels.append("█" RESET " Channel Name " YELLOW "█ " RESET "Online Users " YELLOW "█ " RESET "Operators Of Channel" YELLOW " █" RESET "          Channel Topic          " YELLOW " █\n");
	channels.append("█              █              █                      █                                  █\n");
	channels.append("█████████████████████████████████████████████████████████████████████████████████████████\n");
	
	t_channels user_channels = user->AllUserChannels();
	t_channels::iterator it = user_channels.begin();
	while (it != user_channels.end())
	{
		channels.append("█              █              █                      █                                  █\n");
		channels.append("█ " RESET + fillIt(it->first, 12));
		
		std::ostringstream oss;
		oss.str(""); 
		oss << it->second->getUserList().size();
		channels.append(YELLOW " █      " RESET + fillIt(oss.str(), 7));
		std::string ops = extractOperators(it->second->getUserList());
		channels.append(YELLOW " █ " RESET + fillIt(ops, 20));
		if (it->second->topic)
		{
			channels.append(YELLOW "   █ " RESET + fillIt(it->second->topic(), 32));
		}
		else
		{
			channels.append(YELLOW " █ " RESET + fillIt("No Topic", 32));
		}
		channels.append(YELLOW " █\n");
		channels.append(YELLOW "█              █              █                      █                                  █\n");
		channels.append("█████████████████████████████████████████████████████████████████████████████████████████\n");
		it++;
	};
	if (user_channels.size() == 0)
	{
		channels.append("█                                                                                       █\n");
		channels.append("█                                 " RESET "YOU JOINED NO CHANNEL" YELLOW "                                 █\n");
		channels.append("█                                                                                       █\n");
		channels.append("█████████████████████████████████████████████████████████████████████████████████████████\n");
	}
	channels.append(RESET "\n\n");
	return (channels);
}

static std::string	getUserInfo(User *user)
{
	std::string	userInfo;
	userInfo.append("User Name: " + user->user_name.get() + "\n");
	userInfo.append("Full Name: " + user->real_name.get() + "\n");
	userInfo.append("Nick Name: " + user->nick_name + "\n");
	userInfo.append("Host: " + user->host_name.get() + "\n");

	t_channels channels = user->AllUserChannels();
	t_channels::iterator it = channels.begin();
	std::string channelList;
	while (it != channels.end())
	{
		channelList.append(it->first + " ");
		it++;
	}
	std::ostringstream oss;
	oss.str(""); 
	oss << channels.size();
	userInfo.append("Joined Channels: " + oss.str() + "\n");
	userInfo.append("\n");
	return (userInfo);
};

static std::string _channelInfo(User *user, Channel *Channel, std::string name)
{
	if (!Channel)
		return ("There's No Channel Named " + name + "!\n");
	t_channels channels = user->AllUserChannels();
	t_channels::iterator it = channels.begin();
	while (it != channels.end())
	{
		if (it->first == name)
		{
			std::string Info;
			Info.append("Channel Name: " + it->first + "\n");
			std::ostringstream oss;
			oss.str(""); 
			oss << it->second->countUser();
			Info.append("Online Users: " + oss.str() + "\n");
			Info.append("Channel Topic: " + it->second->topic() + "\n");
			return (Info);
		}
		it++;
	}
	return ("You Need To Join the channel first\n");
}

void	Monitorer::cmd_marvin(void)
{
	DEBUG_CALL_MONITORER_COMMAND
	std::string Greeting(_getBotMessage());

	if (request->params.size() == 0)
	{
		return (user->send_message(Greeting));
	}
	if (request->params.size() > 0)
	{
		std::string param = request->params[0];
		if (param == "0")
			return (user->send_message(getUserInfo(user)));
		else if (param == "1")
			return (user->send_message(getAllChannels(user)));
		else if (param == "2")
		{
			std::ostringstream oss;
			oss.str(""); 
			oss << this->getNumberOfUsers();
			return (user->send_message("Online Users: " + oss.str() + "\n"));	
		}
		else if (param == "3")
		{
			std::string channels;
			channels = getAllServerChannels();
			if (channels.empty())
				return (user->send_message("No Channel in the Server\n"));
			else
				return (user->send_message(getAllServerChannels() + "\n"));
		}
		else if (param == "4")
		{
			if (request->params.size() == 2)
				return (user->send_message(_channelInfo(user, find_channel(request->params[1]), request->params[1])));
			else
				return (user->send_message("Usage of this Command: MARVIN 4 [CHANNEL NAME]\n"));
		}
		else if (param == "5")
			return (user->send_message(RPL_WHOISSERVER(user)));
		else
			return (user->send_message(Greeting));
	}
};
