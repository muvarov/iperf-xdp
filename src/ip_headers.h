
#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#include "iperf_config.h"

#if 0
#include <sys/socket.h>
#include <netinet/in.h>
#ifdef HAVE_NETINET_SCTP_H
#include <netinet/sctp.h>
#endif /* HAVE_NETINET_SCTP_H */
#include <sys/select.h>
#include <sys/uio.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>


#else

/* Enable POSIX features */
#if !defined(_XOPEN_SOURCE)
# define _XOPEN_SOURCE 600
#endif
#ifndef _DEFAULT_SOURCE
# define _DEFAULT_SOURCE
#endif
/* On older systems we need to define _BSD_SOURCE.
 * _DEFAULT_SOURCE is an alias for that. */
#ifndef _BSD_SOURCE
# define _BSD_SOURCE
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

/* do not redefine struct iovec */
#define _BITS_UIO_H 1
#include <fcntl.h>
#include <unistd.h>

#define TCP_MAXSEG	 2

#undef LWIP_COMPAT_SOCKETS
#define LWIP_COMPAT_SOCKETS 0

#include <lwip/arch.h>
#include <lwip/tcpip.h>
#include <lwip/netdb.h>
#include <lwip/init.h>
#include <lwip/sockets.h>
#include <lwip/def.h>
#include <lwip/errno.h>
#define sockaddr_storage sockaddr

#endif
