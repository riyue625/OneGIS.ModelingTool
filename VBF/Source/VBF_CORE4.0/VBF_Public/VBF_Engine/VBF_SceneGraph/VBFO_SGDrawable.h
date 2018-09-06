#ifndef OSG_DRAWABLE
#define OSG_DRAWABLE 1

#include <Types/VBF_BoundingBox.h>
#include <VBF_Engine/VBF_SceneGraph/VBFO_Shape.h>
#include <VBF_Engine/VBF_SceneGraph/VBF_BufferObject.h>
#include <VBF_Engine/VBF_SceneGraph/PrimitiveSet>
#include <VBF_Engine/VBF_SceneGraph/VBF_RenderInfo.h>
#include <VBF_Engine/VBF_SceneGraph/IVBF_SGNode.h>

#ifndef GL_NV_occlusion_query

    #define GL_OCCLUSION_TEST_HP                0x8165
    #define GL_OCCLUSION_TEST_RESULT_HP         0x8166
    #define GL_PIXEL_COUNTER_BITS_NV            0x8864
    #define GL_CURRENT_OCCLUSION_QUERY_ID_NV    0x8865
    #define GL_PIXEL_COUNT_NV                   0x8866
    #define GL_PIXEL_COUNT_AVAILABLE_NV         0x8867

#endif

#ifndef GL_ARB_occlusion_query

    #define GL_SAMPLES_PASSED_ARB               0x8914
    #define GL_QUERY_COUNTER_BITS_ARB           0x8864
    #define GL_CURRENT_QUERY_ARB                0x8865
    #define GL_QUERY_RESULT_ARB                 0x8866
    #define GL_QUERY_RESULT_AVAILABLE_ARB       0x8867

#endif


#ifndef GL_TIME_ELAPSED
    #define GL_TIME_ELAPSED                    0x88BF
    #define GL_TIMESTAMP                       0x8E28
#endif

#ifndef GL_QUERY_RESULT
    #define GL_QUERY_RESULT                     0x8866
    #define GL_QUERY_RESULT_AVAILABLE           0x8867
#endif


#if !defined(GL_EXT_timer_query) && !defined(OSG_GL3_AVAILABLE)
    #ifdef _WIN32
        typedef          __int64 GLint64EXT;
        typedef unsigned __int64 GLuint64EXT;
    #else
        typedef long long int GLint64EXT;
        typedef unsigned long long int GLuint64EXT;
    #endif
#endif


namespace osg {


class Vec2f;
class Vec3f;
class Vec4f;
class Vec4ub;
class Geometry;
class NodeVisitor;
class ArrayDispatchers;

// USE_SEPARATE_COMPILE_AND_EXECUTE ���ڸı�Draw��������ʾ�б�����ķ�ʽ��
// �ݷ��֣�NVidia drivers �Ż�COMPILE_AND_EXECUTE��ȫʧ�ܣ���û����ʾ�б�������
// ���ǰ�COMPILE��EXECUTE�ֿ������Ż�Ч������?!  
// ����ΪĬ�Ϸ�ʽ����COMPILE��glCallList��������ʹ��COMPILE_AND_EXECUTE��

#define USE_SEPARATE_COMPILE_AND_EXECUTE



/** �ɻ��ƶ���Ļ��ࡣDrawable����û��drawing primitives�������������ṩ��
 *  ע�⣺Drawable���ǽڵ㣬����ֱ�Ӽ��뵽����ͼ�С���Ҫ�����ȼ��뵽һ��Ҷ�ڵ��У��ټ��뵽����ͼ��
 *  Drawable��һ��StateSet������ָ�룬StateSet���Ա���ͬ��Drawable������ 
 *  ����StateSet������������ܣ����Լ���OpenGL state�л��Ĵ����Ϳ�����
 *  DrawableҲ���Ա���ͬ��Ҷ�ڵ㹲������ˣ���ͬ��geometry (��װ���ڴ�һ��) ���Ա����ڳ���ͼ�Ĳ�ͬ���֡�
*/
class OSG_EXPORT Drawable : public CVBF_Object
{
    public:

        static unsigned int s_numberDrawablesReusedLastInLastFrame;
        static unsigned int s_numberNewDrawablesInLastFrame;
        static unsigned int s_numberDeletedDrawablesInLastFrame;


		// 1���빹�캯���йص�����

        Drawable();

        /** �������캯��, ͨ��CopyOp���ƶ�̬���ݵ�shallow vs deep������*/
        Drawable(const Drawable& drawable,const CopyOp& copyop=CopyOp::SHALLOW_COPY);

		// 2���������Ϣ�йص�����

        virtual bool isSameKindAs(const CVBF_Object* obj) const { return dynamic_cast<const Drawable*>(obj)!=NULL; }
        virtual const char* libraryName() const { return "osg"; }
        virtual const char* className() const { return "Drawable"; }



  		// 3������ת��
  
		/** ��ͬ��dynamic_cast<Geometry*>(this).*/
        virtual Geometry* asGeometry() { return 0; }
		virtual const Geometry* asGeometry() const { return 0; }





        /** ���ݻص���������������ݵı仯�������ö�̬/��̬����ģʽ��*/
        virtual void computeDataVariance();




        typedef std::vector<IVBF_SGNode*> ParentList;

        /** ��ȡ���ڵ���б� */
        inline const ParentList& getParents() const { return _parents; }

