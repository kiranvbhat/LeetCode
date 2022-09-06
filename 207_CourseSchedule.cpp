// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool cycleFound(vector<vector<int>>& courseReqs, int course, unordered_set<int>& visited) {
        if (visited.count(course) != 0) {
            return true;
        }
        if (courseReqs[course].empty()) {
            return false;
        }
        visited.insert(course);
        for (int prereq : courseReqs[course]) {
            if (cycleFound(courseReqs, prereq, visited)) {
                return true;
            }
        }
        visited.erase(course);
        // If we got past for loop without finding a cycle, we know that no prereqs of course lead to a cycle,
        // so we no longer need to explore course's prerequisites. We mark course as having no prereqs.
        courseReqs[course] = {};
        return false;
    }
    
    // Approach: Recursive DFS with memoization
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build up graph
        vector<vector<int>> courseReqs(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            courseReqs[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        // Look for cycles
        unordered_set<int> visited;
        for (int course = 0; course < numCourses; course++) {
            if (cycleFound(courseReqs, course, visited)) return false;
        }
        return true;
    }
};
