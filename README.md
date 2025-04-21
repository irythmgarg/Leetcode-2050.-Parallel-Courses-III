# Leetcode-2050.-Parallel-Courses-III
⏳ Minimum Time to Complete All Courses
This solution addresses the problem of computing the minimum total time required to complete n courses, given their durations and prerequisite relationships.

🧩 Problem Overview
You are given:

n courses labeled 1 to n.

A list of relations where each relation [x, y] means you must take course x before course y.

An array time[i] where time[i] is the duration of course i+1.

Your goal is to return the minimum number of months needed to complete all the courses, assuming multiple courses can be taken simultaneously only if their prerequisites are met.

🧠 Approach: Topological Sort + Dynamic Programming
Graph Construction: Build a dependency graph.

Topological Sort: Traverse in prerequisite order.

Dynamic Programming: Keep track of the longest time path to each course using a maxans table.

💡 Intuition
Each course can start only after all its prerequisites are completed.

For each course, we track the maximum total time required to reach that course.

The answer is the maximum value across all these paths.

⏱️ Time and Space Complexity

Operation	Complexity
Time Complexity	O(n + m)
Space Complexity	O(n + m)
Where:

n is the number of courses.

m is the number of relations.

📦 Example
cpp

Input:
n = 3
relations = [[1,3],[2,3]]
time = [3,2,5]

Output:
8

Explanation:
- Take courses 1 and 2 in parallel → 3 and 2 months respectively
- Then take course 3 → after max(3,2) = 3 months → 3 + 5 = 8 months
🛠️ When to Use This
Task scheduling with prerequisites

Dependency resolution problems

Project management simulations

