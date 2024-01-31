#ifndef FACE_H
#define FACE_H


class face
{
    public:
        face(int a, int b, int c, int d, int e);
        face(int a, int b, int c, int d);
        face(int a, int b, int c, int d, int e, int f);

        virtual ~face();
        int a,b,c,d,e,f;
        bool four = true;
    protected:

    private:
};

#endif // FACE_H
