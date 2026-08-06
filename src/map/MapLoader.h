#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <string>

#include "../graph/Graph.h"

class MapLoader
{
public:
    MapLoader();

    bool loadVertices(Graph& graph,
                      const std::string& filename);

    bool loadEdges(Graph& graph,
                   const std::string& filename);
};

#endif