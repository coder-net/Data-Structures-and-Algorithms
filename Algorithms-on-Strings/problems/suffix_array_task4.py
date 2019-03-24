def main():
    s = input().rstrip()
    matrix = []
    for i in range(len(s)):
        matrix.append(s[i:])
    matrix.sort()
    suffix_array = []
    for ss in matrix:
        suffix_array.append(len(s) - len(ss))
    print(*suffix_array)


if __name__ == '__main__':
    main()
