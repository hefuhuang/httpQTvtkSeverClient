#pragma once

#include <QtCore/qglobal.h>

#ifndef QT_STATIC
# if defined(QT3DREBUILD_LIB)
#  define QT3DREBUILD_EXPORT Q_DECL_EXPORT
# else
#  define QT3DREBUILD_EXPORT Q_DECL_IMPORT
# endif
#else
# define QT3DREBUILD_EXPORT
#endif