        /** ��ȡ���ڵ��б��Ŀ�������ֹ���ڵ��б������ġ�*/
        inline ParentList getParents() { return _parents; }

		/** ��ȡ��i�����ڵ㣨ע��i���磩 */
		inline IVBF_SGNode* getParent(unsigned int i)  { return _parents[i]; }
		inline const IVBF_SGNode* getParent(unsigned int i) const  { return _parents[i]; }

		/** ��ȡ���ڵ�ĸ��� */
        inline unsigned int getNumParents() const { return static_cast<unsigned int>(_parents.size()); }

        /** Get the list of matrices that transform this node from local coordinates to world coordinates.
          * The optional IVBF_SGNode* haltTraversalAtNode allows the user to prevent traversal beyond a specifed node. */
        osg::MatrixList getWorldMatrices(const osg::IVBF_SGNode* haltTraversalAtNode=0) const;


		//xahg h00017
//		inline bool getEnableReflection()
//		{
//		    return _enableReflection;
//		}
//		inline void setEnableReflection(bool flag)
//		{
//		    _enableReflection = flag;
//		}
		//xahg h00017

  		// 5��״̬������ص�����


        /** ����״̬���ϣ���ǰ��״̬���ϻ��Զ��������ü�����*/
        void setStateSet(StateSet* stateset);

		/** ��ȡ״̬����*/
		inline StateSet* getStateSet() { return _stateset.get();}
		inline const StateSet* getStateSet() const { return _stateset.get();}

        /** ��ȡ״̬���ϣ�����������򴴽�һ����*/
        StateSet* getOrCreateStateSet();



 		// 6����Χ����ص�����



        /** Set the initial bounding volume to use when computing the overall bounding volume.*/
        void setInitialBound(const osg::BoundingBox& bbox) { _initialBound = bbox; dirtyBound(); }

        /** Set the initial bounding volume to use when computing the overall bounding volume.*/
        const BoundingBox& getInitialBound() const { return _initialBound; }

        /** Dirty the bounding box, forcing a computeBound() on the next call
          * to getBound(). Should be called in the internal geometry of the Drawable
          * is modified.*/
        void dirtyBound();

        /** Get BoundingBox of Drawable.
          * If the BoundingBox is not up to date then its updated via an internal call to computeBond().
          */
        inline const BoundingBox& getBound() const
        {
            if(!_boundingBoxComputed)
            {
                _boundingBox = _initialBound;
                if (_computeBoundCallback.valid()) 
                    _boundingBox.expandBy(_computeBoundCallback->computeBound(*this));
                else
                    _boundingBox.expandBy(computeBound());
                    
                _boundingBoxComputed = true;
            }
            return _boundingBox;
        }


        /** Compute the bounding box around Drawables's geometry.*/
        virtual BoundingBox computeBound() const;

        /** Callback to allow users to override the default computation of bounding volume. */
        struct ComputeBoundingBoxCallback : public osg::CVBF_Object
        {
            ComputeBoundingBoxCallback() {}

            ComputeBoundingBoxCallback(const ComputeBoundingBoxCallback&,const CopyOp&) {}

            META_Object(osg,ComputeBoundingBoxCallback);

            virtual BoundingBox computeBound(const osg::Drawable&) const  { return BoundingBox(); }
        };

        /** Set the compute bound callback to override the default computeBound.*/
        void setComputeBoundingBoxCallback(ComputeBoundingBoxCallback* callback) { _computeBoundCallback = callback; }

        /** Get the compute bound callback.*/
        ComputeBoundingBoxCallback* getComputeBoundingBoxCallback() { return _computeBoundCallback.get(); }

        /** Get the const compute bound callback.*/
        const ComputeBoundingBoxCallback* getComputeBoundingBoxCallback() const { return _computeBoundCallback.get(); }






        /** Set the Shape of the \c Drawable. The shape can be used to
         *  speed up collision detection or as a guide for procedural
         *  geometry generation.
         * @see osg::Shape.
        */
        inline void setShape(Shape* shape) { _shape = shape; }

        /** Get the Shape of the Drawable.*/
        inline Shape* getShape() { return _shape.get(); }

        /** Get the const Shape of the const Drawable.*/
        inline const Shape* getShape() const { return _shape.get(); }




		// 8������ʾ�б���ص�����



        /** Set the drawable so that it can or cannot be used in conjunction with OpenGL
          * display lists.  When set to true, calls to Drawable::setUseDisplayList,
          * whereas when set to false, no display lists can be created and calls
          * to setUseDisplayList are ignored, and a warning is produced.  The latter
          * is typically used to guard against the switching on of display lists
          * on objects with dynamic internal data such as continuous Level of Detail
          * algorithms.*/
        void setSupportsDisplayList(bool flag);

        /** Get whether display lists are supported for this drawable instance.*/
        inline bool getSupportsDisplayList() const { return _supportsDisplayList; }


        /** When set to true, force the draw method to use OpenGL Display List for rendering.
            If false, rendering directly.  If the display list has not been compiled
            already, the next call to draw will automatically create the display list.*/
        void setUseDisplayList(bool flag);

        /** Return whether OpenGL display lists are being used for rendering.*/
        inline bool getUseDisplayList() const { return _useDisplayList; }

        /** Return OpenGL display list for specified contextID. */
        inline GLuint& getDisplayList(unsigned int contextID) const { return _globjList[contextID]; }

