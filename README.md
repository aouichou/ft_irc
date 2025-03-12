<h1 align="center">ft_irc</h1>
<h3 align="center">42Paris School Project</h3>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++98-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">>
</p>

## About the Project

`ft_irc` is a custom IRC server implementation in C++98, developed as part of the 42Paris curriculum. This project deepened my understanding of network programming, TCP/IP communication, and the IRC protocol. It handles multiple clients simultaneously using non-blocking I/O and implements core IRC features.

## Features

- **Client Management**: Handle multiple clients simultaneously with non-blocking I/O (using `epoll`/`poll`).
- **Authentication**: Clients must authenticate with a password (`PASS`), set a nickname (`NICK`), and username (`USER`).
- **Channel Operations**: 
  - Join channels (`JOIN`)
  - Send public/private messages (`PRIVMSG`)
  - Channel modes: invite-only (`+i`), topic restriction (`+t`), password-protected (`+k`), user limits (`+l`)
- **Operator Commands**:
  - Kick users from channels (`KICK`)
  - Invite users to channels (`INVITE`)
  - Set channel topics (`TOPIC`)
  - Manage channel modes (`MODE`)
- **Network Protocols**: TCP/IPv4 communication with support for partial data aggregation.
- **Error Handling**: Comprehensive IRC error responses (e.g., `ERR_NICKNAMEINUSE`, `ERR_CHANOPRIVSNEEDED`).

## Technical Details

- **Language**: C++98
- **System Calls**: `socket`, `bind`, `listen`, `accept`, `poll`/`epoll`, `fcntl`, `recv`, `send`
- **Standards**: Compliant with a subset of the IRC protocol (RFC 1459)

## Getting Started

### Prerequisites

- C++98-compatible compiler (e.g., `g++`)
- GNU Make

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/<your-username>/ft_irc.git
   cd ft_irc
   ```

2. Compile the project:
   ```sh
   make
   ```

### Usage

Start the server with a port and password:
```sh
./ircserv <port> <password>
```

Connect using an IRC client (e.g., `nc` or `irssi`):
```sh
nc -C 127.0.0.1 <port>
```

## Project Structure

```
.
├── incs/              # Header files
│   ├── Monitorer.hpp  # Client/channel management
│   ├── Queue.hpp      # Event loop with epoll
│   ├── User.hpp       # Client connection logic
│   └── ...          
├── srcs/
│   ├── Monitorer.cpp  # Command parsing/handling
│   ├── Queue.cpp      # I/O multiplexing
│   ├── User.cpp       # Client operations
│   └── responses/     # IRC response templates (e.g., RPL_WELCOME)
├── main.cpp           # Server entry point
└── Makefile           # Build script
```

## Key Components

- **Event Loop**: Uses `epoll` to manage non-blocking I/O operations.
- **Command Parsing**: Extracts and processes IRC commands like `JOIN`, `PRIVMSG`.
- **Channel Modes**: Implements invite-only, password-protected, and operator privileges.
- **Error Responses**: 40+ predefined IRC error and status codes.

## Acknowledgements

Developed as part of the 42Paris curriculum. Special thanks to the 42 network for providing foundational knowledge in systems programming.

---

<p align="left">
  <a href="https://www.linkedin.com/in/your-profile" target="blank">
    <img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="Your Name" height="30" width="40" />
  </a>
</p>
