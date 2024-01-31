
class Movement {

 public :
     Movement();
     void init();
     void camera();
     void mousePressed(int button, int state, int x, int y);
     void mouseMove(int x, int y);
     float radius();
     void processNormalKey( unsigned char key, int x, int y);
     void processSpecialKey( int key, int x, int y );

 private :

     float eyeX ,
           eyeY,
           eyeZ ;

     float lookAtX,
           lookAtY,
           lookAtZ ;

     float scaleFactor ;
     float rotateFactor;

     float deltaAngle;
     float xOrigin;
     float ourAngle = 0.0;
     float speed;
} ;
