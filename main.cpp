/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:17:15 by juchene           #+#    #+#             */
/*   Updated: 2024/02/02 05:52:18 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Arguments:
	
		port : Le port d’écoute
		password : Le mot de passe de connexion

	Fonctions externes autorisées :
		
		Tout ce qui respecte la norme C++ 98.
			socket, close, setsockopt, getsockname, getprotobyname, 
			gethostbyname, getaddrinfo, freeaddrinfo, bind, connect, listen, 
			accept, htons, htonl, ntohs, ntohl, inet_addr, inet_ntoa, send, 
			recv, signal, sigaction, lseek, fstat, fcntl, poll 
			(ou équivalent : select(), kqueue(), ou epoll().)

	Développer un serveur IRC en C++ 98.
	Vous n’avez pas à développer un client.
	Vous ne devez pas gérer la communication de serveur à serveur.
	
	Usage : ./ircserv <port> <password> 

	port : Le numéro du port sur lequel votre serveur acceptera les connexions entrantes.

	password : Le mot de passe permettant de s’identifier auprès de votre serveur
		IRC, et qui devra être fourni par tout client IRC souhaitant s’y connecter.


	lancer un prog qui ecoute sur un port
		lire
		affiche
		envois message avec nc localhost <ports> 

*/

#include <iostream>
#include <sstream>
#include "Queue.hpp"
#include "SocketBind.hpp"
#include "Monitorer.hpp"
#include "signal_handler.hpp"

typedef struct {
	int			port;
	std::string	password;
}	t_input_params;

t_input_params	parse_input(int argc, char* argv[])
{
	t_input_params		output;
	std::stringstream	ss;

	argc -= 1;
	argv += 1;
	if (argc != 2)
		throw std::runtime_error("This software require 2 argument : <port> <password>");
	std::string	port_string(argv[0]);
	if (port_string.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("This software require only number for argument <port>");
	ss << argv[0];
	ss >> output.port;
	if (output.port < 1024 || output.port > 65536)
		throw std::runtime_error("This software require a valide <port> [1024:65536]");
	output.password = argv[1];
	return (output);
}

void	server(t_input_params params)
{
	Queue			queue;
	Monitorer			monitor(params.password);
	SocketBind		sock(monitor, queue, params.port);
	SignalHandler	sig;

	std::cout << HOSTNAME << ":" << params.port << std::endl;

	while (1
		&& queue.event_loop(monitor)
		&& sig.keep_running()
	);
}

int	main(int argc, char *argv[])
{
	t_input_params	params;

	try
	{
		params = parse_input(argc, argv);
		server(params);
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << RED << "Server stop: " << e.what() << RESET << std::endl;
		return (1);
	}
}
