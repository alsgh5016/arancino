#ifndef PINDEMONIUM_PIN_WINDOWS_H
#define PINDEMONIUM_PIN_WINDOWS_H

/*
 * PinWindows.h - Pin 3.31 Windows API integration for PINdemonium.
 *
 * Adapted from REM's include/common/Types.hpp.
 *
 * On Pin 3.x the tool links PinCRT (libc++/bionic), whose global typedefs
 * (wchar_t, _mbstate_t, __time64_t, ...) clash with the ones the real Windows.h
 * (UCRT) drags in.  Including the real Windows.h inside `namespace WINDOWS`
 * isolates those typedefs so they no longer redefine the PinCRT globals.
 *
 * Pin's own Windows.h shim (extras\crt\include\Windows.h) locates the real SDK
 * header through the _WINDOWS_H_PATH_ macro, which Pin.props defines.
 *
 * PINdemonium's legacy code uses Windows types and APIs unqualified, so we pull
 * WINDOWS into the global namespace.  Names declared directly in the global
 * namespace (e.g. Pin's CONTEXT / VOID) hide the WINDOWS ones, so Pin's types
 * still win wherever they overlap.
 */

#include "pin.H"

#ifdef UNICODE
#undef UNICODE
#endif
#ifdef _UNICODE
#undef _UNICODE
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif

namespace WINDOWS
{
#include <Windows.h>
#include <TlHelp32.h>
#include <WinNT.h>
#include <ImageHlp.h>
#include <Psapi.h>
}

using namespace WINDOWS;

#endif // PINDEMONIUM_PIN_WINDOWS_H
