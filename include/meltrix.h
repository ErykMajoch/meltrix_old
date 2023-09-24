#pragma once


#ifdef _WIN32
  #define MELTRIX_EXPORT __declspec(dllexport)
#else
  #define MELTRIX_EXPORT
#endif

MELTRIX_EXPORT void meltrix();
