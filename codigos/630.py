import heapq
class Solution:

    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x: x[1])
        max_heap = []
        total = 0

        for d, end in courses:
            total += d
            heapq.heappush(max_heap, -d)
            if total > end:
                total += heapq.heappop(max_heap)  # remove maior duração (negativo)

        return len(max_heap)
