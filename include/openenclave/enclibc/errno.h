// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef _ENCLIBC_ERRNO_H
#define _ENCLIBC_ERRNO_H

#include "bits/common.h"

extern int* __enclibc_errno_location(void);

#define enclibc_errno *__enclibc_errno_location()

#define ENCLIBC_EPERM 1
#define ENCLIBC_ENOENT 2
#define ENCLIBC_ESRCH 3
#define ENCLIBC_EINTR 4
#define ENCLIBC_EIO 5
#define ENCLIBC_ENXIO 6
#define ENCLIBC_E2BIG 7
#define ENCLIBC_ENOEXEC 8
#define ENCLIBC_EBADF 9
#define ENCLIBC_ECHILD 10
#define ENCLIBC_EAGAIN 11
#define ENCLIBC_ENOMEM 12
#define ENCLIBC_EACCES 13
#define ENCLIBC_EFAULT 14
#define ENCLIBC_ENOTBLK 15
#define ENCLIBC_EBUSY 16
#define ENCLIBC_EEXIST 17
#define ENCLIBC_EXDEV 18
#define ENCLIBC_ENODEV 19
#define ENCLIBC_ENOTDIR 20
#define ENCLIBC_EISDIR 21
#define ENCLIBC_EINVAL 22
#define ENCLIBC_ENFILE 23
#define ENCLIBC_EMFILE 24
#define ENCLIBC_ENOTTY 25
#define ENCLIBC_ETXTBSY 26
#define ENCLIBC_EFBIG 27
#define ENCLIBC_ENOSPC 28
#define ENCLIBC_ESPIPE 29
#define ENCLIBC_EROFS 30
#define ENCLIBC_EMLINK 31
#define ENCLIBC_EPIPE 32
#define ENCLIBC_EDOM 33
#define ENCLIBC_ERANGE 34
#define ENCLIBC_EDEADLK 35
#define ENCLIBC_ENAMETOOLONG 36
#define ENCLIBC_ENOLCK 37
#define ENCLIBC_ENOSYS 38
#define ENCLIBC_ENOTEMPTY 39
#define ENCLIBC_ELOOP 40
#define ENCLIBC_EWOULDBLOCK ENCLIBC_EAGAIN
#define ENCLIBC_ENOMSG 42
#define ENCLIBC_EIDRM 43
#define ENCLIBC_ECHRNG 44
#define ENCLIBC_EL2NSYNC 45
#define ENCLIBC_EL3HLT 46
#define ENCLIBC_EL3RST 47
#define ENCLIBC_ELNRNG 48
#define ENCLIBC_EUNATCH 49
#define ENCLIBC_ENOCSI 50
#define ENCLIBC_EL2HLT 51
#define ENCLIBC_EBADE 52
#define ENCLIBC_EBADR 53
#define ENCLIBC_EXFULL 54
#define ENCLIBC_ENOANO 55
#define ENCLIBC_EBADRQC 56
#define ENCLIBC_EBADSLT 57
#define ENCLIBC_EDEADLOCK EDEADLK
#define ENCLIBC_EBFONT 59
#define ENCLIBC_ENOSTR 60
#define ENCLIBC_ENODATA 61
#define ENCLIBC_ETIME 62
#define ENCLIBC_ENOSR 63
#define ENCLIBC_ENONET 64
#define ENCLIBC_ENOPKG 65
#define ENCLIBC_EREMOTE 66
#define ENCLIBC_ENOLINK 67
#define ENCLIBC_EADV 68
#define ENCLIBC_ESRMNT 69
#define ENCLIBC_ECOMM 70
#define ENCLIBC_EPROTO 71
#define ENCLIBC_EMULTIHOP 72
#define ENCLIBC_EDOTDOT 73
#define ENCLIBC_EBADMSG 74
#define ENCLIBC_EOVERFLOW 75
#define ENCLIBC_ENOTUNIQ 76
#define ENCLIBC_EBADFD 77
#define ENCLIBC_EREMCHG 78
#define ENCLIBC_ELIBACC 79
#define ENCLIBC_ELIBBAD 80
#define ENCLIBC_ELIBSCN 81
#define ENCLIBC_ELIBMAX 82
#define ENCLIBC_ELIBEXEC 83
#define ENCLIBC_EILSEQ 84
#define ENCLIBC_ERESTART 85
#define ENCLIBC_ESTRPIPE 86
#define ENCLIBC_EUSERS 87
#define ENCLIBC_ENOTSOCK 88
#define ENCLIBC_EDESTADDRREQ 89
#define ENCLIBC_EMSGSIZE 90
#define ENCLIBC_EPROTOTYPE 91
#define ENCLIBC_ENOPROTOOPT 92
#define ENCLIBC_EPROTONOSUPPORT 93
#define ENCLIBC_ESOCKTNOSUPPORT 94
#define ENCLIBC_EOPNOTSUPP 95
#define ENCLIBC_ENOTSUP EOPNOTSUPP
#define ENCLIBC_EPFNOSUPPORT 96
#define ENCLIBC_EAFNOSUPPORT 97
#define ENCLIBC_EADDRINUSE 98
#define ENCLIBC_EADDRNOTAVAIL 99
#define ENCLIBC_ENETDOWN 100
#define ENCLIBC_ENETUNREACH 101
#define ENCLIBC_ENETRESET 102
#define ENCLIBC_ECONNABORTED 103
#define ENCLIBC_ECONNRESET 104
#define ENCLIBC_ENOBUFS 105
#define ENCLIBC_EISCONN 106
#define ENCLIBC_ENOTCONN 107
#define ENCLIBC_ESHUTDOWN 108
#define ENCLIBC_ETOOMANYREFS 109
#define ENCLIBC_ETIMEDOUT 110
#define ENCLIBC_ECONNREFUSED 111
#define ENCLIBC_EHOSTDOWN 112
#define ENCLIBC_EHOSTUNREACH 113
#define ENCLIBC_EALREADY 114
#define ENCLIBC_EINPROGRESS 115
#define ENCLIBC_ESTALE 116
#define ENCLIBC_EUCLEAN 117
#define ENCLIBC_ENOTNAM 118
#define ENCLIBC_ENAVAIL 119
#define ENCLIBC_EISNAM 120
#define ENCLIBC_EREMOTEIO 121
#define ENCLIBC_EDQUOT 122
#define ENCLIBC_ENOMEDIUM 123
#define ENCLIBC_EMEDIUMTYPE 124
#define ENCLIBC_ECANCELED 125
#define ENCLIBC_ENOKEY 126
#define ENCLIBC_EKEYEXPIRED 127
#define ENCLIBC_EKEYREVOKED 128
#define ENCLIBC_EKEYREJECTED 129
#define ENCLIBC_EOWNERDEAD 130
#define ENCLIBC_ENOTRECOVERABLE 131
#define ENCLIBC_ERFKILL 132
#define ENCLIBC_EHWPOISON 133

