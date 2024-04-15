class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        for c in s:
            if c != ']':
                stack.append(c)
            else:
                substr = ""
                while stack[-1] != '[':
                    substr = stack.pop() + substr
                stack.pop()

                K = ""
                while stack and stack[-1].isdigit():
                    K = stack.pop() + K
                stack.append(int(K) * substr)
        return "".join(stack)
             

        
