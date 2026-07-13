#ifndef PINDEMONIUM_STD_COMPAT_H
#define PINDEMONIUM_STD_COMPAT_H

/*
 * std_compat.h - global std visibility for PINdemonium's legacy code.
 *
 * PINdemonium was written for VS2010's non-conformant STL and uses std types
 * (string, vector, map, ...) unqualified, without any `using namespace std`.
 * Under Pin 3.31's PinCRT libc++ those names are not visible in the global
 * namespace, so expose exactly the ones the code relies on (same spirit as
 * REM's `using std::string`).  Force-included into every pintool TU via Pin.props
 * (/FI), so it takes effect before any header that uses these types.
 */

#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <sstream>
#include <ostream>
#include <utility>

// PINdemonium used MSVC's <direct.h> _mkdir(), but <direct.h> is not part of
// PinCRT and would drag in MSVC's UCRT corecrt.h at global scope (clashing
// wchar_t/mbstate_t/time_t typedefs).  Map _mkdir onto PinCRT's POSIX mkdir
// instead (the mode is ignored on Windows; directory creation is unchanged).
#include <sys/stat.h>
#ifndef _mkdir
#define _mkdir(path) mkdir((path), 0777)
#endif

using std::string;
using std::wstring;
using std::vector;
using std::map;
using std::list;
using std::set;
using std::pair;
using std::ostream;
using std::stringstream;

#endif // PINDEMONIUM_STD_COMPAT_H
