/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2006 Robert Osfield 
 * Copyright (C) 2003-2005 3Dlabs Inc. Ltd.
 * Copyright (C) 2004-2005 Nathan Cournia
 * Copyright (C) 2007 Art Tevs
 * Copyright (C) 2008 Zebra Imaging
 * Copyright (C) 2010 VIRES Simulationstechnologie GmbH
 *
 * This application is open source and may be redistributed and/or modified   
 * freely and without restriction, both in commercial and non commercial
 * applications, as long as this copyright notice is maintained.
 * 
 * This application is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

/* file:        include/osg/GL2Extensions
 * author:      Mike Weiblen 2008-01-02
 *              Holger Helmich 2010-10-21
*/

#ifndef OSG_GL2EXTENSIONS
#define OSG_GL2EXTENSIONS 1

#include <VBF_Base/VBF_Referenced.h>
#include <VBF_Engine/VBF_SceneGraph/VBF_GL.h>

#include <string>

#ifndef GL_SAMPLER_2D_ARRAY_EXT
    #define GL_SAMPLER_1D_ARRAY_EXT           0x8DC0
    #define GL_SAMPLER_2D_ARRAY_EXT           0x8DC1
    #define GL_SAMPLER_1D_ARRAY_SHADOW_EXT    0x8DC3
    #define GL_SAMPLER_2D_ARRAY_SHADOW_EXT    0x8DC4
#endif

#if !defined(GL_VERSION_2_0)
typedef char GLchar;
#endif

#if !defined(GL_VERSION_2_0)
    #define GL_VERTEX_PROGRAM_POINT_SIZE      0x8642
    #define GL_VERTEX_PROGRAM_TWO_SIDE        0x8643
#endif

#if !defined(GL_VERSION_2_0) && !defined(GL_ES_VERSION_2_0)
#define GL_VERSION_2_0 1
#define GL_BLEND_EQUATION_RGB             GL_BLEND_EQUATION
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE       0x8625
#define GL_CURRENT_VERTEX_ATTRIB          0x8626
#define GL_VERTEX_ATTRIB_ARRAY_POINTER    0x8645
#define GL_STENCIL_BACK_FUNC              0x8800
#define GL_STENCIL_BACK_FAIL              0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS   0x8803
#define GL_MAX_DRAW_BUFFERS               0x8824
#define GL_DRAW_BUFFER0                   0x8825
#define GL_DRAW_BUFFER1                   0x8826
#define GL_DRAW_BUFFER2                   0x8827
#define GL_DRAW_BUFFER3                   0x8828
#define GL_DRAW_BUFFER4                   0x8829
#define GL_DRAW_BUFFER5                   0x882A
#define GL_DRAW_BUFFER6                   0x882B
#define GL_DRAW_BUFFER7                   0x882C
#define GL_DRAW_BUFFER8                   0x882D
#define GL_DRAW_BUFFER9                   0x882E
#define GL_DRAW_BUFFER10                  0x882F
#define GL_DRAW_BUFFER11                  0x8830
#define GL_DRAW_BUFFER12                  0x8831
#define GL_DRAW_BUFFER13                  0x8832
#define GL_DRAW_BUFFER14                  0x8833
#define GL_DRAW_BUFFER15                  0x8834
#define GL_BLEND_EQUATION_ALPHA           0x883D
#define GL_POINT_SPRITE                   0x8861
#define GL_COORD_REPLACE                  0x8862
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_COORDS             0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS        0x8872
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS  0x8B4A
#define GL_MAX_VARYING_FLOATS             0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE                    0x8B4F
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
#define GL_SAMPLER_CUBE                   0x8B60
#define GL_SAMPLER_1D_SHADOW              0x8B61
#define GL_SAMPLER_2D_SHADOW              0x8B62
#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_ATTACHED_SHADERS               0x8B85
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADER_SOURCE_LENGTH           0x8B88
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN      0x8CA0
#define GL_LOWER_LEFT                     0x8CA1
#define GL_UPPER_LEFT                     0x8CA2
#define GL_STENCIL_BACK_REF               0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK        0x8CA4
#define GL_STENCIL_BACK_WRITEMASK         0x8CA5
#endif

#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#define GL_PIXEL_PACK_BUFFER              0x88EB
#define GL_PIXEL_UNPACK_BUFFER            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING    0x88EF
#define GL_FLOAT_MAT2x3                   0x8B65
#define GL_FLOAT_MAT2x4                   0x8B66
#define GL_FLOAT_MAT3x2                   0x8B67
#define GL_FLOAT_MAT3x4                   0x8B68
#define GL_FLOAT_MAT4x2                   0x8B69
#define GL_FLOAT_MAT4x3                   0x8B6A
#define GL_SRGB                           0x8C40
#define GL_SRGB8                          0x8C41
#define GL_SRGB_ALPHA                     0x8C42
#define GL_SRGB8_ALPHA8                   0x8C43
#define GL_SLUMINANCE_ALPHA               0x8C44
#define GL_SLUMINANCE8_ALPHA8             0x8C45
#define GL_SLUMINANCE                     0x8C46
#define GL_SLUMINANCE8                    0x8C47
#define GL_COMPRESSED_SRGB                0x8C48
#define GL_COMPRESSED_SRGB_ALPHA          0x8C49
#define GL_COMPRESSED_SLUMINANCE          0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA    0x8C4B
#endif

