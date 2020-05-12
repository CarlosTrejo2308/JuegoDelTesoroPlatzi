#ifndef MAPCELL_H
#define MAPCELL_H


class MapCell
{
    public:
        MapCell();
        virtual ~MapCell();

        char id;

        bool isBlocked();

    protected:

    private:
};

#endif // MAPCELL_H
