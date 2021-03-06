#pragma once

const size_t FL_FIELD_SIZE = 10;
const size_t FL_MAX_SHIP_LEN = 4;

enum CellValue {
    CELL_WATER,
    CELL_WHOLE_SHIP,
    CELL_WOUNDED_SHIP,
    CELL_NOT_KNOWN
};

struct Cell {
    int x;
    int y;

    Cell(int x = 0, int y = 0)
        : x(x)
        , y(y)
    { }
};

struct Field{
    CellValue f[FL_FIELD_SIZE][FL_FIELD_SIZE];

    Field() = delete;
    Field(CellValue baseCell);
    
    int getLivesOfShipOn(const Cell &) const;

    /*
    Add ship to field.
    x0 - first cell of ship by X axis.
    y0 - first cell of ship by Y axis.
    x1 - last cell of ship by X axis.
    y1 - last cell of ship by Y axis.
    */
    bool addShip(Cell fcell, Cell lcell);

    /*
    Return ships count
    */
    int getShipsCount(void) const;

    /* 
    Dec lives of ship on (x, y).
    */
    void decLives(const Cell &);

    void getFirstShipCell(Cell &) const;
    void getLastShipCell(Cell &) const;

private:
    int lives;
    int shipsCount;
    bool gameProcess;
};
