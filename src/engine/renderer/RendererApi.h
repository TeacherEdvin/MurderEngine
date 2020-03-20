#ifndef RENDERER_API
  #define RENDERER_API

/* Render Shape Type Thing */
#define ME_RENDERER_TRIANGLES                 0
#define ME_RENDERER_QUADS                     1
#define ME_RENDERER_TRIANGLE_STRIP            2
#define ME_RENDERER_QUAD_STRIP                3
#define ME_RENDERER_POLYGONS                  4

/* Image Stuff */
#define ME_TEXTURE_2D                         5
#define ME_TEXTURE_3D                         6
#define ME_TEX_NEAREST                        7
#define ME_TEX_LINEAR                         8

#define ME_MATRIX_PROJECTION                  9
#define ME_MATRIX_MODELVIEW                   10

#define ME_CULL_FACE                          11
#define ME_BACK                               12
#define ME_FRONT                              13

#define ME_DEPTH_TEST                         14

/* Shader Stuff */
#define ME_SHADER_VERTEX                      234
#define ME_SHADER_FRAGMENT                    235

#include "../scene/scene.h"

class IRendererApi {

public:

  virtual int initializeApi() = 0;

  virtual int enable(int a) = 0;
  virtual int disable(int a) = 0;

  virtual int createMeshIdentifier(me::mesh* mesh) = 0;
  virtual int createImageIdentifier(me::image* image) = 0;

  /* Render Stuff */
  virtual int clear() = 0;

  virtual int renderMesh(me::mesh* mesh) = 0;
  virtual int bind(int type, unsigned int bind) = 0;

  virtual int renderBegin(int mode) = 0;
  virtual int renderEnd() = 0;

  virtual int renderColor3f(float r, float g, float b) = 0;
  virtual int renderColor4f(float r, float g, float b, float a) = 0;
  virtual int renderColor3i(int r, int g, int b) = 0;
  virtual int renderColor4i(int r, int g, int b, int a) = 0;

  virtual int renderVertex2i(int x, int y) = 0;
  virtual int renderVertex3i(int x, int y, int z) = 0;
  virtual int renderVertex2f(float x, float y) = 0;
  virtual int renderVertex3f(float x, float y, float z) = 0;
  virtual int renderVertex2d(double x, double y) = 0;
  virtual int renderVertex3d(double x, double y, double z) = 0;

  /* Transformation */
  virtual int translatef(float x, float y, float z) = 0;
  virtual int translated(double x, double y, double z) = 0;

  virtual int rotatef(float angle, float x, float y, float z) = 0;
  virtual int rotated(double angle, double x, double y, double z) = 0;
  virtual int rotatef(float x, float y, float z) = 0;
  virtual int rotated(double x, double y, double z) = 0;

  virtual int scalef(float x, float y, float z) = 0;
  virtual int scaled(double x, double y, double z) = 0;

  /* Matrix */
  virtual int matrix(int matrix) = 0;

  /* Viewport */
  virtual int viewport(int x, int y, unsigned int width, unsigned int height) = 0;
  virtual int ortho(double left, double right, double bottom, double top, double znear, double zfar) = 0;
  virtual int frustum(double left, double right, double bottom, double top, double znear, double zfar) = 0;
  virtual int perspective(double left, double right, double bottom, double top, double znear, double zfar) = 0;

  /* Other Stuff */
  virtual int loadIdentity() = 0;
  virtual int cullFace(int face) = 0;

};

#endif
