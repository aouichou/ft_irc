/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/02 05:48:43 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

# include <iostream>

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define BLUE		"\033[34m"
# define YELLOW		"\033[33m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"
# define BOLD		"\033[1m"

# define LOGO		"                                                                     \n"\
"          █████████    ████████    ████   ███  ███ ██████████        \n"\
"          ████   ███  ███    ████  █████  ███   ██    ████           \n"\
"          ████   ███  ███    ████  ██████ ███         ████           \n"\
"          ████   ███  ███    ████  ███  █████         ████           \n"\
"          █████████    ████████    ███   ████         ████           \n"\
"                                                                     \n"\
"          █████████    ████     ████   ████  ███    ███████          \n"\
"          ████  ████  ██████    █████  ████  ███  ████   ████        \n"\
"          ██████████ ███  ███   ███ ███████  ███  ███                \n"\
"          ██████     ████████   ███  ██████  ███  ████   ████        \n"\
"          ████      ███    ███  ███   █████  ███   █████████         \n"\


# ifdef DEBUG
# define PRINT_MESSAGE(color, before, message, after)\
	std::cout << before << color << message << after << RESET;

# define PRINT_DEBUG_MESSAGE(color, message)\
	PRINT_MESSAGE(color, "", message , "\n")

# define PRINT_DEBUG_CALL_MESSAGE(color, before, class_name, after)\
	PRINT_MESSAGE(color, before, #class_name << "::" << __FUNCTION__, after)

# define PRINT_DEBUG_CALL(color, class_name)\
	PRINT_DEBUG_CALL_MESSAGE(color, "", class_name, "\n")

# else
# define PRINT_MESSAGE(color, before, message, after)
# define PRINT_DEBUG_MESSAGE(color, message)
# define PRINT_DEBUG_CALL_MESSAGE(color, before, class_name, after)
# define PRINT_DEBUG_CALL(color, class_name)
# endif

#endif
