#ifndef STUBS_QUICKTIME_H
#define STUBS_QUICKTIME_H

/* Platform stubs for quicktime (macOS → Linux) */

typedef int OSErr;

OSErr EnterMovies(void);
void ExitMovies(void);

#endif /* STUBS_QUICKTIME_H */