// EXT_geometry_shader4
#ifndef GL_GEOMETRY_SHADER_EXT
#define GL_GEOMETRY_SHADER_EXT                       0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_EXT                 0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_EXT                   0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT                  0x8DDC
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT      0x8C29
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT       0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT         0x8DDE
#define GL_MAX_VARYING_COMPONENTS_EXT                0x8B4B
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT       0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT          0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT  0x8DE1
#define GL_LINES_ADJACENCY_EXT                       0x000A
#define GL_LINE_STRIP_ADJACENCY_EXT                  0x000B
#define GL_TRIANGLES_ADJACENCY_EXT                   0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT              0x000D
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT  0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT    0x8DA9
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT        0x8DA7
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT  0x8CD4
#define GL_PROGRAM_POINT_SIZE_EXT                    0x8642
#endif

// ARB_tesselation_shader
#ifndef GL_TESS_EVALUATION_SHADER
#define GL_PATCHES                                             0x000E
#define GL_PATCH_VERTICES                                      0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL                           0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL                           0x8E74
#define GL_MAX_PATCH_VERTICES                                  0x8E7D
#define GL_MAX_TESS_GEN_LEVEL                                  0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS                 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS              0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS                0x8E81
#define GL_MAX_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS         0x8E82
#define GL_MAX_MAX_TESS_CONTROL_OUTPUT_COMPONENTS              0x8E83
#define GL_MAX_MAX_TESS_PATCH_COMPONENTS                       0x8E84
#define GL_MAX_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS        0x8E85
#define GL_MAX_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS           0x8E86
#define GL_MAX_MAX_TESS_CONTROL_UNIFORM_BLOCKS                 0x8E89
#define GL_MAX_MAX_TESS_EVALUATION_UNIFORM_BLOCKS              0x8E8A
#define GL_MAX_MAX_TESS_CONTROL_INPUT_COMPONENTS               0x886C
#define GL_MAX_MAX_TESS_EVALUATION_INPUT_COMPONENTS            0x886D
#define GL_MAX_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS    0x8E1E
#define GL_MAX_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_TESS_EVALUATION_SHADER                              0x8E87
#define GL_TESS_CONTROL_SHADER                                 0x8E88
#define GL_TESS_CONTROL_OUTPUT_VERTICES                        0x8E75
#define GL_TESS_GEN_MODE                                       0x8E76
#define GL_TESS_GEN_SPACING                                    0x8E77
#define GL_TESS_GEN_VERTEX_ORDER                               0x8E78
#define GL_TESS_GEN_POINT_MODE                                 0x8E79
#define GL_ISOLINES                                            0x8E7A
#define GL_FRACTIONAL_ODD                                      0x8E7B
#define GL_FRACTIONAL_EVEN                                     0x8E7C
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER     0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER  0x84F1
#endif

// EXT_gpu_shader4
#ifndef GL_INT_SAMPLER_2D_EXT
#define GL_SAMPLER_1D_ARRAY_EXT               0x8DC0
#define GL_SAMPLER_2D_ARRAY_EXT               0x8DC1
#define GL_SAMPLER_BUFFER_EXT                 0x8DC2
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT        0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT        0x8DC4
#define GL_SAMPLER_CUBE_SHADOW_EXT            0x8DC5
#define GL_UNSIGNED_INT_VEC2_EXT              0x8DC6
#define GL_UNSIGNED_INT_VEC3_EXT              0x8DC7
#define GL_UNSIGNED_INT_VEC4_EXT              0x8DC8
#define GL_INT_SAMPLER_1D_EXT                 0x8DC9
#define GL_INT_SAMPLER_2D_EXT                 0x8DCA
#define GL_INT_SAMPLER_3D_EXT                 0x8DCB
#define GL_INT_SAMPLER_CUBE_EXT               0x8DCC
#define GL_INT_SAMPLER_2D_RECT_EXT            0x8DCD
#define GL_INT_SAMPLER_1D_ARRAY_EXT           0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY_EXT           0x8DCF
#define GL_INT_SAMPLER_BUFFER_EXT             0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT        0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT        0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT        0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT      0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT   0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT  0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT  0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT    0x8DD8
#define GL_MIN_PROGRAM_TEXEL_OFFSET_EXT       0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET_EXT       0x8905
#endif

// ARB_uniform_buffer_object
#ifndef GL_UNIFORM_BUFFER
#define GL_UNIFORM_BUFFER                 0x8A11
#define GL_UNIFORM_BUFFER_BINDING         0x8A28
#define GL_UNIFORM_BUFFER_START           0x8A29
#define GL_UNIFORM_BUFFER_SIZE            0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS      0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS    0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS    0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS    0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS    0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE         0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS          0x8A36
#define GL_UNIFORM_TYPE                   0x8A37
#define GL_UNIFORM_SIZE                   0x8A38
#define GL_UNIFORM_NAME_LENGTH            0x8A39
#define GL_UNIFORM_BLOCK_INDEX            0x8A3A
#define GL_UNIFORM_OFFSET                 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE           0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE          0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR           0x8A3E
#define GL_UNIFORM_BLOCK_BINDING          0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE        0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH      0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS  0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX                  0xFFFFFFFFu
#endif

//ARB_get_program_binary
#ifndef GL_PROGRAM_BINARY_RETRIEVABLE_HINT
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH           0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS      0x87FE
#define GL_PROGRAM_BINARY_FORMATS          0x87FF
#endif

namespace osg {

class OSG_EXPORT GL2Extensions : public ::CVBF_Referenced
{
    public:
        GL2Extensions(unsigned int contextID);
        GL2Extensions(const GL2Extensions& rhs);

