#ifndef VBF_3DMANIPULATOR_GLOBAL_H
#define VBF_3DMANIPULATOR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(VBF_3DMANIPULATOR_LIBRARY)
#  define VBF_3DMANIPULATORSHARED_EXPORT Q_DECL_EXPORT
#else
#  define VBF_3DMANIPULATORSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // VBF_3DMANIPULATOR_GLOBAL_H