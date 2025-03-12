/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:36:24 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_HPP
# define SIGNAL_HANDLER_HPP

# include <signal.h>

class SignalHandler
{
	public:
		SignalHandler(void);
		~SignalHandler();
		bool	keep_running(void);

	private:
		struct sigaction	_signals[2];
		static	bool		_stop;
		static	void		_stop_loop_handler(int sig_value);
};

#endif