        void lowestCommonDenominator(const GL2Extensions& rhs);

        void setupGL2Extensions(unsigned int contextID);

        /** Does the GL driver support OpenGL Shading Language? */
        bool isGlslSupported() const;

        float getGlVersion() const { return _glVersion; }
        float getLanguageVersion() const { return _glslLanguageVersion; }

        void setShaderObjectsSupported(bool flag) { _isShaderObjectsSupported = flag; }
        bool isShaderObjectsSupported() const { return _isShaderObjectsSupported; }

        void setVertexShaderSupported(bool flag) { _isVertexShaderSupported = flag; }
        bool isVertexShaderSupported() const { return _isVertexShaderSupported; }

        void setFragmentShaderSupported(bool flag) { _isFragmentShaderSupported = flag; }
        bool isFragmentShaderSupported() const { return _isFragmentShaderSupported; }

        void setLanguage100Supported(bool flag) { _isLanguage100Supported = flag; }
        bool isLanguage100Supported() const { return _isLanguage100Supported; }

        void setGeometryShader4Supported(bool flag) { _isGeometryShader4Supported = flag; }
        bool isGeometryShader4Supported() const { return _isGeometryShader4Supported; }

        void setTessellationShadersSupported(bool flag) { _areTessellationShadersSupported = flag; }
        bool areTessellationShadersSupported() const { return _areTessellationShadersSupported; }

        void setGpuShader4Supported(bool flag) { _isGpuShader4Supported = flag; }
        bool isGpuShader4Supported() const { return _isGpuShader4Supported; }

        void setUniformBufferObjectSupported(bool flag) { _isUniformBufferObjectSupported = flag; }
        bool isUniformBufferObjectSupported() {return _isUniformBufferObjectSupported; }

        void setGetProgramBinarySupported(bool flag) { _isGetProgramBinarySupported = flag; }
        bool isGetProgramBinarySupported() {return _isGetProgramBinarySupported; }

        /** Function to call to get the extension of a specified context.
          * If the Exentsion object for that context has not yet been created then
          * and the 'createIfNotInitalized' flag been set to false then returns NULL.
          * If 'createIfNotInitalized' is true then the Extensions object is
          * automatically created.  However, in this case the extension object
          * only be created with the graphics context associated with ContextID..*/
        static GL2Extensions* Get(unsigned int contextID,bool createIfNotInitalized);

        /** allows users to override the extensions across graphics contexts.
          * typically used when you have different extensions supported across graphics pipes
          * but need to ensure that they all use the same low common denominator extensions.*/
        static void Set(unsigned int contextID, GL2Extensions* extensions);


