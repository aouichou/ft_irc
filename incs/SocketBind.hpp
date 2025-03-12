/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SocketBind.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:32:01 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKETBIND_HPP
# define SOCKETBIND_HPP

# include "ICrud.hpp"
# include "SocketConnection.hpp"
# include <stdexcept>
# include <unistd.h>
# include <sys/socket.h>

# include "Colors.hpp"
# define DEBUG_CALL_SOCKET_BIND_CONSTRUCTOR \
	PRINT_DEBUG_CALL_MESSAGE(BOLD << CYAN, "", SocketBind, "\n")

# define DEBUG_CALL_SOCKET_BIND_DESTRUCTOR \
	PRINT_DEBUG_CALL_MESSAGE(BOLD << CYAN, "", SocketBind, RESET << " -> ")

class SocketBind : public IQueue::IEventListener {
	private:
		int								_fd;
		struct sockaddr_in				_sin;
		IQueue							&_queue;
		ICrud							&_crud;

	public:
		SocketBind(ICrud &crud, IQueue &queue, int port, int backlog = 5);
		~SocketBind();
		void	read(void);
		void	write(void);
};

#endif
