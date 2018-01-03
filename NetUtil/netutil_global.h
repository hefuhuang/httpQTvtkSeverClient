#pragma once

#include <QtCore/qglobal.h>

#ifndef QT_STATIC
# if defined(NETUTIL_LIB)
#  define NETUTIL_EXPORT Q_DECL_EXPORT
# else
#  define NETUTIL_EXPORT Q_DECL_IMPORT
# endif
#else
# define NETUTIL_EXPORT
#endif
