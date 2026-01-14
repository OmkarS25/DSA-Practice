class Solution {
public:
    typedef pair<int, int> ii;

    class SegmentTree{
        public:
            vector<ii> tree; // count - length

            SegmentTree(int n) {
                tree.resize(4 * n);
            }
           
            void update(int i, int left, int right, int uLeft, int uRight, int val, vector<int>& originX) {
                if (right < uLeft || left > uRight) {
                    return;
                }

                if (uLeft <= left && right <= uRight) {
                    tree[i].first += val;
                } else {
                    int mid = (left + right) / 2;
                    update(2 * i + 1, left, mid, uLeft, uRight, val, originX);
                    update(2 * i + 2, mid + 1, right, uLeft, uRight, val, originX);
                }
                
                if (tree[i].first > 0) {
                    tree[i].second = originX[right + 1] - originX[left];
                } else if (left == right) {
                    tree[i].second = 0;
                } else {
                    tree[i].second = tree[2 * i + 1].second + tree[2 * i + 2].second;
                }
            }

            int query() {
                return tree[0].second;
            }
    };

    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        
        vector<tuple<int, int, int, int>> events;
        vector<int> originX;
        int maxX = 0;
        for (int i = 0; i < n; ++i) {
            int x = squares[i][0];
            int y = squares[i][1];
            int l = squares[i][2];

            events.emplace_back(y, x, l, 1);
            events.emplace_back(y + l, x, l, -1);

            originX.push_back(x);
            originX.push_back(x + l);

            maxX = max(maxX, x + l);
        }
        
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            return get<0>(a) < get<0>(b);
        });
        sort(originX.begin(), originX.end());

        int maxCompressX = lower_bound(originX.begin(), originX.end(), maxX) - originX.begin();
        SegmentTree* segmentTree = new SegmentTree(maxCompressX);

        // Calculate totalArea
        double totalArea = 0;
        double prevY = 0;
        for (auto [y, x, l, type] : events) {
            double thisArea = segmentTree->query() * (y - prevY);
            
            int left = lower_bound(originX.begin(), originX.end(), x) - originX.begin();
            int right = lower_bound(originX.begin(), originX.end(), x + l) - originX.begin() - 1;
            segmentTree->update(0, 0, maxCompressX, left, right, type, originX);
            totalArea += thisArea;
            prevY = y;
        }

        // Find answer
        segmentTree = new SegmentTree(maxCompressX);
        double curArea = 0;
        double curWidth = 0;
        prevY = 0;
        for (auto [y, x, l, type] : events) {
            curWidth = segmentTree->query();
            double thisArea =  curWidth * (y - prevY);
            if (2 * (curArea + thisArea) >= totalArea) {
                return prevY + (totalArea - 2.0 * curArea) / (2.0 * curWidth);
            }

            int left = lower_bound(originX.begin(), originX.end(), x) - originX.begin();
            int right = lower_bound(originX.begin(), originX.end(), x + l) - originX.begin() - 1;
            segmentTree->update(0, 0, maxCompressX, left, right, type, originX);
            curArea += thisArea;
            prevY = y;
        }

        return 0;
    }
};



// class Solution {
// public:
//     double separateSquares(vector<vector<int>>& squares) {
//         struct Event {
//             int y;
//             int type; // +1 for START of square, -1 for END of square
//             int xStart;
//             int xEnd;

//             // Sort events primarily by Y coordinate
//             bool operator<(const Event& other) const {
//                 return y < other.y;
//             }
//         };

//         struct Strip {
//             int y;
//             int height;
//             double unionWidth;
//         };

//         vector<Event> sweepEvents;
//         for (const auto& sq : squares) {
//             int x = sq[0];
//             int y = sq[1];
//             int l = sq[2];
//             sweepEvents.push_back({y, 1, x, x + l});
//             sweepEvents.push_back({y + l, -1, x, x + l});
//         }

//         sort(sweepEvents.begin(), sweepEvents.end());

//         vector<pair<int, int>> activeIntervals;
//         vector<Strip> processedStrips;
//         double totalArea = 0;
//         int prevY = sweepEvents[0].y;

//         for (const auto& event : sweepEvents) {
//             // Process the strip formed between the previous event and current event
//             if (event.y > prevY) {
//                 double width = getUnionWidth(activeIntervals);
//                 int height = event.y - prevY;
                
//                 if (width > 0) {
//                     processedStrips.push_back({prevY, height, width});
//                     totalArea += (double)height * width;
//                 }
//             }

//             // Update active intervals based on event type
//             if (event.type == 1) {
//                 activeIntervals.push_back({event.xStart, event.xEnd});
//             } else {
//                 // Find and remove the interval. 
//                 // We iterate to find the specific interval to remove one instance.
//                 for (auto it = activeIntervals.begin(); it != activeIntervals.end(); ++it) {
//                     if (it->first == event.xStart && it->second == event.xEnd) {
//                         activeIntervals.erase(it);
//                         break;
//                     }
//                 }
//             }
//             prevY = event.y;
//         }

//         // Second Pass: Find the exact cut line
//         double targetArea = totalArea / 2.0;
//         double accumulatedArea = 0;

//         for (const auto& strip : processedStrips) {
//             double stripArea = strip.height * strip.unionWidth;

//             if (accumulatedArea + stripArea >= targetArea) {
//                 double areaNeeded = targetArea - accumulatedArea;
//                 return strip.y + (areaNeeded / strip.unionWidth);
//             }
//             accumulatedArea += stripArea;
//         }

//         return 0.0;
//     }

// private:
//     // Helper to calculate the length of the union of intervals
//     double getUnionWidth(vector<pair<int, int>> intervals) {
//         if (intervals.empty()) return 0;
        
//         sort(intervals.begin(), intervals.end());

//         double unionLength = 0;
//         double currentEnd = -1e18; // Negative infinity

//         for (const auto& interval : intervals) {
//             double start = interval.first;
//             double end = interval.second;

//             if (start >= currentEnd) {
//                 // No overlap with previous, add full length
//                 unionLength += (end - start);
//                 currentEnd = end;
//             } else if (end > currentEnd) {
//                 // Partial overlap, extend the current end
//                 unionLength += (end - currentEnd);
//                 currentEnd = end;
//             }
//         }
//         return unionLength;
//     }
// };