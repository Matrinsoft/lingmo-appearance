#pragma once

#include <QtCore/qglobal.h>

#if defined(LINGMO_APPEARANCE_LIBRARY)
#  define LINGMO_APPEARANCE_EXPORT Q_DECL_EXPORT
#else
#  define LINGMO_APPEARANCE_EXPORT Q_DECL_IMPORT
#endif
