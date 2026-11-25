// Matching markers (docs/matching.md). Put one on the line above each
// reconstructed function and end the function's name with its address:
//
//     MATCH_FUNC(0x461370)
//     void TDrawArea::HLine_461370(...)
//
// MATCH_FUNC = byte-exact under VC6 /O2, checked by Scripts/match.py (must stay green).
// WIP_FUNC   = implemented, not matching yet (diffed, never fails the run).
// LIBRARY_FUNC = CRT/library code VC6 can't reproduce (docs/matching.md); not checked.
// They expand to nothing: match.py reads them from the source.
#pragma once

#define MATCH_FUNC(addr)
#define WIP_FUNC(addr)
#define LIBRARY_FUNC(addr)

// The original calls these CRT routines instead of expanding them inline
// (measured: sub_461370 calls memset at 0x5FE3A0).
#include <string.h>
#ifdef _MSC_VER
#pragma function(memset)
#endif