        /** When set to true, ignore the setUseDisplayList() settings, and hints to the drawImplementation 
            method to use OpenGL vertex buffer objects for rendering.*/
        virtual void setUseVertexBufferObjects(bool flag);

        /** Return whether OpenGL vertex buffer objects should be used when supported by OpenGL driver.*/
        inline bool getUseVertexBufferObjects() const { return _useVertexBufferObjects; }


        /** Force a recompile on next draw() of any OpenGL display list associated with this geoset.*/
        virtual void dirtyDisplayList();


        /** Return the estimated size of GLObjects (display lists/vertex buffer objects) that are associated with this drawable.
          * This size is used a hint for reuse of deleted display lists/vertex buffer objects.  */
        virtual unsigned int getGLObjectSizeHint() const { return 0; }











        /** Draw OpenGL primitives.
          * If the \c Drawable has \c _useDisplayList set to \c true, then use
          * an OpenGL display list, automatically compiling one if required.
          * Otherwise, call \c drawImplementation().
          * @note This method should \e not be overridden in subclasses, as it
          *       manages the optional display list (notice this is not even
          *       \c virtual). Subclasses should override
          *       \c drawImplementation() instead.
          */
        inline void draw(RenderInfo& renderInfo) const;

        /** Immediately compile this \c Drawable into an OpenGL Display List/VertexBufferObjects.
          * @note Operation is ignored if \c _useDisplayList is \c false or VertexBufferObjects are not used.
        */
        virtual void compileGLObjects(RenderInfo& renderInfo) const;

        /** Set whether to use a mutex to ensure ref() and unref() are thread safe.*/
        virtual void setThreadSafeRefUnref(bool threadSafe);

        /** Resize any per context GLObject buffers to specified size. */
        virtual void resizeGLObjectBuffers(unsigned int maxSize);

        /** If State is non-zero, this function releases OpenGL objects for
          * the specified graphics context. Otherwise, releases OpenGL objects
          * for all graphics contexts. */
        virtual void releaseGLObjects(State* state=0) const;







        struct UpdateCallback : public virtual osg::CVBF_Object
        {
            UpdateCallback() {}

            UpdateCallback(const UpdateCallback&,const CopyOp&) {}

            META_Object(osg,UpdateCallback);

            /** do customized update code.*/
            virtual void update(osg::NodeVisitor*, osg::Drawable*) {}
        };

        /** Set the UpdateCallback which allows users to attach customize the updating of an object during the update traversal. */
        virtual void setUpdateCallback(UpdateCallback* ac);

        /** Get the non const UpdateCallback.*/
        UpdateCallback* getUpdateCallback() { return _updateCallback.get(); }

        /** Get the const UpdateCallback.*/
        const UpdateCallback* getUpdateCallback() const { return _updateCallback.get(); }

        /** Return whether this Drawable has update callbacks associated with it, and therefore must be traversed.*/
        bool requiresUpdateTraversal() const { return _updateCallback.valid() || (_stateset.valid() && _stateset->requiresUpdateTraversal()); }


        struct EventCallback : public virtual osg::CVBF_Object
        {
            EventCallback() {}

            EventCallback(const EventCallback&,const CopyOp&) {}

            META_Object(osg,EventCallback);

            /** do customized Event code. */
            virtual void event(osg::NodeVisitor*, osg::Drawable*) {}
        };

        /** Set the EventCallback which allows users to attach customize the updating of an object during the Event traversal.*/
        virtual void setEventCallback(EventCallback* ac);

        /** Get the non const EventCallback.*/
        EventCallback* getEventCallback() { return _eventCallback.get(); }

        /** Get the const EventCallback.*/
        const EventCallback* getEventCallback() const { return _eventCallback.get(); }

        /** Return whether this Drawable has event callbacks associated with it, and therefore must be traversed.*/
        bool requiresEventTraversal() const { return _eventCallback.valid() || (_stateset.valid() && _stateset->requiresEventTraversal()); }
/*
		class IVBF_CullCallback : public virtual CVBF_Object
		{
		public:
           virtual bool cull(osg::NodeVisitor*, osg::Drawable*, osg::State*) const =0;
           virtual bool cull(osg::NodeVisitor* nv, osg::Drawable* drawable, osg::RenderInfo* renderInfo) const=0;
 
		};
*/
        struct CullCallback : public virtual osg::CVBF_Object
        {
            CullCallback() {}

            CullCallback(const CullCallback&,const CopyOp&) {}

            META_Object(osg,CullCallback);

            /** deprecated.*/
            virtual bool cull(osg::NodeVisitor*, osg::Drawable*, osg::State*) const { return false; }

            /** do customized cull code, return true if drawable should be culled.*/
            virtual bool cull(osg::NodeVisitor* nv, osg::Drawable* drawable, osg::RenderInfo* renderInfo) const { return cull(nv, drawable, renderInfo? renderInfo->getState():0); }
        };

        /** Set the CullCallback which allows users to customize the culling of Drawable during the cull traversal.*/
        virtual void setCullCallback(CullCallback* cc) { _cullCallback=cc; }

        /** Get the non const CullCallback.*/
        CullCallback* getCullCallback() { return _cullCallback.get(); }

        /** Get the const CullCallback.*/
        const CullCallback* getCullCallback() const { return _cullCallback.get(); }




