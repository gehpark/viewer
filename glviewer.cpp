//========== HEADER FILES ========== //

// Qt
#include <QtGui>

// stl
#include <iostream>

// local
#include "glviewer.h"
#include "random.h"

// Random Walk Parameters
#include "randomWalk.h"
#include <QDebug>

//========== FUNCTIONS ========== //

GlViewer::GlViewer(QWidget *pParent)
: QGLWidget(QGLFormat(QGL::SampleBuffers), pParent)
{
    m_scale = 1.0;
    m_center_x = 0.;
    m_center_y = 0.;
    m_view_circles = true;
    setAutoFillBackground(false);
}


//**** INITIALIZE ****************************************************************************************//
//**** INITIALIZE ****************************************************************************************// 

void GlViewer::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    double aspect_ratio = double(height) / double(width);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -aspect_ratio, aspect_ratio, -1.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GlViewer::initializeGL() 
{
    glClearColor(1., 1., 1., 0.);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void GlViewer::paintGL() 
{

    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    glLoadIdentity();
    glScaled(m_scale, m_scale, m_scale);
    glTranslated(-m_center_x, -m_center_y, 0.0);
    if (m_view_circles) draw_particles();
    //draw_frozen();
    draw_obstacles();
    glPopMatrix();
}

void GlViewer::wheelEvent(QWheelEvent *event) 
{
    m_scale += 0.05 * (event->delta() / 120);
    if (m_scale <= 0.0) m_scale = 0.0;
    updateGL();
}

void GlViewer::mousePressEvent(QMouseEvent *event) 
{
    m_mouse_click = event->pos();
    if (event->button() == Qt::RightButton) 
        setCursor(QCursor(Qt::ClosedHandCursor));
}

void GlViewer::mouseMoveEvent(QMouseEvent *event)
{
    m_mouse_move = event->pos();
    if (event->buttons() == Qt::RightButton)
        move_camera(m_mouse_click, m_mouse_move);
    m_mouse_click = m_mouse_move;
    updateGL();
}

void GlViewer::mouseReleaseEvent(QMouseEvent *event) 
{
    m_mouse_move = event->pos();
    if (event->button() == Qt::RightButton) 
        move_camera(m_mouse_click, m_mouse_move);
    m_mouse_click = m_mouse_move;
    setCursor(QCursor(Qt::ArrowCursor));
    updateGL();
}

void GlViewer::move_camera(const QPoint& p0, const QPoint& p1)
{
    m_center_x -= double(p1.x() - p0.x()) / double(width());
    m_center_y += double(p1.y() - p0.y()) / double(height()); 
}


//********************************************************************************************************//
//******* DRAW *******************************************************************************************// 
//********************************************************************************************************//

void GlViewer::draw_particles() const
{
    std::vector<double> circle;
    generate_polygon(20, circle);
    
    for (unsigned i = 0; i < m_particles.size(); i++)
    {
        double x = m_particles[i].x;
        double y = m_particles[i].y;
        draw_one_particle(x, y, PARTICLE_RADIUS, circle);
    }
    /**for (std::vector<coordinates>::iterator it = m_particles.begin(); it!=m_particles.end(); it++)
    {
        double x = (*it).x;
        double y = (*it).y;
        draw_one_particle(x, y, PARTICLE_RADIUS, circle);
    }**/
}

void GlViewer::draw_obstacles() const
{
    std::vector<double> obstacle;
    generate_polygon(20, obstacle);

    for (unsigned i=0; i<m_obstacles.size(); i++)
    {
            double x = m_obstacles[i].x;
            double y = m_obstacles[i].y;
            double r = m_obstacles[i].r;
            draw_one_obstacle(x, y, r, obstacle);
    }
    /**for (std::vector<coordinates>::iterator oit = m_obstacles.begin(); oit!=m_obstacles.end(); oit++)
    {
        double x = (*oit).x;
        double y = (*oit).y;
        double r = (*oit).r;
        draw_one_obstacle(x, y, r, obstacle);
    }**/
}

void GlViewer::draw_one_particle(const double cx,
                               const double cy,
                               const double radius,
                               const std::vector<double>& points) const
{
    glPushMatrix();
    glColor4f(1.0,0.0,0.0,0.2);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glTranslated(cx, cy, 0.0);
    glScaled(radius, radius, radius);
    
    glBegin(GL_POLYGON);
    for (unsigned j = 0; j < points.size()/2; j++)
    {
        glVertex2d(points[2*j], points[2*j+1]);
    }
    glEnd();
    
    glPopMatrix();
}

/**void GlViewer::draw_one_frozen(const double cx,
                               const double cy,
                               const double radius,
                               const std::vector<double>& points) const
{
    glPushMatrix();
    glColor4f(0.1,0.8,0.5,0.2);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glTranslated(cx, cy, 0.0);
    glScaled(radius, radius, radius);
    
    glBegin(GL_POLYGON);
    for (unsigned j = 0; j < points.size()/2; j++)
    {
        glVertex2d(points[2*j], points[2*j+1]);
    }
    glEnd();
    
    glPopMatrix();
}**/

void GlViewer::draw_one_obstacle(const double cx,
                               const double cy,
                               const double radius,
                               const std::vector<double>& points) const
{
    glPushMatrix();
    glColor4f(0.0,0.7,0.3,0.8);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glTranslated(cx, cy, 0.0);
    glScaled(radius, radius, radius);
    
    glBegin(GL_POLYGON);
    for (unsigned j = 0; j < points.size()/2; j++)
    {
        glVertex2d(points[2*j], points[2*j+1]);
    }
    glEnd();
    
    glPopMatrix();
}

void GlViewer::generate_polygon(unsigned np,
                                std::vector<double>& points) const
{
    if (np < 3) np = 3;
    double start = 0.25 * M_PI;
    double step = 2.0 * M_PI / np;
    for (unsigned i = 0; i < np; i++)
    {
        double angle = start + i * step;
        points.push_back(cos(angle));
        points.push_back(sin(angle));
    }
}

//********************************************************************************************************//
//***** GENERATE *****************************************************************************************// 
//********************************************************************************************************//

void GlViewer::setObstacleRadius(double OBSTACLE_RADIUS_input)
{
    OBSTACLE_RADIUS = OBSTACLE_RADIUS_input;
}


void GlViewer::generate_particles(int np)
{
    m_particles.clear();
    for (int i = 0; i < np; i++)
    {
        m_particles.push_back(coordinates());
        m_particles[i].x = 0;
        m_particles[i].y = 0;
        m_particles[i].r = PARTICLE_RADIUS;
    }
}

void GlViewer::generate_obstacles(int nob, QString obstacle_mode, double row_dist, int per_row)
{
    m_o_positions.clear();
    if (obstacle_mode.contains("Random"))
        m_obstacles.clear();
        for (int i = 0; i < nob; i++)
        {
            m_obstacles.push_back(coordinates());
            m_obstacles[i].x = random_double(-1,1);
            double y_coord = random_double(-1,1);
            m_obstacles[i].y = y_coord;
            m_obstacles[i].r = OBSTACLE_RADIUS;
            m_obstacles[i].n = y_coord;
        }

    if (obstacle_mode.contains("Grid"))
    {
        m_obstacles.clear();
        int row_count = nob/per_row;
        for (int i = 0; i < per_row; i++)
        {
                for (int j = 0; j < row_count; j++)
                {
                    m_obstacles.push_back(coordinates((-((double)per_row - 1)/2 + i) * row_dist, 
                                        (((double)row_count - 1)/2 - j) * row_dist, 
                                        OBSTACLE_RADIUS, 
                                        (((double)row_count - 1)/2 - j) * row_dist));
                }
        }
    }
        
    if (obstacle_mode.contains("Circle"))
    {
        m_obstacles.clear();
        double OBS_ANGLE = 2 * M_PI / nob;
        for (int i = 0; i < nob; i++)
        {

            m_obstacles.push_back(coordinates());
            m_obstacles[i].x = row_dist * cos(OBS_ANGLE * i);
            m_obstacles[i].y = row_dist * sin(OBS_ANGLE * i);  
            m_obstacles[i].r = OBSTACLE_RADIUS;
            m_obstacles[i].n = row_dist * sin(OBS_ANGLE * i);
        }
    }

    for (unsigned i = 0; i < m_obstacles.size(); i++)
    {
        m_o_positions.push_back(m_obstacles[i].y);
    }

    // delete duplicates in the m_o_positions vector
    sort(m_o_positions.begin(), m_o_positions.end());
    m_o_positions.erase(unique( m_o_positions.begin(), m_o_positions.end() ), m_o_positions.end());
}


//********************************************************************************************************//
//***** ACTION   *****************************************************************************************// 
//********************************************************************************************************//


// This function moves the particles in a random pattern
void GlViewer::random_walk_particles(QString mode, double WIND_DIST_X, double WIND_DIST_Y)
{
    m_old_particles.clear();
    // user input will be either Discrete or Continuous
    if (mode.contains("Discrete"))
    {
        // Iterates through all of the points that define the circles
        // where even entries are the x coords and odd are y coords
        for (std::vector<coordinates>::iterator it = m_particles.begin(); it!=m_particles.end(); it++)
        {
        // Generate the delta X and Y we want to introduce based
        // on constant set in randomWalk.h
        double x_delta = random_double(-WALK_DIST,WALK_DIST);
        double y_delta = random_double(-WALK_DIST,WALK_DIST);
        (*it).x_old = (*it).x;
        (*it).y_old = (*it).y;        
        // Add the deltas and wind movements to the old position for the new position
        (*it).x += (x_delta + WIND_DIST_X);
        // if the particles go beyond the 1x1 square
        // make them pop out from the other side
        if (abs((*it).x) >= 1)
        {
            (*it).x *= (-1);
        }

        (*it).y += (y_delta + WIND_DIST_Y);

        if (abs((*it).y) >= 1)
        {
            (*it).y *= (-1);
        }       
        }

    }

    else
    {
        for (std::vector<coordinates>::iterator it = m_particles.begin(); it!=m_particles.end(); it++)
        {
        double theta = random_double(0, 2 * M_PI);
        double x_delta = WALK_DIST * cos(theta);
        double y_delta = WALK_DIST * sin(theta);

        double x_wind_delta = WIND_DIST_X * cos(WIND_ANGLE);
        double y_wind_delta = WIND_DIST_X * sin(WIND_ANGLE);
        (*it).x_old = (*it).x;
        (*it).y_old = (*it).y; 
        // Add the deltas and wind movements to the old position for the new position
        (*it).x += (x_delta + WIND_DIST_X);
        // if the particles go beyond the 1x1 square
        // make them pop out from the other side
        if (abs((*it).x) >= 1)
        {
            (*it).x *= (-1);
        }

        (*it).y += (y_delta + WIND_DIST_Y);

        if (abs((*it).y) >= 1)
        {
            (*it).y *= (-1);
        }       
        }
    }
    for (std::vector<coordinates>::iterator it = m_particles.begin(); it!=m_particles.end(); it++)
    {
        m_old_particles.push_back(coordinates((*it).x, (*it).y, (*it).r, (*it).n));
    }
}




// this function oscillates the obstacles randomly
void GlViewer::oscillate_obstacles(QString oscillation_mode, int per_row, double amplitude)
{    
    if (oscillation_mode.contains("Off"))
    {

    }

    if (oscillation_mode.contains("Random"))
    {
        // iterate over each obstacle
        // again, the odd elements are the x coordinates and 
        // the even elements are the y coordinates of the obstacles
        for (unsigned i = 0; i < m_obstacles.size(); i++)
        {
            SINE_INCREMENT += M_PI/6;
            m_obstacles[i].x += rand()%2 * sin(SINE_INCREMENT) * amplitude;
            m_obstacles[i].y += rand()%2 * sin(SINE_INCREMENT) * amplitude;
        }
    }

    if (oscillation_mode.contains("Together"))
    {
        SINE_INCREMENT += M_PI/6;
         for (std::vector<coordinates>::iterator it = m_obstacles.begin(); it!=m_obstacles.end(); it++)
        {
            (*it).x += sin(SINE_INCREMENT) * amplitude;
        }
    }

    if (oscillation_mode.contains("Alternating"))
    {
        SINE_INCREMENT += M_PI/6;
        for (unsigned i = 0; i < m_o_positions.size(); i++)
        {   
            for (std::vector<coordinates>::iterator it = m_obstacles.begin(); it!=m_obstacles.end(); it++)
            {
                if ((*it).n == m_o_positions[i])
                {
                    (*it).x += sin(SINE_INCREMENT + (M_PI * i)) * amplitude;
                }
            }
        }
    } 

    if (oscillation_mode.contains("Tiered"))
    {
        SINE_INCREMENT += M_PI/6;
        for (unsigned i = 0; i < m_o_positions.size(); i++)
        {   
            for (std::vector<coordinates>::iterator it = m_obstacles.begin(); it!=m_obstacles.end(); it++)
            {
                if ((*it).n == m_o_positions[i])
                {
                    (*it).x += sin(SINE_INCREMENT + (M_PI/6 * i)) * amplitude;
                }
            }
        }
    }


}



// this function deals with the interaction between the particles and the obstacles
void GlViewer::touch(QString interaction, double OBSTACLE_RADIUS)
{
    // the user inputs are Disappear, Stick, and reflect
    if (interaction.contains("Disappear"))
    {
        // iterate over each particle until iterator reaches the end
        // (odd elements are x coordinates and even elements are y coordinates)
        for (std::vector<coordinates>::iterator oit = m_obstacles.begin(); oit!=m_obstacles.end(); oit++)
        {
            for (std::vector<coordinates>::iterator it = m_particles.begin(); it!=m_particles.end();)
            {
                if ((OBSTACLE_RADIUS + PARTICLE_RADIUS) * (OBSTACLE_RADIUS + PARTICLE_RADIUS)
                    >= (((*it).x - (*oit).x) * ((*it).x - (*oit).x) + ((*it).y - (*oit).y) * ((*it).y - (*oit).y)))
                {
                    it = m_particles.erase(it);
                } 
                else 
                {
                    it++;
                }
            }
        }
    }

    if (interaction.contains("Stick"))
    {
        for (unsigned i = 0; i < m_obstacles.size(); i++)
        //for (std::vector<coordinates>::iterator oit = m_obstacles.begin(); oit!=m_obstacles.end(); oit++)  
        {
            for (std::vector<coordinates>::iterator it = m_particles.begin(); it!=m_particles.end();)
            {
                if ((m_obstacles[i].r + (*it).r) * (m_obstacles[i].r + (*it).r)
                        >= (((*it).x - m_obstacles[i].x) * ((*it).x - m_obstacles[i].x) + ((*it).y - m_obstacles[i].y) * ((*it).y - m_obstacles[i].y))) 
                    {
                        m_obstacles.push_back(coordinates((*it).x, (*it).y, (*it).r, m_obstacles[i].n));
                        it = m_particles.erase(it);
                    }
                    else
                    {
                        it++;
                    }
            }
        }
    }

    if (interaction.contains("Reflect"))
    {
      for (std::vector<coordinates>::iterator oit = m_obstacles.begin(); oit!=m_obstacles.end(); oit++)  
        {
            for (std::vector<coordinates>::iterator it = m_particles.begin(); it!=m_particles.end(); it++)
            {
                if ((OBSTACLE_RADIUS + PARTICLE_RADIUS) * (OBSTACLE_RADIUS + PARTICLE_RADIUS)
                    >= (((*it).x - (*oit).x) * ((*it).x - (*oit).x) + ((*it).y - (*oit).y) * ((*it).y - (*oit).y)))
                {
                //(((*it).x * (1-t) + (*it).x_old * t - (*oit).x) * ((*it).x * (1-t) + (*it).x_old * t - (*oit).x) + 
                //((*it).y * (1-t) + (*it).y_old * t - (*oit).y) * ((*it).y * (1-t) + (*it).y_old * t - (*oit).y) = OBSTACLE_RADIUS * OBSTACLE_RADIUS)
                
                /**double coeff_a = ((*it).x - (*it).x_old) * ((*it).x - (*it).x_old) + 
                                 ((*it).y - (*it).y_old) * ((*it).y - (*it).y_old);
                double coeff_b = (2 * ((*it).x_old - (*oit).x) * ((*it).x - (*it).x_old) + 
                                  2 * ((*it).y_old - (*oit).y) * ((*it).y - (*it).y_old));
                double coeff_c = ((*it).x_old - (*oit).x) * ((*it).x_old - (*oit).x) + 
                                 ((*it).y_old - (*oit).y) * ((*it).y_old - (*oit).y) - 
                                 (OBSTACLE_RADIUS) * (OBSTACLE_RADIUS);
                printf("%f, %f, %f\n", coeff_a, coeff_b, coeff_c);
                double t = (-coeff_b + sqrt((coeff_b * coeff_b) - (4 * coeff_a * coeff_c))) / (2 * coeff_a);
                double t_minus = (-coeff_b - sqrt((coeff_b * coeff_b) - (4 * coeff_a * coeff_c))) / (2 * coeff_a);
                printf("t: %f\n",t);
                printf("t_minus: %f\n",t_minus);
                if (t_minus <= 1 && t_minus >= 0)
                {
                    t = t_minus;
                    printf("changed\n");
                }
                double xt = (*it).x_old * (1-t) + (*it).x * t;
                double yt = (*it).y_old * (1-t) + (*it).y * t;
                double x_int = (*it).x_old * (2 - 2 * t) + (*it).x * (2 * t - 1);
                double y_int = (*it).y_old * (2 - 2 * t) + (*it).y * (2 * t - 1);
                double m = (y_int - (*oit).y) / (x_int - (*oit).x);
                double b = y_int - m * x_int;
                
                double d = (xt + (yt - b) * m) / (1 + m * m);
                (*it).x = 2 * d - xt;
                (*it).y = 2 * d * m - yt + 2 * b;

                // (y - y_0)x + (x - x_0)y = C is the path of the particle
                double M = ((*it).y - (*it).y_old) / ((*it).x - (*it).x_old);
                double B = (*it).y - (M * (*it).x);
                // use the quadratic formula to find the point of intersection
                double a = (1 + (M * M));
                double b = 2 * ((M * B) - (M * (*oit).y) - (*oit).x);
                double c = (((*oit).x * (*oit).x) + ((*oit).y + (*oit).y) + (B * B) - 2 * (B * (*oit).y) - (OBSTACLE_RADIUS * OBSTACLE_RADIUS));
                ;
                **/

                //y(x1 - x0) = x(y1 - y0) + B'
                

                /**double x0 = (*it).x_old;
                double x1 = (*it).x;
                double y0 = (*it).y_old;
                double y1 = (*it).y;
                double xc = (*oit).x;
                double yc = (*oit).y;

                double B = x1 * y0 - x0 * y1;
                double a = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
                double b = 2 * (y1 - y0) * (B - yc * (x1 - x0)) - 2 * xc * (x1 - x0) * (x1 - x0);
                double c = (x1 - x0) * (x1 - x0) * (xc * xc + yc * yc) + 
                            B * B - 2 * B * yc * (x1 - x0) - OBSTACLE_RADIUS * OBSTACLE_RADIUS * (x1 - x0) * (x1 - x0);
                double x_int = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
                double x_minus = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
                bool changed = false;
                if ((x_minus <= (*it).x_old && x_minus >= (*it).x) || (x_minus >= (*it).x_old && x_minus <= (*it).x))
                {
                    x_int = x_minus;
                    changed = true;
                }
                printf("B: %f, a: %f, b: %f, c:%f magicnumber:%f\n", B, a, b, c, b*b-4*a*c);
                printf("%d x_old: %f, x_int: %f, %f x: %f\n", changed, (*it).x_old, x_int, x_minus, (*it).x);

                double y_int = (B + x_int * (y1 - y0)) / (x1 - x0);

                double x_ref = x_int + (x_int - x1);
                double y_ref = y_int + (y_int - y1);
                if (x_ref != x_ref)
                {

                }
                else
                {  
                    (*it).x = x_ref;
                    (*it).y = y_ref;
                }**/

                (*it).x = (*it).x_old;
                (*it).y = (*it).y_old;
                
                /**double y_int = M * x_int + B;
                // find y = Mc * x + Bc, the normal to the circle
                double Mc = ((*oit).y - y_int) / ((*oit).x - x_int);
                double Bc = y_int - Mc * x_int;
                // find point on path of particle to reflect
                double x_ref = x_int + (x_int - (*it).x);
                double y_ref = y_int + (y_int - (*it).y);
                double Bc_ref = y_ref + (1 / Mc) * x_ref;
                // intersection of y = (Mc)x + Bc and its normal, y = (-1/Mc)X + Bc_ref
                double x_line = (Bc_ref - B) / (M + (1 / M));
                double y_line = (-1 / M) * x_line + Bc_ref;
                // find reflected point over the line for final position
                (*it).x = x_line + (x_line - x_ref);
                (*it).y = y_line + (y_line - y_ref); 
                printf("final points: %f, %f\n", (*it).x, (*it).y);**/
                


                }    
            }
        }
    }


    if (interaction.contains("Ignore"))
    {
    }
}


//*****************************************************************************************************//
//***** WRAP UP  **************************************************************************************// 
//*****************************************************************************************************//

// this function prints out the position of each particle in a matlab command format
QString GlViewer::output_position(double BIN_COUNT)
{
    QString hist1 = "hist3([";
    for (std::vector<coordinates>::iterator it = m_particles.begin(); it!=m_particles.end(); it++)
    {
        hist1.append(QString::number((*it).x));
        hist1.append(",");
        hist1.append(QString::number((*it).y));
        hist1.append(";");
    }
    hist1.append("]");
    if (BIN_COUNT != 0)
    {
        hist1.append(",[");
        hist1.append(QString::number(BIN_COUNT));
        hist1.append(",");
        hist1.append(QString::number(BIN_COUNT));
        hist1.append("]");
    }
    hist1.append(");\n");
    hist1.append("set(gcf,'renderer','opengl');\n set(get(gca,'child'),'FaceColor','interp','CDataMode','auto');\n");
    return hist1;
}

QString GlViewer::output_position_heat(double BIN_COUNT)
{
    QString heat1 = "data = [";
    for (std::vector<coordinates>::iterator it = m_particles.begin(); it!=m_particles.end(); it++)
    {
        heat1.append(QString::number((*it).x));
        heat1.append(",");
        heat1.append(QString::number((*it).y));
        heat1.append(";");
    }
    heat1.append("]");
    /**if (BIN_COUNT != 0)
    {
        heat1.append(",[");
        heat1.append(QString::number(BIN_COUNT));
        heat1.append(",");
        heat1.append(QString::number(BIN_COUNT));
        heat1.append("]");
    }**/
    heat1.append(";\n");
    return heat1;
}

// this function prints out the radial distance of each particle
// from the starting point in matlab command format
// and it also bins the data for quick use
QString GlViewer::radius_data(double BIN_COUNT)
{
    QString radius1 = ("histfit([");
    for (std::vector<coordinates>::iterator it = m_particles.begin(); it!=m_particles.end(); it++)
    {
        double RADIUS_DIST_SQ = ((*it).x * (*it).x + (*it).y * (*it).y);
        radius1.append(QString::number(sqrt(RADIUS_DIST_SQ)));
        radius1.append(",");
    }
    radius1.append("]");
    if (BIN_COUNT != 0)
    {
        radius1.append(",");
        radius1.append(QString::number(BIN_COUNT));
    }
    radius1.append(");\n");
    return radius1;
}


bool GlViewer::run_complete()
{
    if (m_particles.size() == 0)
    {
        return true;
    }
    else return false;
}