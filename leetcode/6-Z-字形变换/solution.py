class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        cycle = 2 * numRows - 2
        answer = []
        for row in range(numRows):
            for index, char in enumerate(s):
                remainder = index % cycle
                if row == 0:
                    if remainder == 0:
                        answer.append(char)
                elif row == numRows - 1:
                    if remainder == row:
                        answer.append(char)
                elif remainder == row or remainder == cycle - row:
                    answer.append(char)

        return "".join(answer)