        /** Callback attached to an Drawable which allows the users to customize the drawing of an exist Drawable object.
          * The draw callback is implement as a replacement to the Drawable's own drawImplementation() method, if the
          * the user intends to decorate the existing draw code then simple call the drawable->drawImplementation() from
          * with the callbacks drawImplementation() method. This allows the users to do both pre and post callbacks
          * without fuss and can even disable the inner draw if required.*/
        struct DrawCallback : public virtual osg::CVBF_Object
        {
            DrawCallback() {}

            DrawCallback(const DrawCallback&,const CopyOp&) {}

            META_Object(osg,DrawCallback);

            /** do customized draw code.*/
            virtual void drawImplementation(osg::RenderInfo& /*renderInfo*/,const osg::Drawable* /*drawable*/) const {}
        };

        /** Set the DrawCallback which allows users to attach customize the drawing of existing Drawable object.*/
        virtual void setDrawCallback(DrawCallback* dc) { _drawCallback=dc; dirtyDisplayList(); }

        /** Get the non const DrawCallback.*/
        DrawCallback* getDrawCallback() { return _drawCallback.get(); }

        /** Get the const DrawCallback.*/
        const DrawCallback* getDrawCallback() const { return _drawCallback.get(); }

        /** drawImplementation(RenderInfo&) is a pure virtual method for the actual implementation of OpenGL drawing calls, such as vertex arrays and primitives, that
          * must be implemented in concrete subclasses of the Drawable base class, examples include osg::Geometry and osg::ShapeDrawable.
          * drawImplementation(RenderInfo&) is called from the draw(RenderInfo&) method, with the draw method handling management of OpenGL display lists,
          * and drawImplementation(RenderInfo&) handling the actual drawing itself.  
          * @param renderInfo The osg::RenderInfo object that encapsulates the current rendering information including the osg::State OpenGL state for the current graphics context. */
        virtual void drawImplementation(RenderInfo& renderInfo) const = 0;


        /** Return a OpenGL display list handle a newly generated or reused from display list cache. */
        static GLuint generateDisplayList(unsigned int contextID, unsigned int sizeHint = 0);

        // ����/��ȡ�����ڣ���ɾ����ʾ�б����棩�е���ʾ�б�����С����,Ϊ������
        static void setMinimumNumberOfDisplayListsToRetainInCache(unsigned int minimum);
        static unsigned int getMinimumNumberOfDisplayListsToRetainInCache();

        /** Use deleteDisplayList instead of glDeleteList to allow
          * OpenGL display list to be cached until they can be deleted
          * by the OpenGL context in which they were created, specified
          * by contextID.*/
        static void deleteDisplayList(unsigned int contextID,GLuint globj, unsigned int sizeHint = 0);

        /** Flush all the cached display list which need to be deleted
          * in the OpenGL context related to contextID.*/
        static void flushAllDeletedDisplayLists(unsigned int contextID);

        /** Flush all the cached display list which need to be deleted
          * in the OpenGL context related to contextID.
          * Note, unlike flush no OpenGL calls are made, instead the handles are all removed.
          * this call is useful for when an OpenGL context has been destroyed. */
        static void discardAllDeletedDisplayLists(unsigned int contextID);

        /** Flush the cached display list which need to be deleted
          * in the OpenGL context related to contextID.*/
        static void flushDeletedDisplayLists(unsigned int contextID,double& availableTime);

        typedef unsigned int AttributeType;

        enum AttributeTypes
        {
            VERTICES            = 0,
            WEIGHTS             = 1,
            NORMALS             = 2,
            COLORS              = 3,
            SECONDARY_COLORS    = 4,
            FOG_COORDS          = 5,
            ATTRIBUTE_6         = 6,
            ATTRIBUTE_7         = 7,
            TEXTURE_COORDS      = 8,
            TEXTURE_COORDS_0    = TEXTURE_COORDS,
            TEXTURE_COORDS_1    = TEXTURE_COORDS_0+1,
            TEXTURE_COORDS_2    = TEXTURE_COORDS_0+2,
            TEXTURE_COORDS_3    = TEXTURE_COORDS_0+3,
            TEXTURE_COORDS_4    = TEXTURE_COORDS_0+4,
            TEXTURE_COORDS_5    = TEXTURE_COORDS_0+5,
            TEXTURE_COORDS_6    = TEXTURE_COORDS_0+6,
            TEXTURE_COORDS_7    = TEXTURE_COORDS_0+7
            // only eight texture coord examples provided here, but underlying code can handle any no of texture units,
            // simply co them as (TEXTURE_COORDS_0+unit).
        };

        class AttributeFunctor
        {
        public:
            virtual ~AttributeFunctor() {}

            virtual void apply(AttributeType,unsigned int,GLbyte*) {}
            virtual void apply(AttributeType,unsigned int,GLshort*) {}
            virtual void apply(AttributeType,unsigned int,GLint*) {}

            virtual void apply(AttributeType,unsigned int,GLubyte*) {}
            virtual void apply(AttributeType,unsigned int,GLushort*) {}
            virtual void apply(AttributeType,unsigned int,GLuint*) {}

            virtual void apply(AttributeType,unsigned int,float*) {}
            virtual void apply(AttributeType,unsigned int,Vec2*) {}
            virtual void apply(AttributeType,unsigned int,Vec3*) {}
            virtual void apply(AttributeType,unsigned int,Vec4*) {}
            virtual void apply(AttributeType,unsigned int,Vec4ub*) {}

