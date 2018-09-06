#ifndef OSG_KDTREE
#define OSG_KDTREE 1

#include <VBF_Engine/VBF_SceneGraph/VBFO_Shape.h>
#include <VBF_Engine/VBF_SceneGraph/VBFO_SGDrawableGeometry.h>

#include <map>

namespace osg
{

/** Implementation of a kdtree for Geometry leaves, to enable fast intersection tests.*/
class OSG_EXPORT KdTree : public osg::Shape 
{
    public:
        KdTree();       
        KdTree(const KdTree& rhs, const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY);

        META_Shape(osg, KdTree)
        
        struct OSG_EXPORT BuildOptions
        {
            BuildOptions();
                        
            unsigned int _numVerticesProcessed;
            unsigned int _targetNumTrianglesPerLeaf;
            unsigned int _maxNumLevels;
        };
        
        
        /** Build the kdtree from the specified source geometry object.
          * retun true on success. */ 
        virtual bool build(BuildOptions& buildOptions, osg::Geometry* geometry);
        
        struct LineSegmentIntersection
        {
            LineSegmentIntersection():
                ratio(-1.0),
                p0(0),
                p1(0),
                p2(0),
                r0(0.0f),
                r1(0.0f),
                r2(0.0f),
                primitiveIndex(0) {}

            bool operator < (const LineSegmentIntersection& rhs) const { return ratio < rhs.ratio; }

            typedef std::vector<unsigned int>   IndexList;
            typedef std::vector<double>         RatioList;

            double                          ratio;
            osg::Vec3d                      intersectionPoint;
            osg::Vec3                       intersectionNormal;

            unsigned int                    p0;
            unsigned int                    p1;
            unsigned int                    p2;
            float                           r0;
            float                           r1;
            float                           r2;

            unsigned int                    primitiveIndex;
        };        
        

        typedef std::vector<LineSegmentIntersection> LineSegmentIntersections;
        
        /** compute the intersection of a line segment and the kdtree, return true if an intersection has been found.*/
        virtual bool intersect(const osg::Vec3d& start, const osg::Vec3d& end, LineSegmentIntersections& intersections) const;


        typedef int value_type;

        struct KdNode
        {
            KdNode():
                first(0),
                second(0) {}

            KdNode(value_type f, value_type s):
                first(f),
                second(s) {}

            osg::BoundingBox bb;

            value_type first;    
            value_type second;
        };
    
        struct Triangle
        {
            Triangle():
                p0(0),p1(0),p2(0) {}
        
            Triangle(unsigned int ip0, unsigned int ip1, unsigned int ip2):
                p0(ip0), p1(ip1), p2(ip2) {}

            bool operator < (const Triangle& rhs) const
            {
                if (p0<rhs.p0) return true;
                if (p0>rhs.p0) return false;
                if (p1<rhs.p1) return true;
                if (p1>rhs.p1) return false;
                return p2<rhs.p2;
            }

            unsigned int p0;
            unsigned int p1;
            unsigned int p2;
        };

        typedef std::vector< KdNode >       KdNodeList;
        typedef std::vector< Triangle >     TriangleList;

        int addNode(const KdNode& node)
        {
            int num = static_cast<int>(_kdNodes.size()); 
            _kdNodes.push_back(node); 
            return num;
        }

        KdNode& getNode(int nodeNum) { return _kdNodes[nodeNum]; }
        const KdNode& getNode(int nodeNum) const { return _kdNodes[nodeNum]; }
        
        KdNodeList& getNodes() { return _kdNodes; }
        const KdNodeList& getNodes() const { return _kdNodes; }

        void setVertices(osg::Vec3Array* vertices) { _vertices = vertices; }
        const osg::Vec3Array* getVertices() const { return _vertices.get(); }

        unsigned int addTriangle(const Triangle& tri)
        {
            unsigned int num = static_cast<unsigned int>(_triangles.size());
            _triangles.push_back(tri);
            return num;
        }

        Triangle& getTriangle(unsigned int i) { return _triangles[i]; }
        const Triangle& getTriangle(unsigned int i) const { return _triangles[i]; }

        TriangleList& getTriangles() { return _triangles; }
        const TriangleList& getTriangles() const { return _triangles; }


    protected:

        ref_ptr<osg::Vec3Array>        _vertices;
        KdNodeList                          _kdNodes;
        TriangleList                        _triangles;

};

class OSG_EXPORT KdTreeBuilder : public osg::NodeVisitor
{
    public:
    
        KdTreeBuilder();
    
        KdTreeBuilder(const KdTreeBuilder& rhs);

        META_NodeVisitor("osg","KdTreeBuilder")

        virtual KdTreeBuilder* clone() { return new KdTreeBuilder(*this); }

        void apply(osg::IVBF_SGNodeGeometry& geode);
    
        KdTree::BuildOptions _buildOptions;

        ref_ptr<osg::KdTree> _kdTreePrototype;             
    protected:
    
        virtual ~KdTreeBuilder() {}// IE���ܴ���
        
};

}

#endif