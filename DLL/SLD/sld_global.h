#ifndef SLD_GLOBAL_H
#define SLD_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SLD_LIBRARY)
#  define SLDSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SLDSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SLD_GLOBAL_H
