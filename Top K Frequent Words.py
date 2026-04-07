class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        d = defaultdict(int)
        for word in words:
            d[word] += 1
        
        heap = []
        for word, count in d.items():
            heapq.heappush(heap, (-count, word))
            
        return [heapq.heappop(heap)[1] for _ in range(k)]
