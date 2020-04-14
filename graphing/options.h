#ifndef OPTIONS_H
#define OPTIONS_H

#define Node_Radius         8
#define Selector_Radius     32
#define ws_Height           512
#define ws_Width            512

// animation
#define delayCD             150
#define changeTime          250

#define block_Size           4
#define block_RangeX         (ws_Height/block_Size)             // поменять потом на глобальные переменные,
#define block_RangeY         (ws_Width/block_Size)              // для возможности редактировать размеры холста

#endif // OPTIONS_H
