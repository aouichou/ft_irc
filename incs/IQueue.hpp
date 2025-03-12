/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IQueue.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:32:10 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IQUEUE_HPP
# define IQUEUE_HPP

class IQueue {
	public:
		class IEventListener
		{
			public:
				IEventListener(void);
				bool			is_alive(bool alive = true);
				virtual void	read(void)	= 0;
				virtual void	write(void)	= 0;
				static void free(IEventListener* p) { delete p; };
			protected:
				virtual	~IEventListener(void) = 0;
			private:
				bool	_alive;
		};

		virtual void	subscribe(int fd, IEventListener* event)	= 0;
		virtual void	unsubscribe(int fd)	= 0;
};

#endif

