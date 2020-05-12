#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();
        int x, y;
        int nivel;

        void mover();

    protected:
        int track;

    private:
};

#endif // ENEMY_H