            virtual void apply(AttributeType,unsigned int,double*) {}
            virtual void apply(AttributeType,unsigned int,Vec2d*) {}
            virtual void apply(AttributeType,unsigned int,Vec3d*) {}
            virtual void apply(AttributeType,unsigned int,Vec4d*) {}
        };


        /** Return true if the Drawable subclass supports accept(AttributeFunctor&).*/
        virtual bool supports(const AttributeFunctor&) const { return false; }

        /** accept an AttributeFunctor and call its methods to tell it about the internal attributes that this Drawable has.
          * return true if functor handled by drawable,
          * return false on failure of drawable to generate functor calls.*/
        virtual void accept(AttributeFunctor&) {}


        class ConstAttributeFunctor
        {
        public:

            virtual ~ConstAttributeFunctor() {}

            virtual void apply(AttributeType,unsigned int,const GLbyte*) {}
            virtual void apply(AttributeType,unsigned int,const GLshort*) {}
            virtual void apply(AttributeType,unsigned int,const GLint*) {}

            virtual void apply(AttributeType,unsigned int,const GLubyte*) {}
            virtual void apply(AttributeType,unsigned int,const GLushort*) {}
            virtual void apply(AttributeType,unsigned int,const GLuint*) {}

            virtual void apply(AttributeType,unsigned int,const float*) {}
            virtual void apply(AttributeType,unsigned int,const Vec2*) {}
            virtual void apply(AttributeType,unsigned int,const Vec3*) {}
            virtual void apply(AttributeType,unsigned int,const Vec4*) {}
            virtual void apply(AttributeType,unsigned int,const Vec4ub*) {}

            virtual void apply(AttributeType,unsigned int,const double*) {}
            virtual void apply(AttributeType,unsigned int,const Vec2d*) {}
            virtual void apply(AttributeType,unsigned int,const Vec3d*) {}
            virtual void apply(AttributeType,unsigned int,const Vec4d*) {}
        };

        /** Return true if the Drawable subclass supports accept(ConstAttributeFunctor&).*/
        virtual bool supports(const ConstAttributeFunctor&) const { return false; }

        /** Accept an AttributeFunctor and call its methods to tell it about the internal attributes that this Drawable has.
          * return true if functor handled by drawable,
          * return false on failure of drawable to generate functor calls.*/
        virtual void accept(ConstAttributeFunctor&) const {}



        /** Return true if the Drawable subclass supports accept(PrimitiveFunctor&).*/
        virtual bool supports(const PrimitiveFunctor&) const { return false; }

        /** Accept a PrimitiveFunctor and call its methods to tell it about the internal primitives that this Drawable has.
          * return true if functor handled by drawable, return false on failure of drawable to generate functor calls.
          * Note, PrimtiveFunctor only provides const access of the primitives, as primitives may be procedurally generated
          * so one cannot modify it.*/
        virtual void accept(PrimitiveFunctor&) const {}

        /** Return true if the Drawable subclass supports accept(PrimitiveIndexFunctor&).*/
        virtual bool supports(const PrimitiveIndexFunctor&) const { return false; }

        /** Accept a PrimitiveIndexFunctor and call its methods to tell it about the internal primitives that this Drawable has.
          * return true if functor handled by drawable, return false on failure of drawable to generate functor calls.
          * Note, PrimtiveIndexFunctor only provide const access of the primitives, as primitives may be procedurally generated
          * so one cannot modify it.*/
        virtual void accept(PrimitiveIndexFunctor&) const {}


        /** Extensions class which encapsulates the querying of extensions and
        * associated function pointers, and provide convenience wrappers to
        * check for the extensions or use the associated functions.*/
        class OSG_EXPORT Extensions : public ::CVBF_Referenced
        {
        public:
            Extensions(unsigned int contextID);

            Extensions(const Extensions& rhs);

            void lowestCommonDenominator(const Extensions& rhs);

            void setupGLExtensions(unsigned int contextID);

            void setVertexProgramSupported(bool flag) { _isVertexProgramSupported=flag; }
            bool isVertexProgramSupported() const { return _isVertexProgramSupported; }

            void setSecondaryColorSupported(bool flag) { _isSecondaryColorSupported=flag; }
            bool isSecondaryColorSupported() const { return _isSecondaryColorSupported; }

            void setFogCoordSupported(bool flag) { _isFogCoordSupported=flag; }
            bool isFogCoordSupported() const { return _isFogCoordSupported; }

            void setMultiTexSupported(bool flag) { _isMultiTexSupported=flag; }
            bool isMultiTexSupported() const { return _isMultiTexSupported; }

            void setOcclusionQuerySupported(bool flag) { _isOcclusionQuerySupported=flag; }
            bool isOcclusionQuerySupported() const { return _isOcclusionQuerySupported; }

            void setARBOcclusionQuerySupported(bool flag) { _isARBOcclusionQuerySupported=flag; }
            bool isARBOcclusionQuerySupported() const { return _isARBOcclusionQuerySupported; }

            void setCVBF_TimerQuerySupported(bool flag) { m_bTimerQuerySupported = flag; }
            bool isTimerQuerySupported() const { return m_bTimerQuerySupported; }
            void setARBCVBF_TimerQuerySupported(bool flag) { m_bARBTimerQuerySupported = flag; }
            bool isARBTimerQuerySupported() const { return m_bARBTimerQuerySupported; }
            void glSecondaryColor3ubv(const GLubyte* coord) const;
            void glSecondaryColor3fv(const GLfloat* coord) const;

