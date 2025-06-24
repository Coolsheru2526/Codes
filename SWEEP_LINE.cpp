#include <bits/stdc++.h>
using namespace std;

class SweepLine {
private:
    map<int, int> eventCount;
    map<int, int> overlapAtPoint;
    bool processed = false;

    void process() {
        overlapAtPoint.clear();
        int currOverlap = 0;
        for (auto &[point, delta] : eventCount) {
            currOverlap += delta;
            overlapAtPoint[point] = currOverlap;
        }
        processed = true;
    }

public:
    // Add interval [l, r] inclusive
    void addInterval(int l, int r) {
        eventCount[l] += 1;
        eventCount[r + 1] -= 1;
        processed = false;
    }

    // Remove interval [l, r] inclusive
    void removeInterval(int l, int r) {
        eventCount[l] -= 1;
        eventCount[r + 1] += 1;
        processed = false;
    }

    // Get overlap at point x using upper_bound
    int getOverlapAt(int x) {
        if (!processed) process();
        auto it = overlapAtPoint.upper_bound(x);
        if (it == overlapAtPoint.begin()) return 0;
        --it;
        return it->second;
    }

    // Get max overlap among all intervals
    int getMaxOverlap() {
        if (!processed) process();
        int maxOverlap = 0;
        for (auto &[point, count] : overlapAtPoint) {
            maxOverlap = max(maxOverlap, count);
        }
        return maxOverlap;
    }

    // Get all key points with overlaps (for plotting or debug)
    vector<pair<int, int>> getAllOverlapPoints() {
        if (!processed) process();
        vector<pair<int, int>> result;
        for (auto &[point, count] : overlapAtPoint) {
            result.emplace_back(point, count);
        }
        return result;
    }

    // Get total union length covered by intervals
    long long getUnionLength() {
        if (!processed) process();
        long long unionLength = 0;
        int prev = -1;
        int curr = 0;
        for (auto &[point, count] : overlapAtPoint) {
            if (curr > 0 && prev != -1) {
                unionLength += (point - prev);
            }
            curr = count;
            prev = point;
        }
        return unionLength;
    }

    // Get merged intervals (interval union)
    vector<pair<int, int>> getMergedIntervals() {
        if (!processed) process();
        vector<pair<int, int>> result;
        int start = -1;
        int curr = 0;
        for (auto &[point, count] : overlapAtPoint) {
            if (curr == 0 && count > 0) {
                start = point;
            } else if (curr > 0 && count == 0) {
                result.emplace_back(start, point - 1); // inclusive
            }
            curr = count;
        }
        return result;
    }

    // Get all gaps between intervals
    vector<pair<int, int>> getGaps() {
        if (!processed) process();
        vector<pair<int, int>> merged = getMergedIntervals();
        vector<pair<int, int>> gaps;
        for (size_t i = 1; i < merged.size(); ++i) {
            int prevEnd = merged[i - 1].second;
            int nextStart = merged[i].first;
            if (prevEnd + 1 <= nextStart - 1) {
                gaps.emplace_back(prevEnd + 1, nextStart - 1);
            }
        }
        return gaps;
    }
};

int main() {
    SweepLine sw;
    
    // Add sample intervals
    sw.addInterval(1, 5);
    sw.addInterval(2, 6);
    sw.addInterval(4, 8);
    sw.addInterval(10, 15);
    sw.addInterval(20, 25);

    // Test overlap at different points
    cout << "Overlap at point 3: " << sw.getOverlapAt(3) << endl;
    cout << "Overlap at point 9: " << sw.getOverlapAt(9) << endl;
    cout << "Max Overlap: " << sw.getMaxOverlap() << endl;

    // Show all overlap changes
    cout << "\nSweep Line Events:\n";
    for (auto &[pt, cnt] : sw.getAllOverlapPoints()) {
        cout << pt << " -> " << cnt << "\n";
    }

    // Get union length
    cout << "\nTotal union length: " << sw.getUnionLength() << endl;

    // Get merged intervals
    cout << "\nMerged Intervals (Union Form):\n";
    for (auto &[l, r] : sw.getMergedIntervals()) {
        cout << "[" << l << ", " << r << "]\n";
    }

    // Get gaps
    cout << "\nGaps between intervals:\n";
    for (auto &[l, r] : sw.getGaps()) {
        cout << "[" << l << ", " << r << "]\n";
    }

    // Remove an interval and test again
    sw.removeInterval(2, 6);
    cout << "\nAfter removing [2,6] -> Max Overlap: " << sw.getMaxOverlap() << endl;

    return 0;
}
