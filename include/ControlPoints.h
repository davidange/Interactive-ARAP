
#include <igl/unproject_onto_mesh.h>
#include <igl/opengl/glfw/Viewer.h>
#include <igl/project.h>
#include <vector>
#include "Polygon.h"

class ControlPoints
{
  public:
    bool add(igl::opengl::glfw::Viewer& viewer, Eigen::MatrixXd V, Eigen::MatrixXi F);
    bool remove(igl::opengl::glfw::Viewer& viewer, Eigen::MatrixXd V, Eigen::MatrixXi F);
    std::tuple<Eigen::MatrixXd, std::vector<std::vector<unsigned int>>> removeAllPoints();
    void setInitialPoints(Eigen::MatrixXd initialPoints, std::vector<std::vector<unsigned int>> initialGroups);
    bool add(igl::opengl::glfw::Viewer& viewer, Eigen::MatrixXd V,  GUI::Polygon& controlArea);

    long addSelectedPoint(igl::opengl::glfw::Viewer& viewer, Eigen::Vector3f mouseLocation);
    bool addSelectedPoints(igl::opengl::glfw::Viewer& viewer, Eigen::MatrixXd V,  GUI::Polygon& controlArea);
    void clearSelectedPoints();
    bool removeSelectedPoint(igl::opengl::glfw::Viewer& viewer, Eigen::Vector3f mouseLocation);
  
    Eigen::MatrixXd getPoints();
    Eigen::MatrixXd getSelectedPoints();
    Eigen::VectorXi getPointsVertex();
    Eigen::SparseMatrix<double> getPointsAsMatrix(int numRows);
    inline Eigen::RowVector3d getPoint(int index) { return m_points[index]; }
    inline void updatePoint(int index, Eigen::RowVector3d translataion) { m_points[index] =  m_points[index] + translataion; }
    void updatePoints( Eigen::RowVector3d transltation);
  private:
    //Values of all control Points
    std::vector<Eigen::RowVector3d> m_points;
    //indices of vertices of all control points
    std::vector<unsigned int> m_pointsVertexIndex;
    //indices of all selected control points (NOTE: indices of m_points vector)
    std::vector<unsigned int> m_selectedPointsIndex;
    // Constraint groups with all corresponding vertex indices
    std::vector<std::vector<unsigned int>> m_constraintGroups;
};
