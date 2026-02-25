#ifndef IMPORTS_AUDIOTOOLBOX_H
#define IMPORTS_AUDIOTOOLBOX_H

/* Import stubs for AudioToolbox */

int AudioConverterDispose(); /* _AudioConverterDispose */
int AudioConverterFillBuffer(); /* _AudioConverterFillBuffer */
int AudioConverterFillComplexBuffer(); /* _AudioConverterFillComplexBuffer */
int AudioConverterNew(); /* _AudioConverterNew */
int AudioConverterReset(); /* _AudioConverterReset */
int AudioDeviceGetProperty(); /* _AudioDeviceGetProperty */
int AudioDeviceGetPropertyInfo(); /* _AudioDeviceGetPropertyInfo */
int AudioDeviceSetProperty(); /* _AudioDeviceSetProperty */
int AudioHardwareGetProperty(); /* _AudioHardwareGetProperty */
int AudioOutputUnitStart(); /* _AudioOutputUnitStart */
int AudioOutputUnitStop(); /* _AudioOutputUnitStop */
int AudioUnitAddRenderNotify(); /* _AudioUnitAddRenderNotify */
int AudioUnitGetProperty(); /* _AudioUnitGetProperty */
int AudioUnitInitialize(); /* _AudioUnitInitialize */
int AudioUnitRemoveRenderNotify(); /* _AudioUnitRemoveRenderNotify */
int AudioUnitRender(); /* _AudioUnitRender */
int AudioUnitSetParameter(); /* _AudioUnitSetParameter */
int AudioUnitSetProperty(); /* _AudioUnitSetProperty */
int AudioUnitUninitialize(); /* _AudioUnitUninitialize */

#endif /* IMPORTS_AUDIOTOOLBOX_H */
