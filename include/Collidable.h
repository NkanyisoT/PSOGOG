#ifndef COLLIDABLE_H
#define COLLIDABLE_H


class Collidable
{
    public:
        Collidable();
        virtual bool getState();
        void setState(bool state);
        virtual ~Collidable();

    protected:
            bool exist;
    private:
};

#endif // COLLIDABLE_H