            void glFogCoordfv(const GLfloat* coord) const;

            void glMultiTexCoord1f(GLenum target,GLfloat coord) const;
            void glMultiTexCoord2fv(GLenum target,const GLfloat* coord) const;
            void glMultiTexCoord3fv(GLenum target,const GLfloat* coord) const;
            void glMultiTexCoord4fv(GLenum target,const GLfloat* coord) const;

            void glMultiTexCoord1d(GLenum target,GLdouble coord) const;
            void glMultiTexCoord2dv(GLenum target,const GLdouble* coord) const;
            void glMultiTexCoord3dv(GLenum target,const GLdouble* coord) const;
            void glMultiTexCoord4dv(GLenum target,const GLdouble* coord) const;

            void glVertexAttrib1s(unsigned int index, GLshort s) const;
            void glVertexAttrib1f(unsigned int index, GLfloat f) const;
            void glVertexAttrib1d(unsigned int index, GLdouble f) const;
            void glVertexAttrib2fv(unsigned int index, const GLfloat * v) const;
            void glVertexAttrib3fv(unsigned int index, const GLfloat * v) const;
            void glVertexAttrib4fv(unsigned int index, const GLfloat * v) const;
            void glVertexAttrib2dv(unsigned int index, const GLdouble * v) const;
            void glVertexAttrib3dv(unsigned int index, const GLdouble * v) const;
            void glVertexAttrib4dv(unsigned int index, const GLdouble * v) const;
            void glVertexAttrib4ubv(unsigned int index, const GLubyte * v) const;
            void glVertexAttrib4Nubv(unsigned int index, const GLubyte * v) const;


            void glGenBuffers (GLsizei n, GLuint *buffers) const;
            void glBindBuffer (GLenum target, GLuint buffer) const;
            void glBufferData (GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage) const;
            void glBufferSubData (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data) const;
            void glDeleteBuffers (GLsizei n, const GLuint *buffers) const;
            GLboolean glIsBuffer (GLuint buffer) const;
            void glGetBufferSubData (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data) const;
            GLvoid* glMapBuffer (GLenum target, GLenum access) const;
            GLboolean glUnmapBuffer (GLenum target) const;
            void glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params) const;
            void glGetBufferPointerv (GLenum target, GLenum pname, GLvoid* *params) const;


            void glGenOcclusionQueries( GLsizei n, GLuint *ids ) const;
            void glDeleteOcclusionQueries( GLsizei n, const GLuint *ids ) const;
            GLboolean glIsOcclusionQuery( GLuint id ) const;
            void glBeginOcclusionQuery( GLuint id ) const;
            void glEndOcclusionQuery() const;
            void glGetOcclusionQueryiv( GLuint id, GLenum pname, GLint *params ) const;
            void glGetOcclusionQueryuiv( GLuint id, GLenum pname, GLuint *params ) const;

