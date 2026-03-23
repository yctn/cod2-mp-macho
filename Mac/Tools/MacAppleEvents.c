/* ASM dump from: MacAppleEvents.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacAppleEvents.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacExceptions.h"
 */

void ZN8CAEEventD1Ev(void); /* CAEEvent_~CAEEvent */
void ZN9CAETargetD1Ev(void); /* CAETarget_~CAETarget */
double CAETarget_CAETarget(const CAETarget * _this, const ProcessSerialNumber *inPSN);
double CAEDesc_GetData(const CAEDesc * _this, DescType inTypeCode, double *outDataPtr, Size inDataSize);
double CAEDesc_PutData(const CAEDesc * _this, DescType inTypeCode, const double *inDataPtr, Size inDataSize);
double CAEObject_CAEObject(const CAEObject * _this, DescType inDesiredClass, const AEDesc *inContainer, DescType inKeyForm, const AEDesc *inKeyData);
double CAERecord_PutParam(const CAERecord * _this, AEKeyword inKeyword, const AEDesc *inParam);
double CAEEvent_Create(const CAEEvent * _this, CAETarget *inTarget, AEEventClass inEventClass, AEEventID inEventID);
double CAEEvent_CAEEvent(const CAEEvent * _this);
double CAEEvent_Send(const CAEEvent * _this);
double CAETarget_SetPropertyData(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inPropertyID, const AEDesc *inData, const CAERecord * _this_4, AEKeyword inKeyword, SInt32 *outParam, const CAERecord * _this_7, AEKeyword inKeyword_8, StringPtr outParam_9);
double CAETarget_CountElements(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inElementClass, SInt32 *outCount);
double CAETarget_GetPropertyData(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inPropertyID, DescType inRequestedType, AEDesc *outData);

/* line 505 */
void ZN8CAEEventD1Ev(void) /* CAEEvent_~CAEEvent */
{ }

/* line 565 */
void ZN9CAETargetD1Ev(void) /* CAETarget_~CAETarget */
{ }

/* line 557 */
double CAETarget_CAETarget(const CAETarget * _this, const ProcessSerialNumber *inPSN)
{ return 0; }

/* line 210 */
double CAEDesc_GetData(const CAEDesc * _this, DescType inTypeCode, double *outDataPtr, Size inDataSize)
{ return 0; }

/* overload skip: CAEDesc_GetData (0x2ad6) */

/* line 299 */
double CAEDesc_PutData(const CAEDesc * _this, DescType inTypeCode, const double *inDataPtr, Size inDataSize)
{ return 0; }

/* line 349 */
double CAEObject_CAEObject(const CAEObject * _this, DescType inDesiredClass, const AEDesc *inContainer, DescType inKeyForm, const AEDesc *inKeyData)
{ return 0; }

/* overload skip: CAEObject_CAEObject (0x2d04) */

/* line 471 */
double CAERecord_PutParam(const CAERecord * _this, AEKeyword inKeyword, const AEDesc *inParam)
{ return 0; }

/* line 515 */
double CAEEvent_Create(const CAEEvent * _this, CAETarget *inTarget, AEEventClass inEventClass, AEEventID inEventID)
{ return 0; }

/* overload skip: CAETarget_CAETarget (0x2e86) */

/* overload skip: CAETarget_CAETarget (0x2f1a) */

/* overload skip: CAETarget_CAETarget (0x2fae) */

/* line 491 */
double CAEEvent_CAEEvent(const CAEEvent * _this)
{ return 0; }

/* line 526 */
double CAEEvent_Send(const CAEEvent * _this)
{ return 0; }

/* line 638 */
double CAETarget_SetPropertyData(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inPropertyID, const AEDesc *inData, const CAERecord * _this_4, AEKeyword inKeyword, SInt32 *outParam, const CAERecord * _this_7, AEKeyword inKeyword_8, StringPtr outParam_9)
{ return 0; }

/* line 575 */
double CAETarget_CountElements(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inElementClass, SInt32 *outCount)
{ return 0; }

/* line 608 */
double CAETarget_GetPropertyData(const CAETarget * _this, const AEDesc *inObjectSpecifier, DescType inPropertyID, DescType inRequestedType, AEDesc *outData)
{ return 0; }