#if defined(ENCLIBC_NEED_STDC_NAMES)

#define EPERM ENCLIBC_EPERM
#define ENOENT ENCLIBC_ENOENT
#define ESRCH ENCLIBC_ESRCH
#define EINTR ENCLIBC_EINTR
#define EIO ENCLIBC_EIO
#define ENXIO ENCLIBC_ENXIO
#define E2BIG ENCLIBC_E2BIG
#define ENOEXEC ENCLIBC_ENOEXEC
#define EBADF ENCLIBC_EBADF
#define ECHILD ENCLIBC_ECHILD
#define EAGAIN ENCLIBC_EAGAIN
#define ENOMEM ENCLIBC_ENOMEM
#define EACCES ENCLIBC_EACCES
#define EFAULT ENCLIBC_EFAULT
#define ENOTBLK ENCLIBC_ENOTBLK
#define EBUSY ENCLIBC_EBUSY
#define EEXIST ENCLIBC_EEXIST
#define EXDEV ENCLIBC_EXDEV
#define ENODEV ENCLIBC_ENODEV
#define ENOTDIR ENCLIBC_ENOTDIR
#define EISDIR ENCLIBC_EISDIR
#define EINVAL ENCLIBC_EINVAL
#define ENFILE ENCLIBC_ENFILE
#define EMFILE ENCLIBC_EMFILE
#define ENOTTY ENCLIBC_ENOTTY
#define ETXTBSY ENCLIBC_ETXTBSY
#define EFBIG ENCLIBC_EFBIG
#define ENOSPC ENCLIBC_ENOSPC
#define ESPIPE ENCLIBC_ESPIPE
#define EROFS ENCLIBC_EROFS
#define EMLINK ENCLIBC_EMLINK
#define EPIPE ENCLIBC_EPIPE
#define EDOM ENCLIBC_EDOM
#define ERANGE ENCLIBC_ERANGE
#define EDEADLK ENCLIBC_EDEADLK
#define ENAMETOOLONG ENCLIBC_ENAMETOOLONG
#define ENOLCK ENCLIBC_ENOLCK
#define ENOSYS ENCLIBC_ENOSYS
#define ENOTEMPTY ENCLIBC_ENOTEMPTY
#define ELOOP ENCLIBC_ELOOP
#define EWOULDBLOCK ENCLIBC_EWOULDBLOCK
#define ENOMSG ENCLIBC_ENOMSG
#define EIDRM ENCLIBC_EIDRM
#define ECHRNG ENCLIBC_ECHRNG
#define EL2NSYNC ENCLIBC_EL2NSYNC
#define EL3HLT ENCLIBC_EL3HLT
#define EL3RST ENCLIBC_EL3RST
#define ELNRNG ENCLIBC_ELNRNG
#define EUNATCH ENCLIBC_EUNATCH
#define ENOCSI ENCLIBC_ENOCSI
#define EL2HLT ENCLIBC_EL2HLT
#define EBADE ENCLIBC_EBADE
#define EBADR ENCLIBC_EBADR
#define EXFULL ENCLIBC_EXFULL
#define ENOANO ENCLIBC_ENOANO
#define EBADRQC ENCLIBC_EBADRQC
#define EBADSLT ENCLIBC_EBADSLT
#define EDEADLOCK ENCLIBC_EDEADLOCK
#define EBFONT ENCLIBC_EBFONT
#define ENOSTR ENCLIBC_ENOSTR
#define ENODATA ENCLIBC_ENODATA
#define ETIME ENCLIBC_ETIME
#define ENOSR ENCLIBC_ENOSR
#define ENONET ENCLIBC_ENONET
#define ENOPKG ENCLIBC_ENOPKG
#define EREMOTE ENCLIBC_EREMOTE
#define ENOLINK ENCLIBC_ENOLINK
#define EADV ENCLIBC_EADV
#define ESRMNT ENCLIBC_ESRMNT
#define ECOMM ENCLIBC_ECOMM
#define EPROTO ENCLIBC_EPROTO
#define EMULTIHOP ENCLIBC_EMULTIHOP
#define EDOTDOT ENCLIBC_EDOTDOT
#define EBADMSG ENCLIBC_EBADMSG
#define EOVERFLOW ENCLIBC_EOVERFLOW
#define ENOTUNIQ ENCLIBC_ENOTUNIQ
#define EBADFD ENCLIBC_EBADFD
#define EREMCHG ENCLIBC_EREMCHG
#define ELIBACC ENCLIBC_ELIBACC
#define ELIBBAD ENCLIBC_ELIBBAD
#define ELIBSCN ENCLIBC_ELIBSCN
#define ELIBMAX ENCLIBC_ELIBMAX
#define ELIBEXEC ENCLIBC_ELIBEXEC
#define EILSEQ ENCLIBC_EILSEQ
#define ERESTART ENCLIBC_ERESTART
#define ESTRPIPE ENCLIBC_ESTRPIPE
#define EUSERS ENCLIBC_EUSERS
#define ENOTSOCK ENCLIBC_ENOTSOCK
#define EDESTADDRREQ ENCLIBC_EDESTADDRREQ
#define EMSGSIZE ENCLIBC_EMSGSIZE
#define EPROTOTYPE ENCLIBC_EPROTOTYPE
#define ENOPROTOOPT ENCLIBC_ENOPROTOOPT
#define EPROTONOSUPPORT ENCLIBC_EPROTONOSUPPORT
#define ESOCKTNOSUPPORT ENCLIBC_ESOCKTNOSUPPORT
#define EOPNOTSUPP ENCLIBC_EOPNOTSUPP
#define ENOTSUP ENCLIBC_ENOTSUP
#define EPFNOSUPPORT ENCLIBC_EPFNOSUPPORT
#define EAFNOSUPPORT ENCLIBC_EAFNOSUPPORT
#define EADDRINUSE ENCLIBC_EADDRINUSE
#define EADDRNOTAVAIL ENCLIBC_EADDRNOTAVAIL
#define ENETDOWN ENCLIBC_ENETDOWN
#define ENETUNREACH ENCLIBC_ENETUNREACH
#define ENETRESET ENCLIBC_ENETRESET
#define ECONNABORTED ENCLIBC_ECONNABORTED
#define ECONNRESET ENCLIBC_ECONNRESET
#define ENOBUFS ENCLIBC_ENOBUFS
#define EISCONN ENCLIBC_EISCONN
#define ENOTCONN ENCLIBC_ENOTCONN
#define ESHUTDOWN ENCLIBC_ESHUTDOWN
#define ETOOMANYREFS ENCLIBC_ETOOMANYREFS
#define ETIMEDOUT ENCLIBC_ETIMEDOUT
#define ECONNREFUSED ENCLIBC_ECONNREFUSED
#define EHOSTDOWN ENCLIBC_EHOSTDOWN
#define EHOSTUNREACH ENCLIBC_EHOSTUNREACH
#define EALREADY ENCLIBC_EALREADY
#define EINPROGRESS ENCLIBC_EINPROGRESS
#define ESTALE ENCLIBC_ESTALE
#define EUCLEAN ENCLIBC_EUCLEAN
#define ENOTNAM ENCLIBC_ENOTNAM
#define ENAVAIL ENCLIBC_ENAVAIL
#define EISNAM ENCLIBC_EISNAM
#define EREMOTEIO ENCLIBC_EREMOTEIO
#define EDQUOT ENCLIBC_EDQUOT
#define ENOMEDIUM ENCLIBC_ENOMEDIUM
#define EMEDIUMTYPE ENCLIBC_EMEDIUMTYPE
#define ECANCELED ENCLIBC_ECANCELED
#define ENOKEY ENCLIBC_ENOKEY
#define EKEYEXPIRED ENCLIBC_EKEYEXPIRED
#define EKEYREVOKED ENCLIBC_EKEYREVOKED
#define EKEYREJECTED ENCLIBC_EKEYREJECTED
#define EOWNERDEAD ENCLIBC_EOWNERDEAD
#define ENOTRECOVERABLE ENCLIBC_ENOTRECOVERABLE
#define ERFKILL ENCLIBC_ERFKILL
#define EHWPOISON ENCLIBC_EHWPOISON

#define errno enclibc_errno

#endif /* defined(ENCLIBC_NEED_STDC_NAMES) */

#endif /* _ENCLIBC_ERRNO_H */
