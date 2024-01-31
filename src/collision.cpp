#include <math.h>

using namespace std;

#include "collision.h"
#include "point.h"
#include "Sphere.h"
#include "plane.h"


collision::collision()
{

}

bool collision:: collideSpheres(Sphere sp1, Sphere sp2)
{
    point p1 = sp1.getCenter();
    point p2 = sp2.getCenter();

    float dist = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z,2));

    if(dist <= sp1.getRadius() + sp2.getRadius())
         return true;
    else
        return false;
}

/*bool collision:: collideSpherePlane(Sphere sp, plane pln)
{

}
*/
collision::~collision()
{
    //dtor
}
