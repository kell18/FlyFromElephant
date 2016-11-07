#include <deque>
#include "AdjacencyMatrix.h"


namespace ffe {

    AdjacencyMatrix::AdjacencyMatrix(const std::vector<std::vector<bool> >& matrix) : matrix(matrix) {
    }

    std::vector<size_t> AdjacencyMatrix::findPath(size_t fromId, size_t toId) const {
        if (fromId == toId) return  { fromId };
        else {
            auto pathLayers = this->findPathLayers(fromId, toId);
            if (pathLayers.size() == 0) return {};
            std::vector<size_t> finalPath(pathLayers.size());
            size_t lastId = toId;
            for (size_t outI = pathLayers.size()-1; outI > 0; --outI) {    // for each layer from end-1 (toId) find ...
                finalPath[outI] = lastId;                                  // backward path to source node (fromId)
                auto& layer = pathLayers[outI-1];
                for (size_t layerI = 0; layerI < layer.size(); ++layerI) {
                    if (matrix[layer[layerI]][lastId]) {
                        lastId = layer[layerI];
                        break;
                    }
                }
            }
            finalPath[0] = fromId;
            return finalPath;
        }
    }

    std::vector<std::vector<size_t> > AdjacencyMatrix::findPathLayers(size_t fromId, size_t toId) const {
        std::vector<std::vector<size_t> > pathLayers;       // Layers of indexes leading to toId if possible
        std::vector<size_t> currPathLayer;                  // Currently treated layer
        std::deque<size_t> front { fromId };                // BFS frontier
        unsigned currLayerItemsAmt = 1;                     // Counters to determine layers bounds
        unsigned nextLayerItemsAmt = 0;
        while (front.size() > 0) {
            size_t neighbourInd = front.front();
            front.pop_front();
            currLayerItemsAmt -= 1;
            currPathLayer.push_back(neighbourInd);
            auto newNeighbours = getNeighboursFor(neighbourInd);

            // Iterating over non seen, connected to current neighbourInd indexes
            for (size_t ind = 0; ind < newNeighbours.size(); ++ind) if (newNeighbours[ind]) {
                bool notSeenOnPathLayers = true;
                for (auto& layer : pathLayers) {
                    if (std::find(layer.begin(), layer.end(), ind) != layer.end()) {
                        notSeenOnPathLayers = false;
                        break;
                    }
                }
                bool isNotSeenBefore = notSeenOnPathLayers && std::find(front.begin(), front.end(), ind) == front.end() &&
                        std::find(currPathLayer.begin(), currPathLayer.end(), ind) == currPathLayer.end();
                if (isNotSeenBefore) {
                    if (ind == toId) {                              // If path is found:
                        pathLayers.push_back(currPathLayer);        // Add previous and current (last) index
                        pathLayers.push_back({ ind });              // Add target index, it always last.
                        return pathLayers;
                    } else {
                        front.push_back(ind);
                        nextLayerItemsAmt += 1;
                    }
                }
            }
            if (currLayerItemsAmt == 0) {                           // If current layer is iterated:
                pathLayers.push_back(currPathLayer);                // Append layer
                currPathLayer = {};
                std::swap(currLayerItemsAmt, nextLayerItemsAmt);    // Reset counters
            }

        }
        return { };
    }

    const std::vector<bool>& AdjacencyMatrix::getNeighboursFor(size_t index) const {
        return matrix[index];
    }
}