            void glGetQueryiv(GLenum target, GLenum pname, GLint *params) const;
            void glGenQueries(GLsizei n, GLuint *ids) const;
            void glBeginQuery(GLenum target, GLuint id) const;
            void glEndQuery(GLenum target) const;
            void glQueryCounter(GLuint id, GLenum target) const;
            GLboolean glIsQuery(GLuint id) const;
            void glDeleteQueries(GLsizei n, const GLuint *ids) const;
            void glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params) const;
            void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params) const;
            void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64EXT *params) const;
            void glGetInteger64v(GLenum pname, GLint64EXT *params) const;

        protected:

            friend class ArrayDispatchers;

            typedef void (GL_APIENTRY * FogCoordProc) (const GLfloat* coord);

            typedef void (GL_APIENTRY * VertexAttrib1sProc) (GLuint index, GLshort s);
            typedef void (GL_APIENTRY * VertexAttrib1fProc) (GLuint index, GLfloat f);
            typedef void (GL_APIENTRY * VertexAttrib1dProc) (GLuint index, GLdouble f);
            typedef void (GL_APIENTRY * VertexAttribfvProc) (GLuint index, const GLfloat * v);
            typedef void (GL_APIENTRY * VertexAttribdvProc) (GLuint index, const GLdouble * v);
            typedef void (GL_APIENTRY * VertexAttribubvProc) (GLuint index, const GLubyte * v);

            typedef void (GL_APIENTRY * SecondaryColor3ubvProc) (const GLubyte* coord);
            typedef void (GL_APIENTRY * SecondaryColor3fvProc) (const GLfloat* coord);

            typedef void (GL_APIENTRY * MultiTexCoord1fProc) (GLenum target,GLfloat coord);
            typedef void (GL_APIENTRY * MultiTexCoordfvProc) (GLenum target,const GLfloat* coord);
            typedef void (GL_APIENTRY * MultiTexCoord1dProc) (GLenum target,GLdouble coord);
            typedef void (GL_APIENTRY * MultiTexCoorddvProc) (GLenum target,const GLdouble* coord);


            typedef void (GL_APIENTRY * GenBuffersProc) (GLsizei n, GLuint *buffers);
            typedef void (GL_APIENTRY * BindBufferProc) (GLenum target, GLuint buffer);
            typedef void (GL_APIENTRY * BufferDataProc) (GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage);
            typedef void (GL_APIENTRY * BufferSubDataProc) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data);
            typedef void (GL_APIENTRY * DeleteBuffersProc) (GLsizei n, const GLuint *buffers);
            typedef GLboolean (GL_APIENTRY * IsBufferProc) (GLuint buffer);
            typedef void (GL_APIENTRY * GetBufferSubDataProc) (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data);
            typedef GLvoid* (GL_APIENTRY * MapBufferProc) (GLenum target, GLenum access);
            typedef GLboolean (GL_APIENTRY * UnmapBufferProc) (GLenum target);
            typedef void (GL_APIENTRY * GetBufferParameterivProc) (GLenum target, GLenum pname, GLint *params);
            typedef void (GL_APIENTRY * GetBufferPointervProc) (GLenum target, GLenum pname, GLvoid* *params);

            typedef void (GL_APIENTRY * GenOcclusionQueriesProc) ( GLsizei n, GLuint *ids );
            typedef void (GL_APIENTRY * DeleteOcclusionQueriesProc) ( GLsizei n, const GLuint *ids );
            typedef GLboolean (GL_APIENTRY * IsOcclusionQueryProc) ( GLuint id );
            typedef void (GL_APIENTRY * BeginOcclusionQueryProc) ( GLuint id );
            typedef void (GL_APIENTRY * EndOcclusionQueryProc) ();
            typedef void (GL_APIENTRY * GetOcclusionQueryivProc) ( GLuint id, GLenum pname, GLint *params );
            typedef void (GL_APIENTRY * GetOcclusionQueryuivProc) ( GLuint id, GLenum pname, GLuint *params );
            typedef void (GL_APIENTRY * GetOcclusionQueryui64vProc) ( GLuint id, GLenum pname, GLuint64EXT *params );

            typedef void (GL_APIENTRY *GenQueriesProc) (GLsizei n, GLuint *ids);
            typedef void (GL_APIENTRY *DeleteQueriesProc) (GLsizei n, const GLuint *ids);
            typedef GLboolean (GL_APIENTRY *IsQueryProc) (GLuint id);
            typedef void (GL_APIENTRY *BeginQueryProc) (GLenum target, GLuint id);
            typedef void (GL_APIENTRY *EndQueryProc) (GLenum target);
            typedef void (GL_APIENTRY *QueryCounterProc)(GLuint id, GLenum target);
            typedef void (GL_APIENTRY *GetQueryivProc) (GLenum target, GLenum pname, GLint *params);
            typedef void (GL_APIENTRY *GetQueryObjectivProc) (GLuint id, GLenum pname, GLint *params);
            typedef void (GL_APIENTRY *GetQueryObjectuivProc) (GLuint id, GLenum pname, GLuint *params);
            typedef void (GL_APIENTRY *GetQueryObjectui64vProc) (GLuint id, GLenum pname, GLuint64EXT *params);
            typedef void (GL_APIENTRY *GetInteger64vProc) (GLenum pname, GLint64EXT *params);

            ~Extensions() {}// IE���ܴ���

            bool _isVertexProgramSupported;
            bool _isSecondaryColorSupported;
            bool _isFogCoordSupported;
            bool _isMultiTexSupported;
            bool _isOcclusionQuerySupported;
            bool _isARBOcclusionQuerySupported;
            bool m_bTimerQuerySupported;
            bool m_bARBTimerQuerySupported;

            FogCoordProc _glFogCoordfv;

            SecondaryColor3ubvProc _glSecondaryColor3ubv;
            SecondaryColor3fvProc _glSecondaryColor3fv;

            VertexAttrib1sProc _glVertexAttrib1s;
            VertexAttrib1fProc _glVertexAttrib1f;
            VertexAttrib1dProc _glVertexAttrib1d;
            VertexAttribfvProc _glVertexAttrib1fv;
            VertexAttribfvProc _glVertexAttrib2fv;
            VertexAttribfvProc _glVertexAttrib3fv;
            VertexAttribfvProc _glVertexAttrib4fv;
            VertexAttribdvProc _glVertexAttrib2dv;
            VertexAttribdvProc _glVertexAttrib3dv;
            VertexAttribdvProc _glVertexAttrib4dv;
            VertexAttribubvProc _glVertexAttrib4ubv;
            VertexAttribubvProc _glVertexAttrib4Nubv;

            MultiTexCoord1fProc _glMultiTexCoord1f;
            MultiTexCoordfvProc _glMultiTexCoord1fv;
            MultiTexCoordfvProc _glMultiTexCoord2fv;
            MultiTexCoordfvProc _glMultiTexCoord3fv;
            MultiTexCoordfvProc _glMultiTexCoord4fv;
            MultiTexCoord1dProc _glMultiTexCoord1d;
            MultiTexCoorddvProc _glMultiTexCoord2dv;
            MultiTexCoorddvProc _glMultiTexCoord3dv;
            MultiTexCoorddvProc _glMultiTexCoord4dv;

            GenBuffersProc          _glGenBuffers;
            BindBufferProc          _glBindBuffer;
            BufferDataProc          _glBufferData;
            BufferSubDataProc       _glBufferSubData;
            DeleteBuffersProc       _glDeleteBuffers;
            IsBufferProc            _glIsBuffer;
            GetBufferSubDataProc    _glGetBufferSubData;
            MapBufferProc           _glMapBuffer;
            UnmapBufferProc         _glUnmapBuffer;
            GetBufferParameterivProc _glGetBufferParameteriv;
            GetBufferPointervProc   _glGetBufferPointerv;

            GenOcclusionQueriesProc _glGenOcclusionQueries;
            DeleteOcclusionQueriesProc _glDeleteOcclusionQueries;
            IsOcclusionQueryProc _glIsOcclusionQuery;
            BeginOcclusionQueryProc _glBeginOcclusionQuery;
            EndOcclusionQueryProc _glEndOcclusionQuery;
            GetOcclusionQueryivProc _glGetOcclusionQueryiv;
            GetOcclusionQueryuivProc _glGetOcclusionQueryuiv;

            GenQueriesProc _gl_gen_queries_arb;
            DeleteQueriesProc _gl_delete_queries_arb;
            IsQueryProc _gl_is_query_arb;
            BeginQueryProc _gl_begin_query_arb;
            EndQueryProc _gl_end_query_arb;
            QueryCounterProc _glQueryCounter;
            GetQueryivProc _gl_get_queryiv_arb;
            GetQueryObjectivProc _gl_get_query_objectiv_arb;
            GetQueryObjectuivProc  _gl_get_query_objectuiv_arb;
            GetQueryObjectui64vProc  _gl_get_query_objectui64v;
            GetInteger64vProc _glGetInteger64v;

        };

        /** Function to call to get the extension of a specified context.
        * If the Extension object for that context has not yet been created  
        * and the 'createIfNotInitalized' flag been set to false then returns NULL.
        * If 'createIfNotInitalized' is true then the Extensions object is 
        * automatically created.  However, in this case the extension object is
        * only created with the graphics context associated with ContextID..*/
        static Extensions* getExtensions(unsigned int contextID,bool createIfNotInitalized);

        /** setExtensions allows users to override the extensions across graphics contexts.
        * typically used when you have different extensions supported across graphics pipes
        * but need to ensure that they all use the same low common denominator extensions.*/
        static void setExtensions(unsigned int contextID,Extensions* extensions);


       void addParent(osg::IVBF_SGNode* node);
        void removeParent(osg::IVBF_SGNode* node);    

