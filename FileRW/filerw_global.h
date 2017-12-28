#pragma once

#include <QtCore/qglobal.h>

#ifndef QT_STATIC
# if defined(FILERW_LIB)
#  define FILERW_EXPORT Q_DECL_EXPORT
# else
#  define FILERW_EXPORT Q_DECL_IMPORT
# endif
#else
# define FILERW_EXPORT
#endif
