#pragma once

#include <fstream>
#include <vector>
#include <algorithm>

namespace ffe {
    /**
     * @brief  Adjacency matrix, e.g. undirected graph. Row-ordered, indexing from zero.
     */
    class AdjacencyMatrix {
    public:
        AdjacencyMatrix(const std::vector<std::vector<bool> >& matrix);

        /**
         * @brief Find a first appropriate path fromId toId.
         */
        std::vector<size_t>                 findPath(size_t fromId, size_t toId) const;

    private:
        std::vector<std::vector<bool> > matrix;

        /**
         * @brief Breadth-first search indexes layers fromId toId path.
         */
        std::vector<std::vector<size_t> >   findPathLayers(size_t fromId, size_t toId) const;
        const std::vector<bool>&            getNeighboursFor(size_t index) const;
    };

}
