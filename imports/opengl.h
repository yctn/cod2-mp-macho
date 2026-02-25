#ifndef IMPORTS_OPENGL_H
#define IMPORTS_OPENGL_H

/* Import stubs for OpenGL */

int glActiveTextureARB(); /* _glActiveTextureARB */
int glAlphaFunc(); /* _glAlphaFunc */
void glBegin(unsigned int mode);
int glBindProgramARB(); /* _glBindProgramARB */
void glBindTexture(unsigned int target, unsigned int texture);
int glBindVertexArrayAPPLE(); /* _glBindVertexArrayAPPLE */
int glBlendEquationEXT(); /* _glBlendEquationEXT */
void glBlendFunc(unsigned int sfactor, unsigned int dfactor);
int glBlendFuncSeparateEXT(); /* _glBlendFuncSeparateEXT */
void glClear(unsigned int mask);
int glClearColor(); /* _glClearColor */
int glClearDepth(); /* _glClearDepth */
int glClearStencil(); /* _glClearStencil */
int glClientActiveTextureARB(); /* _glClientActiveTextureARB */
int glClipPlane(); /* _glClipPlane */
void glColor4f(float r, float g, float b, float a);
int glColorMask(); /* _glColorMask */
int glColorMaterial(); /* _glColorMaterial */
int glColorPointer(); /* _glColorPointer */
int glCombinerParameterfvNV(); /* _glCombinerParameterfvNV */
int glCombinerStageParameterfvNV(); /* _glCombinerStageParameterfvNV */
int glCompressedTexImage2DARB(); /* _glCompressedTexImage2DARB */
int glCompressedTexImage3DARB(); /* _glCompressedTexImage3DARB */
int glCompressedTexSubImage2D(); /* _glCompressedTexSubImage2D */
int glCompressedTexSubImage3D(); /* _glCompressedTexSubImage3D */
int glCopyTexSubImage2D(); /* _glCopyTexSubImage2D */
int glDeleteFencesAPPLE(); /* _glDeleteFencesAPPLE */
int glDeleteProgramsARB(); /* _glDeleteProgramsARB */
void glDeleteTextures(int n, const unsigned int *textures);
int glDeleteVertexArraysAPPLE(); /* _glDeleteVertexArraysAPPLE */
int glDepthFunc(); /* _glDepthFunc */
void glDepthMask(unsigned char flag);
int glDepthRange(); /* _glDepthRange */
void glDisable(unsigned int cap);
int glDisableClientState(); /* _glDisableClientState */
int glDisableVertexAttribArrayARB(); /* _glDisableVertexAttribArrayARB */
int glDrawBuffer(); /* _glDrawBuffer */
int glDrawRangeElements(); /* _glDrawRangeElements */
void glEnable(unsigned int cap);
int glEnableClientState(); /* _glEnableClientState */
int glEnableVertexAttribArrayARB(); /* _glEnableVertexAttribArrayARB */
void glEnd(void);
int glFinish(); /* _glFinish */
int glFinishFenceAPPLE(); /* _glFinishFenceAPPLE */
int glFlushVertexArrayRangeAPPLE(); /* _glFlushVertexArrayRangeAPPLE */
int glFogf(); /* _glFogf */
int glFogfv(); /* _glFogfv */
int glFogi(); /* _glFogi */
int glFrontFace(); /* _glFrontFace */
int glGenFencesAPPLE(); /* _glGenFencesAPPLE */
int glGenProgramsARB(); /* _glGenProgramsARB */
void glGenTextures(int n, unsigned int *textures);
int glGenVertexArraysAPPLE(); /* _glGenVertexArraysAPPLE */
unsigned int glGetError(void);
int glGetFloatv(); /* _glGetFloatv */
void glGetIntegerv(unsigned int pname, int *params);
int glGetProgramivARB(); /* _glGetProgramivARB */
int glGetString(); /* _glGetString */
int glHint(); /* _glHint */
int glLightModelfv(); /* _glLightModelfv */
int glLightModeli(); /* _glLightModeli */
int glLightf(); /* _glLightf */
int glLightfv(); /* _glLightfv */
void glLoadIdentity(void);
int glLoadMatrixf(); /* _glLoadMatrixf */
int glMaterialf(); /* _glMaterialf */
int glMaterialfv(); /* _glMaterialfv */
void glMatrixMode(unsigned int mode);
int glNormalPointer(); /* _glNormalPointer */
int glPixelStorei(); /* _glPixelStorei */
int glPointParameterfARB(); /* _glPointParameterfARB */
int glPointParameterfvARB(); /* _glPointParameterfvARB */
int glPointSize(); /* _glPointSize */
int glPolygonMode(); /* _glPolygonMode */
int glPolygonOffset(); /* _glPolygonOffset */
int glPopAttrib(); /* _glPopAttrib */
int glPopClientAttrib(); /* _glPopClientAttrib */
void glPopMatrix(void);
int glProgramEnvParameter4fvARB(); /* _glProgramEnvParameter4fvARB */
int glProgramStringARB(); /* _glProgramStringARB */
int glPushAttrib(); /* _glPushAttrib */
int glPushClientAttrib(); /* _glPushClientAttrib */
void glPushMatrix(void);
int glReadBuffer(); /* _glReadBuffer */
int glReadPixels(); /* _glReadPixels */
void glScalef(float x, float y, float z);
void glScissor(int x, int y, int width, int height);
int glSetFenceAPPLE(); /* _glSetFenceAPPLE */
int glShadeModel(); /* _glShadeModel */
int glStencilFunc(); /* _glStencilFunc */
int glStencilMask(); /* _glStencilMask */
int glStencilOp(); /* _glStencilOp */
int glTestFenceAPPLE(); /* _glTestFenceAPPLE */
void glTexCoord2f(float s, float t);
int glTexCoordPointer(); /* _glTexCoordPointer */
int glTexEnvf(); /* _glTexEnvf */
int glTexEnvfv(); /* _glTexEnvfv */
int glTexEnvi(); /* _glTexEnvi */
int glTexGenfv(); /* _glTexGenfv */
int glTexGeni(); /* _glTexGeni */
void glTexImage2D(unsigned int target, int level, int internalformat, int width, int height, int border, unsigned int format, unsigned int type, const void *pixels);
int glTexImage3D(); /* _glTexImage3D */
int glTexParameterf(); /* _glTexParameterf */
int glTexParameterfv(); /* _glTexParameterfv */
void glTexParameteri(unsigned int target, unsigned int pname, int param);
int glTexSubImage2D(); /* _glTexSubImage2D */
int glTexSubImage3D(); /* _glTexSubImage3D */
void glVertex2f(float x, float y);
void glVertex3f(float x, float y, float z);
int glVertexArrayParameteriAPPLE(); /* _glVertexArrayParameteriAPPLE */
int glVertexArrayRangeAPPLE(); /* _glVertexArrayRangeAPPLE */
int glVertexAttribPointerARB(); /* _glVertexAttribPointerARB */
int glVertexPointer(); /* _glVertexPointer */
void glViewport(int x, int y, int width, int height);
int gluCheckExtension(); /* _gluCheckExtension */
int gluOrtho2D(); /* _gluOrtho2D */

#endif /* IMPORTS_OPENGL_H */
