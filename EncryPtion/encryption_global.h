#pragma once

#include <QtCore/qglobal.h>

#ifndef QT_STATIC
# if defined(ENCRYPTION_LIB)
#  define ENCRYPTION_EXPORT Q_DECL_EXPORT
# else
#  define ENCRYPTION_EXPORT Q_DECL_IMPORT
# endif
#else
# define ENCRYPTION_EXPORT
#endif
