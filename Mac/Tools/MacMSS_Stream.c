/* ASM dump from: MacMSS_Stream.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacMSS_Stream.cp */

#include "common_types.h"
#include "imports.h"

extern INT32 CStreamSound_sQTStreams; /* 0x0 */

void CStreamSound_CStreamSound(const CStreamSound * _this, CSoundEngine *inEngine);
void ZN12CStreamSoundD1Ev(void); /* CStreamSound_~CStreamSound */
void ZN12CStreamSoundD0Ev(void); /* CStreamSound_~CStreamSound */
void CStreamSound_stop_sample(const CStreamSound * _this);
void CStreamSound_end_sample(const CStreamSound * _this);
void CStreamSound_get_sample_ms_position(const CStreamSound * _this, long int *total_milliseconds, long int *current_milliseconds);
void CStreamSound_set_sample_ms_position(const CStreamSound * _this, long int milliseconds);
void CStreamSound_ChangedVolume(const CStreamSound * _this);
void CStreamSound_UpdateAllStreams(void);
void CStreamSound_close_stream(const CStreamSound * _this);
void CStreamSound_resume_sample(const CStreamSound * _this);
void CStreamSound_set_sample_playback_rate(const CStreamSound * _this, long int playback_rate);
bool CStreamSound_open_stream(const CStreamSound * _this, const char *filename);
static void __static_initialization_and_destruction_0(void);
static void GLOBAL__D__ZN12CStreamSound10sQTStreamsE(void); /* global destructors keyed to CStreamSound_sQTStreams */
static void GLOBAL__I__ZN12CStreamSound10sQTStreamsE(void); /* global constructors keyed to CStreamSound_sQTStreams */
void ZNSt6vectorIP12CStreamSoundSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EE(void); /* std_vector<CStreamSound*, std_allocator<CStreamSound*> >_erase */
void ZNSt6vectorIP12CStreamSoundSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void); /* std_vector<CStreamSound*, std_allocator<CStreamSound*> >__M_insert_aux */

/* line 34 */
void CStreamSound_CStreamSound(const CStreamSound * _this, CSoundEngine *inEngine) { (void)_this; (void)inEngine; }

/* line 46 */
void ZN12CStreamSoundD1Ev(void) { }

/* line 46 */
void ZN12CStreamSoundD0Ev(void) { }

/* line 105 */
void CStreamSound_stop_sample(const CStreamSound * _this) { (void)_this; }

/* line 138 */
void CStreamSound_end_sample(const CStreamSound * _this) { (void)_this; }

/* line 152 */
void CStreamSound_get_sample_ms_position(const CStreamSound * _this, long int *total_milliseconds, long int *current_milliseconds) { (void)_this; (void)total_milliseconds; (void)current_milliseconds; }

/* line 174 */
void CStreamSound_set_sample_ms_position(const CStreamSound * _this, long int milliseconds) { (void)_this; (void)milliseconds; }

/* line 354 */
void CStreamSound_ChangedVolume(const CStreamSound * _this) { (void)_this; }

/* line 63 */
void CStreamSound_UpdateAllStreams(void) { }

/* line 328 */
void CStreamSound_close_stream(const CStreamSound * _this) { }

/* line 118 */
void CStreamSound_resume_sample(const CStreamSound * _this) { }

/* line 188 */
void CStreamSound_set_sample_playback_rate(const CStreamSound * _this, long int playback_rate) { }

/* line 203 */
bool CStreamSound_open_stream(const CStreamSound * _this, const char *filename) { (void)_this; (void)filename; return 0; }

/* line 398 */
static void __static_initialization_and_destruction_0(void) { }

/* line 400 */
static void GLOBAL__D__ZN12CStreamSound10sQTStreamsE(void) /* global destructors keyed to CStreamSound_sQTStreams */ { }

/* line 399 */
static void GLOBAL__I__ZN12CStreamSound10sQTStreamsE(void) /* global constructors keyed to CStreamSound_sQTStreams */ { }

/* line 110 */
void ZNSt6vectorIP12CStreamSoundSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EE(void) /* std_vector<CStreamSound*, std_allocator<CStreamSound*> >_erase */ { }

/* line 249 */
void ZNSt6vectorIP12CStreamSoundSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void) { }
