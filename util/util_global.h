#pragma once

#include <QtCore/qglobal.h>

#ifndef QT_STATIC
# if defined(UTIL_LIB)
#  define UTIL_EXPORT Q_DECL_EXPORT
# else
#  define UTIL_EXPORT Q_DECL_IMPORT
# endif
#else
# define UTIL_EXPORT
#endif
