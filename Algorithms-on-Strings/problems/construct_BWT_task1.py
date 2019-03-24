def main():
    s = input().rstrip()
    n = len(s)
    matrix = []
    for i in range(n):
        matrix.append(''.join((s[i:], s[:i])))
    matrix = sorted(matrix)
    bwt = ""
    for i in range(n):
        bwt = ''.join((bwt, matrix[i][-1]))
    print(bwt)


if __name__ == '__main__':
    main()

