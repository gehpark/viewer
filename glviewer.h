#ifndef _GLWIDGET_
#define _GLWIDGET_

// Qt
#include <QGLWidget>
#include <QPaintEvent>


class GlViewer : public QGLWidget
{
    Q_OBJECT
    
private:
    struct coordinates {
        double x,y,r,n,x_old, y_old;
        coordinates() : x(), y(), r(), n(), x_old(), y_old() {}
        coordinates(double xx, double yy, double rr, double nn) : x(xx), y(yy), r(rr), n(nn) {}
    };
    
    std::vector<coordinates> m_particles;
    std::vector<coordinates> m_old_particles;
    std::vector<coordinates> m_obstacles;
    std::vector<double> m_o_positions;
    std::vector<int> m_bins;
    bool m_view_circles;
    double SINE_INCREMENT;

    // camera
    double m_scale;
    double m_center_x;
    double m_center_y;
    
    // mouse
    QPoint m_mouse_click;
    QPoint m_mouse_move;    
    QPoint m_mouse_pick;

    double OBSTACLE_RADIUS;
    

    
public:
    GlViewer(QWidget *parent);
    
    void set_camera(const double x, const double y, const double s)
    {
        m_center_x = x;
        m_center_y = y;
        m_scale = s;
    }
    
    void random_walk_particles(QString mode, double WIND_DIST_X, double WIND_DIST_Y);
    void oscillate_obstacles(QString oscillation_mode, int per_row, double amplitude);
    void generate_particles(int np);
    void generate_obstacles(int nob, QString obstacle_mode, double row_dist, int per_row);
    void draw_particles() const;
    void draw_obstacles() const;
    void draw_one_particle(const double cx,
                         const double cy,
                         const double radius,
                         const std::vector<double>& points) const;
    void draw_one_obstacle(const double cx,
                         const double cy,
                         const double radius,
                         const std::vector<double>& points) const;
    void generate_polygon(unsigned np,
                          std::vector<double>& points) const;

    void toggle_circles() { m_view_circles = !m_view_circles; }
    void touch(QString interaction, double OBSTACLE_RADIUS);
    QString output_position(double BIN_COUNT);
    QString output_position_heat(double BIN_COUNT);
    void setObstacleRadius(double OBSTACLE_RADIUS_input);
    QString radius_data(double BIN_COUNT);
    bool run_complete();
    
protected:
    // GL
    void paintGL();
    void initializeGL();
    void resizeGL(int width, int height);
    
    // mouse
    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
   // void keyPressEvent(QKeyEvent *event);
    void move_camera(const QPoint& p0, const QPoint& p1);
};

#endif