protected:

        Drawable& operator = (const Drawable&) { return *this;}

        virtual ~Drawable();


        /** set the bounding box .*/
        void setBound(const BoundingBox& bb) const;

 

        ParentList _parents;
        friend class IVBF_SGNode;
        friend class StateSet;

        ref_ptr<StateSet>       _stateset;

        BoundingBox                         _initialBound;
        ref_ptr<ComputeBoundingBoxCallback> _computeBoundCallback;
        mutable BoundingBox                 _boundingBox;
        mutable bool                        _boundingBoxComputed;

        ref_ptr<Shape>          _shape;

        bool                    _supportsDisplayList;
        bool                    _useDisplayList;
        bool                    _supportsVertexBufferObjects;
        bool                    _useVertexBufferObjects;

        typedef osg::buffered_value<GLuint> GLObjectList;
        mutable GLObjectList    _globjList;

        ref_ptr<UpdateCallback> _updateCallback;
        unsigned int _numChildrenRequiringUpdateTraversal;
        void setNumChildrenRequiringUpdateTraversal(unsigned int num);
        unsigned int getNumChildrenRequiringUpdateTraversal() const { return _numChildrenRequiringUpdateTraversal; }

        ref_ptr<EventCallback>  _eventCallback;
        unsigned int _numChildrenRequiringEventTraversal;
        void setNumChildrenRequiringEventTraversal(unsigned int num);
        unsigned int getNumChildrenRequiringEventTraversal() const { return _numChildrenRequiringEventTraversal; }

        ref_ptr<CullCallback>   _cullCallback;
        ref_ptr<DrawCallback>   _drawCallback;

		//xahg h00017
		//bool _enableReflection;
};

inline void Drawable::draw(RenderInfo& renderInfo) const
{
#ifdef OSG_GL_DISPLAYLISTS_AVAILABLE
    if (_useDisplayList && !(_supportsVertexBufferObjects && _useVertexBufferObjects && renderInfo.getState()->isVertexBufferObjectSupported()))
    {
        // get the contextID (user defined ID of 0 upwards) for the
        // current OpenGL context.
        unsigned int contextID = renderInfo.getContextID();

        // get the globj for the current contextID.
        GLuint& globj = _globjList[contextID];

        // call the globj if already set otherwise compile and execute.
        if( globj != 0 )
        {
            glCallList( globj );
        }
        else if (_useDisplayList)
        {
#ifdef USE_SEPARATE_COMPILE_AND_EXECUTE
            globj = generateDisplayList(contextID, getGLObjectSizeHint());
//			OSG_NOTICE<<"������ʾ�б�"<<globj<<std::endl;
            glNewList( globj, GL_COMPILE );
            if (_drawCallback.valid())
                _drawCallback->drawImplementation(renderInfo,this);
            else
                drawImplementation(renderInfo);
            glEndList();

            glCallList( globj);
#else
            globj = generateDisplayList(contextID, getGLObjectSizeHint());
//			OSG_NOTICE<<"������ʾ�б�"<<globj<<std::endl;
            glNewList( globj, GL_COMPILE_AND_EXECUTE );
            if (_drawCallback.valid())
                _drawCallback->drawImplementation(renderInfo,this);
            else
                drawImplementation(renderInfo);
            glEndList();
#endif
        }

        return;

    }
#endif

    // draw object as nature intended..
    if (_drawCallback.valid())
        _drawCallback->drawImplementation(renderInfo,this);
    else
        drawImplementation(renderInfo);
}


}

#endif