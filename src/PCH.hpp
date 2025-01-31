#ifndef PRECOMPILED_HEADER_HPP
#define PRECOMPILED_HEADER_HPP

#ifndef _DEBUG
	#ifndef NDEBUG
		#define NDEBUG
	#endif
#endif // _DEBUG

#include <GLFW/glfw3.h>
#if defined(APIENTRY)
	#undef APIENTRY
#endif

#include <algorithm>
#include <cstdio>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>


// Macros
#define UNUSED(x) static_cast<void>(x)

#endif // PRECOMPILED_HEADER_HPP
