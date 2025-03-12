/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responses.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/02 05:50:07 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSES_HPP
# define RESPONSES_HPP

# include <sstream>

# include "User.hpp"
# include "Channel.hpp"

# define HOSTNAME "localhost"
# define SERVERNAME "Total Perspective Vortex"
# define VERSION "4.2"
# define CREATION_DATE "2023/12/10"

class User;
class Channel;

// MODE
std::string	RPL_TRYAGAIN(std::string command, std::string info = "command not found");

std::string	RPL_WELCOME(User * user, std::string channel = "", std::string msg = "Welcome to the Internet Relay Network ");
std::string	RPL_YOURHOST();
std::string	RPL_CREATED();
std::string	RPL_MYINFO();

std::string	ERR_NEEDMOREPARAMS(std::string channel, std::string cmd, std::string reason = "command requires more parameters");
std::string	ERR_NOSUCHCHANNEL(std::string nickname, std::string channel, std::string reason = "no such channel");
std::string	ERR_UMODEUNKNOWNFLAG(std::string nickname, std::string reason = "U MODE UNKNOWN FLAG");
std::string	ERR_CHANOPRIVSNEEDED(std::string nickname, std::string channel, std::string reason = "Channel operator privilege needed");
std::string	ERR_NOTONCHANNEL(std::string nickname, std::string channel, std::string reason = "You are not a member");
std::string	ERR_KEYSET(std::string nickname, std::string channel, std::string reason = "the channel key has already been set ");
std::string	ERR_NOSUCHNICK(std::string userNickName, std::string channel ="", std::string nickname="", std::string reason = "the nickname parameter supplied is unused");
std::string	ERR_UNKNOWNMODE(std::string user, std::string channel, char c, std::string reason = "the given mode in unknown");

std::string	RPL_CHANNELMODEIS(std::string nickname, Channel* channel);

// NICK
std::string	ERR_NONICKNAMEGIVEN(std::string reason = "a nickname parameter is expected");
std::string	ERR_NICKNAMEINUSE(std::string nick, std::string reason = "the given nickname is already in use");
std::string	ERR_ERRONEUSNICKNAME(std::string nick, std::string reason = "the given nickname is considered invalid");

//PASS 
std::string	ERR_ALREADYREGISTRED(std::string nick, std::string reason = "You are already registered");
std::string	ERR_PASSWDMISMATCH(std::string nick, std::string reason = "A Password is requiered");

// INVITE
std::string	ERR_USERONCHANNEL(std::string nick, std::string channel, std::string reason = "user is already on the channel");
std::string	RPL_INVITING(std::string userNick, std::string invitedNick, std::string channel);

// TOPIC
std::string	RPL_NOTOPIC(std::string nickname, std::string channel, std::string info = "no topic is set");
std::string	RPL_TOPIC(std::string nickname, std::string channel, std::string topic);

// PING
std::string	PONG(std::string server);

// WHOIS
std::string	RPL_WHOISUSER(User * _user);

// PRIVMSG
std::string	PRIVMSG(std::string sender, std::string channel, std::string message);
std::string	ERR_NORECIPIENT(std::string reason = "no recipient is given with the command");
std::string	ERR_NOTEXTTOSEND(std::string reason = "no message given");
std::string	ERR_CANNOTSENDTOCHAN(std::string channel, std::string reason = "no rights to send text to the channel");
std::string	ERR_TOOMANYTARGETS(std::string target, std::string reason = "the given target is ambigous");

// JOIN
std::string	ERR_INVITEONLYCHAN(std::string nickname, std::string channel, std::string reason = "invite only channel");
std::string	ERR_BADCHANNELKEY(std::string user, std::string channel, std::string reason = "bad channel key");
std::string	ERR_CHANNELISFULL(std::string user, std::string channel, std::string reason = "channel is full");
std::string	ERR_BANNEDFROMCHAN(std::string channel, std::string reason = "banned ... #sorry");

std::string	RPL_NAMREPLY(std::string nickname, Channel *channel);
std::string	RPL_ENDOFNAMES(std::string nickname, Channel *channel);
std::string	NICK(std::string old, std::string newnick);

//PING PONG
std::string	ERR_NOORIGIN();

std::string	ERR_NOTREGISTERED(void);

// KICK
std::string	KICK(std::string user, std::string channel, std::string kickedUser, std::string reason);
std::string	JOIN(User* user, std::string channel);

// WHOIS
std::string	ERR_NOSUCHSERVER(std::string server, std::string reason = "No such server");
std::string	RPL_ENDOFWHOIS(User * _user);
std::string	RPL_WHOISCHANNELS(std::string prefix, Channel *channel);
std::string	RPL_WHOISIDLE(User * _user, std::string reason = "seconds idle, signon time");
std::string	RPL_WHOISOPERATOR(User * _user, std::string reason = "is an IRC operator");
std::string	RPL_WHOISSERVER(User * _user);

// WHO
std::string	RPL_WHOREPLY(std::string channel, std::string users_list);
std::string RPL_ENDOFWHO(std::string name);

#endif
