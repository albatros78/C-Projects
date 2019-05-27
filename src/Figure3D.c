//
// Created by Mariia on 30.04.2019.
//

#include "../headers/Figure3D.h"

Figure3D *make_Figure(Edge3DArray *edges, Point3DArray *points) {
    /** Returns a pointer to Figure3D with given arrays of edges and points.
     *
     * Preferably use this function instead of malloc or calloc, in order to get get right initialization of fields.
     */
    Figure3D* newFigure = malloc(sizeof(Figure3D));
    newFigure->edges = edges;
    newFigure->points = points;
    return newFigure;
}

ChType *_repr_Figure(Figure3D *thisFigure) {
    /** Return char* representation of thisFigure.
     *
     * Use printf("%s",reprFigure(someFigure)) to print representation.
     *
     * Example
     *  Figure:[
     *  Edges:(Edge 3D:{
     *   A= Point3D Cartesian, x=0.000000, y=0.000000, z=0.000000;
     *   B= Point3D Cartesian, x=0.000000, y=0.000000, z=1.000000
     *  });
     *  Points:(
     *   Point3D Cartesian, x=0.000000, y=0.000000, z=0.000000
     *   Point3D Cartesian, x=0.000000, y=0.000000, z=1.000000
     *   Point3D Cartesian, x=0.000000, y=5.000000, z=0.000000)]
     *
     */
    ChType *repr = malloc(sizeof(ChType)*(thisFigure->edges->size+2*thisFigure->points->size)*60);
    strcpy(repr, "Figure:[\nEdges:(");
    for (int i=0; i<thisFigure->edges->size; i++){
        repr = strcat(repr, _repr_Edge3D(thisFigure->edges->data[i]));
        if(i!=thisFigure->edges->size-1){repr = strcat(repr, "\n  ");}
    }
    strcat(repr, "); \nPoints:(\n ");
    for (int i=0; i<thisFigure->points->size; i++){
        repr = strcat(repr, _repr_Point(thisFigure->points->data[i]));
        if(i!=thisFigure->points->size-1){repr = strcat(repr, "\n ");}
    }
    strcat(repr, ")]");
    return repr;
}

Edge3DArray *make_EdgeArray(IType size) {
    /** Returns a pointer to empty Edge3DArray with certain size.
    *
    * Preferably use this function instead of malloc or calloc, in order to get get right initialization of fields.
    *
    */
    Edge3DArray* newArray = malloc(sizeof(Edge3DArray));
    newArray->size = size;
    newArray->data = malloc(sizeof(Edge3D*)*size);
    return newArray;
}

Point3DArray *make_PointArray(IType size) {
    /** Returns a pointer to empty Point3DArray with certain size.
    *
    * Preferably use this function instead of malloc or calloc, in order to get get right initialization of fields.
    *
    */
    Point3DArray* newArray = malloc(sizeof(Point3DArray));
    newArray->size = size;
    newArray->data = malloc(sizeof(Point3D*)*size);
    return newArray;
}

void free_Figure(Figure3D *thisFigure) {
    /** Free allocated memory in thisFigure and thisFigure itself.
    *
    */
    free_Edge3DArray(thisFigure->edges);
    free_Point3DArray(thisFigure->points);
    free(thisFigure);
}

void free_Edge3DArray(Edge3DArray *thisArray) {
    /** Free allocated memory for each element in thisArray->data, also free data and thisArray itself.
     *
     */
    for (int i=0; i<thisArray->size;i++){free(thisArray->data[i]);}
    free(thisArray->data);
    free(thisArray);
}

void free_Point3DArray(Point3DArray *thisArray) {
    /** Free allocated memory for each element in thisArray->data, also free data and thisArray itself.
     *
     */
    for (int i=0; i<thisArray->size;i++){free(thisArray->data[i]);}
    free(thisArray->data);
    free(thisArray);
}
