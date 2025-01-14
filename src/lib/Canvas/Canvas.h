//
// Created by lbcos on 14/01/2025.
//

#ifndef CANVAS_H
#define CANVAS_H



class Canvas {
  public:
    Canvas(int width, int height, int nRow, int nCol);
    void Draw() const;
private:
    int width, height, nRow, nCol;

};



#endif //CANVAS_H