        void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) const;
        void glDrawBuffers(GLsizei n, const GLenum *bufs) const;
        void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) const;
        void glStencilFuncSeparate(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask) const;
        void glStencilMaskSeparate(GLenum face, GLuint mask) const;
        void glAttachShader(GLuint program, GLuint shader) const;
        void glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) const;
        void glCompileShader(GLuint shader) const;
        GLuint glCreateProgram(void) const;
        GLuint glCreateShader(GLenum type) const;
        void glDeleteProgram(GLuint program) const;
        void glDeleteShader(GLuint shader) const;
        void glDetachShader(GLuint program, GLuint shader) const;
        void glDisableVertexAttribArray(GLuint index) const;
        void glEnableVertexAttribArray(GLuint index) const;
        void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) const;
        void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) const;
        void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *obj) const;
        GLint glGetAttribLocation(GLuint program, const GLchar *name) const;
        void glGetProgramiv(GLuint program, GLenum pname, GLint *params) const;
        void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) const;
        void glGetShaderiv(GLuint shader, GLenum pname, GLint *params) const;
        void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) const;
        void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) const;
        GLint glGetUniformLocation(GLuint program, const GLchar *name) const;
        void glGetUniformfv(GLuint program, GLint location, GLfloat *params) const;
        void glGetUniformiv(GLuint program, GLint location, GLint *params) const;
        void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params) const;
        void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) const;
        void glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) const;
        void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid* *pointer) const;
        GLboolean glIsProgram(GLuint program) const;
        GLboolean glIsShader(GLuint shader) const;
        void glLinkProgram(GLuint program) const;
        void glShaderSource(GLuint shader, GLsizei count, const GLchar* *string, const GLint *length) const;
        void glUseProgram(GLuint program) const;
        void glUniform1f(GLint location, GLfloat v0) const;
        void glUniform2f(GLint location, GLfloat v0, GLfloat v1) const;
        void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) const;
        void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) const;
        void glUniform1i(GLint location, GLint v0) const;
        void glUniform2i(GLint location, GLint v0, GLint v1) const;
        void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) const;
        void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) const;
        void glUniform1fv(GLint location, GLsizei count, const GLfloat *value) const;
        void glUniform2fv(GLint location, GLsizei count, const GLfloat *value) const;
        void glUniform3fv(GLint location, GLsizei count, const GLfloat *value) const;
        void glUniform4fv(GLint location, GLsizei count, const GLfloat *value) const;
        void glUniform1iv(GLint location, GLsizei count, const GLint *value) const;
        void glUniform2iv(GLint location, GLsizei count, const GLint *value) const;
        void glUniform3iv(GLint location, GLsizei count, const GLint *value) const;
        void glUniform4iv(GLint location, GLsizei count, const GLint *value) const;
        void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) const;
        void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) const;
        void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) const;
        void glValidateProgram(GLuint program) const;
        void glVertexAttrib1d(GLuint index, GLdouble x) const;
        void glVertexAttrib1dv(GLuint index, const GLdouble *v) const;
        void glVertexAttrib1f(GLuint index, GLfloat x) const;
        void glVertexAttrib1fv(GLuint index, const GLfloat *v) const;
        void glVertexAttrib1s(GLuint index, GLshort x) const;
        void glVertexAttrib1sv(GLuint index, const GLshort *v) const;
        void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) const;
        void glVertexAttrib2dv(GLuint index, const GLdouble *v) const;
        void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) const;
        void glVertexAttrib2fv(GLuint index, const GLfloat *v) const;
        void glVertexAttrib2s(GLuint index, GLshort x, GLshort y) const;
        void glVertexAttrib2sv(GLuint index, const GLshort *v) const;
        void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) const;
        void glVertexAttrib3dv(GLuint index, const GLdouble *v) const;
        void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) const;
        void glVertexAttrib3fv(GLuint index, const GLfloat *v) const;
        void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) const;
        void glVertexAttrib3sv(GLuint index, const GLshort *v) const;
        void glVertexAttrib4Nbv(GLuint index, const GLbyte *v) const;
        void glVertexAttrib4Niv(GLuint index, const GLint *v) const;
        void glVertexAttrib4Nsv(GLuint index, const GLshort *v) const;
        void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) const;
        void glVertexAttrib4Nubv(GLuint index, const GLubyte *v) const;
        void glVertexAttrib4Nuiv(GLuint index, const GLuint *v) const;
        void glVertexAttrib4Nusv(GLuint index, const GLushort *v) const;
        void glVertexAttrib4bv(GLuint index, const GLbyte *v) const;
        void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) const;
        void glVertexAttrib4dv(GLuint index, const GLdouble *v) const;
        void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) const;
        void glVertexAttrib4fv(GLuint index, const GLfloat *v) const;
        void glVertexAttrib4iv(GLuint index, const GLint *v) const;
        void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) const;
        void glVertexAttrib4sv(GLuint index, const GLshort *v) const;
        void glVertexAttrib4ubv(GLuint index, const GLubyte *v) const;
        void glVertexAttrib4uiv(GLuint index, const GLuint *v) const;
        void glVertexAttrib4usv(GLuint index, const GLushort *v) const;
        void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer) const;

        // C++-friendly convenience wrapper methods
        GLuint getCurrentProgram() const;
        bool getProgramInfoLog( GLuint program, std::string& result ) const;
        bool getShaderInfoLog( GLuint shader, std::string& result ) const;
        bool getAttribLocation( const char* attribName, GLuint& slot ) const;
        bool getFragDataLocation( const char* fragDataName, GLuint& slot) const;

        // GL 2.1
        void glUniformMatrix2x3fv( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) const;
        void glUniformMatrix3x2fv( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) const;
        void glUniformMatrix2x4fv( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) const;
        void glUniformMatrix4x2fv( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) const;
        void glUniformMatrix3x4fv( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) const;
        void glUniformMatrix4x3fv( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) const;

        // EXT_geometry_shader4
        void glProgramParameteri( GLuint program, GLenum pname, GLint value ) const;
        void glFramebufferTexture( GLenum target, GLenum attachment, GLuint texture, GLint level ) const;
        void glFramebufferTextureLayer( GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer ) const;
        void glFramebufferTextureFace( GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face ) const;

        // ARB_tessellation_shader
        void glPatchParameteri(GLenum pname, GLint value) const;
        void glPatchParameterfv(GLenum pname, const GLfloat *values) const;

        // EXT_gpu_shader4
        void glGetUniformuiv( GLuint program, GLint location, GLuint *params ) const;
        void glBindFragDataLocation( GLuint program, GLuint color, const GLchar *name ) const;
        GLint glGetFragDataLocation( GLuint program, const GLchar *name ) const;
        void glUniform1ui( GLint location, GLuint v0 ) const;
        void glUniform2ui( GLint location, GLuint v0, GLuint v1 ) const;
        void glUniform3ui( GLint location, GLuint v0, GLuint v1, GLuint v2 ) const;
        void glUniform4ui( GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3 ) const;
        void glUniform1uiv( GLint location, GLsizei count, const GLuint *value ) const;
        void glUniform2uiv( GLint location, GLsizei count, const GLuint *value ) const;
        void glUniform3uiv( GLint location, GLsizei count, const GLuint *value ) const;
        void glUniform4uiv( GLint location, GLsizei count, const GLuint *value ) const;

        // ARB_uniform_buffer_object
        void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* *uniformNames, GLuint *uniformIndices) const;
        void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) const;
        void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName) const;
        GLuint glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName) const;
        void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) const;
        void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) const;
        void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) const;

        // ARB_get_program_binary
        void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary) const;
        void glProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length) const;

    protected:
        ~GL2Extensions() {}// IE���ܴ���

        float _glVersion;
        float _glslLanguageVersion;

        bool _isShaderObjectsSupported;
        bool _isVertexShaderSupported;
        bool _isFragmentShaderSupported;
        bool _isLanguage100Supported;
        bool _isGeometryShader4Supported;
        bool _areTessellationShadersSupported;
        bool _isGpuShader4Supported;
        bool _isUniformBufferObjectSupported;
        bool _isGetProgramBinarySupported;

        typedef void (GL_APIENTRY * BlendEquationSeparateProc)(GLenum modeRGB, GLenum modeAlpha);
        typedef void (GL_APIENTRY * DrawBuffersProc)(GLsizei n, const GLenum *bufs);
        typedef void (GL_APIENTRY * StencilOpSeparateProc)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
        typedef void (GL_APIENTRY * StencilFuncSeparateProc)(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
        typedef void (GL_APIENTRY * StencilMaskSeparateProc)(GLenum face, GLuint mask);
        typedef void (GL_APIENTRY * AttachShaderProc)(GLuint program, GLuint shader);
        typedef void (GL_APIENTRY * BindAttribLocationProc)(GLuint program, GLuint index, const GLchar *name);
        typedef void (GL_APIENTRY * CompileShaderProc)(GLuint shader);
        typedef GLuint (GL_APIENTRY * CreateProgramProc)(void);
        typedef GLuint (GL_APIENTRY * CreateShaderProc)(GLenum type);
        typedef void (GL_APIENTRY * DeleteProgramProc)(GLuint program);
        typedef void (GL_APIENTRY * DeleteObjectARBProc)(GLuint program);
        typedef void (GL_APIENTRY * DeleteShaderProc)(GLuint shader);
        typedef void (GL_APIENTRY * DetachShaderProc)(GLuint program, GLuint shader);
        typedef void (GL_APIENTRY * DisableVertexAttribArrayProc)(GLuint index);
        typedef void (GL_APIENTRY * EnableVertexAttribArrayProc)(GLuint index);
        typedef void (GL_APIENTRY * GetActiveAttribProc)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
        typedef void (GL_APIENTRY * GetActiveUniformProc)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
        typedef void (GL_APIENTRY * GetAttachedShadersProc)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *obj);
        typedef GLint (GL_APIENTRY * GetAttribLocationProc)(GLuint program, const GLchar *name);
        typedef void (GL_APIENTRY * GetProgramivProc)(GLuint program, GLenum pname, GLint *params);
        typedef void (GL_APIENTRY * GetObjectParameterivARBProc)(GLuint program, GLenum pname, GLint *params);
        typedef void (GL_APIENTRY * GetProgramInfoLogProc)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
        typedef void (GL_APIENTRY * GetInfoLogARBProc)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);    
        typedef void (GL_APIENTRY * GetShaderivProc)(GLuint shader, GLenum pname, GLint *params);                             
        typedef void (GL_APIENTRY * GetShaderInfoLogProc)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);  
        typedef void (GL_APIENTRY * GetShaderSourceProc)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);    
        typedef GLint (GL_APIENTRY * GetUniformLocationProc)(GLuint program, const GLchar *name);                             
        typedef void (GL_APIENTRY * GetUniformfvProc)(GLuint program, GLint location, GLfloat *params);                       
        typedef void (GL_APIENTRY * GetUniformivProc)(GLuint program, GLint location, GLint *params);                         
        typedef void (GL_APIENTRY * GetVertexAttribdvProc)(GLuint index, GLenum pname, GLdouble *params);                     
        typedef void (GL_APIENTRY * GetVertexAttribfvProc)(GLuint index, GLenum pname, GLfloat *params);                      
        typedef void (GL_APIENTRY * GetVertexAttribivProc)(GLuint index, GLenum pname, GLint *params);                        
        typedef void (GL_APIENTRY * GetVertexAttribPointervProc)(GLuint index, GLenum pname, GLvoid* *pointer);               
        typedef GLboolean (GL_APIENTRY * IsProgramProc)(GLuint program);                                                      
        typedef GLboolean (GL_APIENTRY * IsShaderProc)(GLuint shader);                                                        
        typedef void (GL_APIENTRY * LinkProgramProc)(GLuint program);                                                         
        typedef void (GL_APIENTRY * ShaderSourceProc)(GLuint shader, GLsizei count, const GLchar* *string, const GLint *length);
        typedef void (GL_APIENTRY * UseProgramProc)(GLuint program);                                                            
        typedef void (GL_APIENTRY * Uniform1fProc)(GLint location, GLfloat v0);                                                 
        typedef void (GL_APIENTRY * Uniform2fProc)(GLint location, GLfloat v0, GLfloat v1);                                     
        typedef void (GL_APIENTRY * Uniform3fProc)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);                         
        typedef void (GL_APIENTRY * Uniform4fProc)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);             
        typedef void (GL_APIENTRY * Uniform1iProc)(GLint location, GLint v0);                                                   
        typedef void (GL_APIENTRY * Uniform2iProc)(GLint location, GLint v0, GLint v1);                                         
        typedef void (GL_APIENTRY * Uniform3iProc)(GLint location, GLint v0, GLint v1, GLint v2);                               
        typedef void (GL_APIENTRY * Uniform4iProc)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);                   
        typedef void (GL_APIENTRY * Uniform1fvProc)(GLint location, GLsizei count, const GLfloat *value);                       
        typedef void (GL_APIENTRY * Uniform2fvProc)(GLint location, GLsizei count, const GLfloat *value);                       
        typedef void (GL_APIENTRY * Uniform3fvProc)(GLint location, GLsizei count, const GLfloat *value);                       
        typedef void (GL_APIENTRY * Uniform4fvProc)(GLint location, GLsizei count, const GLfloat *value);                       
        typedef void (GL_APIENTRY * Uniform1ivProc)(GLint location, GLsizei count, const GLint *value);                         
        typedef void (GL_APIENTRY * Uniform2ivProc)(GLint location, GLsizei count, const GLint *value);                         
        typedef void (GL_APIENTRY * Uniform3ivProc)(GLint location, GLsizei count, const GLint *value);                       
        typedef void (GL_APIENTRY * Uniform4ivProc)(GLint location, GLsizei count, const GLint *value);                         
        typedef void (GL_APIENTRY * UniformMatrix2fvProc)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
        typedef void (GL_APIENTRY * UniformMatrix3fvProc)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
        typedef void (GL_APIENTRY * UniformMatrix4fvProc)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);  
        typedef void (GL_APIENTRY * ValidateProgramProc)(GLuint program);                                                             
        typedef void (GL_APIENTRY * VertexAttrib1dProc)(GLuint index, GLdouble x);                                                    
        typedef void (GL_APIENTRY * VertexAttrib1dvProc)(GLuint index, const GLdouble *v);                                          
        typedef void (GL_APIENTRY * VertexAttrib1fProc)(GLuint index, GLfloat x);                                                     
        typedef void (GL_APIENTRY * VertexAttrib1fvProc)(GLuint index, const GLfloat *v);                                             
        typedef void (GL_APIENTRY * VertexAttrib1sProc)(GLuint index, GLshort x);                                                     
        typedef void (GL_APIENTRY * VertexAttrib1svProc)(GLuint index, const GLshort *v);                                             
        typedef void (GL_APIENTRY * VertexAttrib2dProc)(GLuint index, GLdouble x, GLdouble y);                                        
        typedef void (GL_APIENTRY * VertexAttrib2dvProc)(GLuint index, const GLdouble *v);                                            
        typedef void (GL_APIENTRY * VertexAttrib2fProc)(GLuint index, GLfloat x, GLfloat y);                                          
        typedef void (GL_APIENTRY * VertexAttrib2fvProc)(GLuint index, const GLfloat *v);                                             
        typedef void (GL_APIENTRY * VertexAttrib2sProc)(GLuint index, GLshort x, GLshort y);                                          
        typedef void (GL_APIENTRY * VertexAttrib2svProc)(GLuint index, const GLshort *v);                                             
        typedef void (GL_APIENTRY * VertexAttrib3dProc)(GLuint index, GLdouble x, GLdouble y, GLdouble z);                            
        typedef void (GL_APIENTRY * VertexAttrib3dvProc)(GLuint index, const GLdouble *v);                                            
        typedef void (GL_APIENTRY * VertexAttrib3fProc)(GLuint index, GLfloat x, GLfloat y, GLfloat z);                               
        typedef void (GL_APIENTRY * VertexAttrib3fvProc)(GLuint index, const GLfloat *v);                                             
        typedef void (GL_APIENTRY * VertexAttrib3sProc)(GLuint index, GLshort x, GLshort y, GLshort z);                               
        typedef void (GL_APIENTRY * VertexAttrib3svProc)(GLuint index, const GLshort *v);                                             
        typedef void (GL_APIENTRY * VertexAttrib4NbvProc)(GLuint index, const GLbyte *v);                                             
        typedef void (GL_APIENTRY * VertexAttrib4NivProc)(GLuint index, const GLint *v);                                              
        typedef void (GL_APIENTRY * VertexAttrib4NsvProc)(GLuint index, const GLshort *v);                                            
        typedef void (GL_APIENTRY * VertexAttrib4NubProc)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);                  
        typedef void (GL_APIENTRY * VertexAttrib4NubvProc)(GLuint index, const GLubyte *v);                                           
        typedef void (GL_APIENTRY * VertexAttrib4NuivProc)(GLuint index, const GLuint *v);                                            
        typedef void (GL_APIENTRY * VertexAttrib4NusvProc)(GLuint index, const GLushort *v);                                          
        typedef void (GL_APIENTRY * VertexAttrib4bvProc)(GLuint index, const GLbyte *v);                                              
        typedef void (GL_APIENTRY * VertexAttrib4dProc)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);                
        typedef void (GL_APIENTRY * VertexAttrib4dvProc)(GLuint index, const GLdouble *v);                                            
        typedef void (GL_APIENTRY * VertexAttrib4fProc)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);                    
        typedef void (GL_APIENTRY * VertexAttrib4fvProc)(GLuint index, const GLfloat *v);                                             
        typedef void (GL_APIENTRY * VertexAttrib4ivProc)(GLuint index, const GLint *v);                                               
        typedef void (GL_APIENTRY * VertexAttrib4sProc)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);                    
        typedef void (GL_APIENTRY * VertexAttrib4svProc)(GLuint index, const GLshort *v);                                             
        typedef void (GL_APIENTRY * VertexAttrib4ubvProc)(GLuint index, const GLubyte *v);                                            
        typedef void (GL_APIENTRY * VertexAttrib4uivProc)(GLuint index, const GLuint *v);                                             
        typedef void (GL_APIENTRY * VertexAttrib4usvProc)(GLuint index, const GLushort *v);                                           
        typedef void (GL_APIENTRY * VertexAttribPointerProc)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
        typedef void (GL_APIENTRY * UniformMatrix2x3fvProc)( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value );                         
        typedef void (GL_APIENTRY * UniformMatrix3x2fvProc)( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value );
        typedef void (GL_APIENTRY * UniformMatrix2x4fvProc)( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value );
        typedef void (GL_APIENTRY * UniformMatrix4x2fvProc)( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value );
        typedef void (GL_APIENTRY * UniformMatrix3x4fvProc)( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value );
        typedef void (GL_APIENTRY * UniformMatrix4x3fvProc)( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value );
        typedef void (GL_APIENTRY * ProgramParameteriProc)( GLuint program, GLenum pname, GLint value );
        typedef void (GL_APIENTRY * FramebufferTextureProc)( GLenum target, GLenum attachment, GLuint texture, GLint level );
        typedef void (GL_APIENTRY * FramebufferTextureLayerProc)( GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer );
        typedef void (GL_APIENTRY * FramebufferTextureFaceProc)( GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face );
        typedef void (GL_APIENTRY * PatchParameteriProc)( GLenum pname, GLint value );
        typedef void (GL_APIENTRY * PatchParameterfvProc)( GLenum pname, const GLfloat* values );
        typedef void (GL_APIENTRY * GetUniformuivProc)( GLuint program, GLint location, GLuint* params );
        typedef void (GL_APIENTRY * BindFragDataLocationProc)( GLuint program, GLuint color, const GLchar* name );
        typedef GLint (GL_APIENTRY * GetFragDataLocationProc)( GLuint program, const GLchar* name );
        typedef void (GL_APIENTRY * Uniform1uiProc)( GLint location, GLuint v0 );
        typedef void (GL_APIENTRY * Uniform2uiProc)( GLint location, GLuint v0, GLuint v1 );
        typedef void (GL_APIENTRY * Uniform3uiProc)( GLint location, GLuint v0, GLuint v1, GLuint v2 );
        typedef void (GL_APIENTRY * Uniform4uiProc)( GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3 );
        typedef void (GL_APIENTRY * Uniform1uivProc)( GLint location, GLsizei count, const GLuint *value );
        typedef void (GL_APIENTRY * Uniform2uivProc)( GLint location, GLsizei count, const GLuint *value );
        typedef void (GL_APIENTRY * Uniform3uivProc)( GLint location, GLsizei count, const GLuint *value );
        typedef void (GL_APIENTRY * Uniform4uivProc)( GLint location, GLsizei count, const GLuint *value );
        typedef GLuint (GL_APIENTRY * GetHandleProc) (GLenum pname);
        typedef void (GL_APIENTRY * GetUniformIndicesProc)(GLuint program, GLsizei uniformCount, const GLchar* *uniformNames, GLuint *uniformIndices);
        typedef void (GL_APIENTRY * GetActiveUniformsivProc)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
        typedef void (GL_APIENTRY * GetActiveUniformNameProc)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
        typedef GLuint (GL_APIENTRY * GetUniformBlockIndexProc)(GLuint program, const GLchar *uniformBlockName);
        typedef void (GL_APIENTRY * GetActiveUniformBlockivProc)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
        typedef void (GL_APIENTRY * GetActiveUniformBlockNameProc)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
        typedef void (GL_APIENTRY * UniformBlockBindingProc)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
        typedef void (GL_APIENTRY * GetProgramBinaryProc)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary);
        typedef void (GL_APIENTRY * ProgramBinaryProc)(GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length);

        BlendEquationSeparateProc _glBlendEquationSeparate;        
        DrawBuffersProc _glDrawBuffers;
        StencilOpSeparateProc _glStencilOpSeparate;
        StencilFuncSeparateProc _glStencilFuncSeparate;
        StencilMaskSeparateProc _glStencilMaskSeparate;
        AttachShaderProc _glAttachShader;
        BindAttribLocationProc _glBindAttribLocation;
        CompileShaderProc _glCompileShader;
        CreateProgramProc _glCreateProgram;
        CreateShaderProc _glCreateShader;
        DeleteProgramProc _glDeleteProgram;
        DeleteShaderProc _glDeleteShader;
        DetachShaderProc _glDetachShader;
        DisableVertexAttribArrayProc _glDisableVertexAttribArray;
        EnableVertexAttribArrayProc _glEnableVertexAttribArray;
        GetActiveAttribProc _glGetActiveAttrib;
        GetActiveUniformProc _glGetActiveUniform;
        GetAttachedShadersProc _glGetAttachedShaders;
        GetAttribLocationProc _glGetAttribLocation;
        GetProgramivProc _glGetProgramiv;
        GetProgramInfoLogProc _glGetProgramInfoLog;
        GetShaderivProc _glGetShaderiv;
        GetShaderInfoLogProc _glGetShaderInfoLog;
        GetShaderSourceProc _glGetShaderSource;
        GetUniformLocationProc _glGetUniformLocation;
        GetUniformfvProc _glGetUniformfv;
        GetUniformivProc _glGetUniformiv;
        GetVertexAttribdvProc _glGetVertexAttribdv;
        GetVertexAttribfvProc _glGetVertexAttribfv;
        GetVertexAttribivProc _glGetVertexAttribiv;
        GetVertexAttribPointervProc _glGetVertexAttribPointerv;
        IsProgramProc _glIsProgram;
        IsShaderProc _glIsShader;
        LinkProgramProc _glLinkProgram;
        ShaderSourceProc _glShaderSource;
        UseProgramProc _glUseProgram;
        Uniform1fProc _glUniform1f;
        Uniform2fProc _glUniform2f;
        Uniform3fProc _glUniform3f;
        Uniform4fProc _glUniform4f;
        Uniform1iProc _glUniform1i;
        Uniform2iProc _glUniform2i;
        Uniform3iProc _glUniform3i;
        Uniform4iProc _glUniform4i;
        Uniform1fvProc _glUniform1fv;
        Uniform2fvProc _glUniform2fv;
        Uniform3fvProc _glUniform3fv;
        Uniform4fvProc _glUniform4fv;
        Uniform1ivProc _glUniform1iv;
        Uniform2ivProc _glUniform2iv;
        Uniform3ivProc _glUniform3iv;
        Uniform4ivProc _glUniform4iv;
        UniformMatrix2fvProc _glUniformMatrix2fv;
        UniformMatrix3fvProc _glUniformMatrix3fv;
        UniformMatrix4fvProc _glUniformMatrix4fv;
        ValidateProgramProc _glValidateProgram;
        VertexAttrib1dProc _glVertexAttrib1d;
        VertexAttrib1dvProc _glVertexAttrib1dv;
        VertexAttrib1fProc _glVertexAttrib1f;
        VertexAttrib1fvProc _glVertexAttrib1fv;
        VertexAttrib1sProc _glVertexAttrib1s;
        VertexAttrib1svProc _glVertexAttrib1sv;
        VertexAttrib2dProc _glVertexAttrib2d;
        VertexAttrib2dvProc _glVertexAttrib2dv;
        VertexAttrib2fProc _glVertexAttrib2f;
        VertexAttrib2fvProc _glVertexAttrib2fv;
        VertexAttrib2sProc _glVertexAttrib2s;
        VertexAttrib2svProc _glVertexAttrib2sv;
        VertexAttrib3dProc _glVertexAttrib3d;
        VertexAttrib3dvProc _glVertexAttrib3dv;
        VertexAttrib3fProc _glVertexAttrib3f;
        VertexAttrib3fvProc _glVertexAttrib3fv;
        VertexAttrib3sProc _glVertexAttrib3s;
        VertexAttrib3svProc _glVertexAttrib3sv;
        VertexAttrib4NbvProc _glVertexAttrib4Nbv;
        VertexAttrib4NivProc _glVertexAttrib4Niv;
        VertexAttrib4NsvProc _glVertexAttrib4Nsv;
        VertexAttrib4NubProc _glVertexAttrib4Nub;
        VertexAttrib4NubvProc _glVertexAttrib4Nubv;
        VertexAttrib4NuivProc _glVertexAttrib4Nuiv;
        VertexAttrib4NusvProc _glVertexAttrib4Nusv;
        VertexAttrib4bvProc _glVertexAttrib4bv;
        VertexAttrib4dProc _glVertexAttrib4d;
        VertexAttrib4dvProc _glVertexAttrib4dv;
        VertexAttrib4fProc _glVertexAttrib4f;
        VertexAttrib4fvProc _glVertexAttrib4fv;
        VertexAttrib4ivProc _glVertexAttrib4iv;
        VertexAttrib4sProc _glVertexAttrib4s;
        VertexAttrib4svProc _glVertexAttrib4sv;
        VertexAttrib4ubvProc _glVertexAttrib4ubv;
        VertexAttrib4uivProc _glVertexAttrib4uiv;
        VertexAttrib4usvProc _glVertexAttrib4usv;
        VertexAttribPointerProc _glVertexAttribPointer;

        GetInfoLogARBProc _glGetInfoLogARB;
        GetObjectParameterivARBProc _glGetObjectParameterivARB;
        DeleteObjectARBProc _glDeleteObjectARB;
        GetHandleProc _glGetHandleARB;

        // GL 2.1
        UniformMatrix2x3fvProc _glUniformMatrix2x3fv;
        UniformMatrix3x2fvProc _glUniformMatrix3x2fv;
        UniformMatrix2x4fvProc _glUniformMatrix2x4fv;
        UniformMatrix4x2fvProc _glUniformMatrix4x2fv;
        UniformMatrix3x4fvProc _glUniformMatrix3x4fv;
        UniformMatrix4x3fvProc _glUniformMatrix4x3fv;

        // EXT_geometry_shader4
        ProgramParameteriProc _glProgramParameteri;
        FramebufferTextureProc _glFramebufferTexture;
        FramebufferTextureLayerProc _glFramebufferTextureLayer;
        FramebufferTextureFaceProc _glFramebufferTextureFace;

        // ARB_tesselation_shader
        PatchParameteriProc _glPatchParameteri;
        PatchParameterfvProc _glPatchParameterfv;

        // EXT_gpu_shader4
        GetUniformuivProc _glGetUniformuiv;
        BindFragDataLocationProc _glBindFragDataLocation;
        GetFragDataLocationProc _glGetFragDataLocation;
        Uniform1uiProc _glUniform1ui;
        Uniform2uiProc _glUniform2ui;
        Uniform3uiProc _glUniform3ui;
        Uniform4uiProc _glUniform4ui;
        Uniform1uivProc _glUniform1uiv;
        Uniform2uivProc _glUniform2uiv;
        Uniform3uivProc _glUniform3uiv;
        Uniform4uivProc _glUniform4uiv;

        // ARB_uniform_buffer_object
        GetUniformIndicesProc _glGetUniformIndices;
        GetActiveUniformsivProc _glGetActiveUniformsiv;
        GetActiveUniformNameProc _glGetActiveUniformName;
        GetUniformBlockIndexProc _glGetUniformBlockIndex;
        GetActiveUniformBlockivProc _glGetActiveUniformBlockiv;
        GetActiveUniformBlockNameProc _glGetActiveUniformBlockName;
        UniformBlockBindingProc _glUniformBlockBinding;

        //ARB_get_program_binary
        GetProgramBinaryProc _glGetProgramBinary;
        ProgramBinaryProc _glProgramBinary;
};

}

#endif