/* Platform stubs for audio (macOS → Linux) */
#include "audio_stubs.h"

OSStatus NewAUGraph(AUGraph *outGraph)
{
    if (outGraph) *outGraph = 0; return 0;
}

OSStatus DisposeAUGraph(AUGraph graph)
{
    return 0;
}

OSStatus AUGraphInitialize(AUGraph graph)
{
    return 0;
}

OSStatus AUGraphStart(AUGraph graph)
{
    return 0;
}

OSStatus AUGraphStop(AUGraph graph)
{
    return 0;
}

OSStatus AUGraphAddNode(AUGraph graph, const ComponentDescription *desc, AUNode *outNode)
{
    if (outNode) *outNode = 0; return 0;
}

OSStatus AUGraphConnectNodeInput(AUGraph graph, AUNode srcNode, unsigned int srcOutput, AUNode destNode, unsigned int destInput)
{
    return 0;
}

OSStatus AUGraphNodeInfo(AUGraph graph, AUNode node, ComponentDescription *outDesc, AudioUnit *outUnit)
{
    if (outUnit) *outUnit = 0; return 0;
}

OSStatus AUGraphOpen(AUGraph graph)
{
    return 0;
}

OSStatus AudioUnitSetProperty(AudioUnit unit, AudioUnitPropertyID id, AudioUnitScope scope, AudioUnitElement elem, const void *data, UInt32 size)
{
    return 0;
}

OSStatus AudioUnitGetProperty(AudioUnit unit, AudioUnitPropertyID id, AudioUnitScope scope, AudioUnitElement elem, void *data, UInt32 *size)
{
    return 0;
}

OSStatus AudioUnitSetParameter(AudioUnit unit, unsigned int paramID, unsigned int scope, unsigned int elem, float value, unsigned int offset)
{
    return 0;
}

OSStatus AudioUnitRender(AudioUnit unit, unsigned int *ioActionFlags, const void *inTimeStamp, unsigned int inOutputBusNumber, unsigned int inNumberFrames, void *ioData)
{
    return 0;
}

OSStatus AudioOutputUnitStart(AudioUnit unit)
{
    return 0;
}

OSStatus AudioOutputUnitStop(AudioUnit unit)
{
    return 0;
}

OSStatus AudioDeviceGetProperty(AudioDeviceID dev, unsigned int channel, int isInput, unsigned int propID, unsigned int *size, void *data)
{
    return 0;
}

OSStatus AudioDeviceSetProperty(AudioDeviceID dev, const void *when, unsigned int channel, int isInput, unsigned int propID, unsigned int size, const void *data)
{
    return 0;
}

OSStatus AudioHardwareGetProperty(unsigned int propID, unsigned int *size, void *data)
{
    return 0;
}
